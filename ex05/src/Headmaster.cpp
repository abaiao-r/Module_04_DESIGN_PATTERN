/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:39:58 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/13 20:15:40 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/one.hpp"

Headmaster::Headmaster() : Staff("Headmaster")
{
}

Headmaster::~Headmaster()
{
    // delete all forms
    for (std::vector<Form*>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it)
    {
        delete *it;
    }
    // delete all rooms
    for (std::vector<Room*>::iterator it = _rooms.begin(); it != _rooms.end(); ++it)
    {
        delete *it;
    }
    // delete all courses
    for (std::vector<Course*>::iterator it = _courses.begin(); it != _courses.end(); ++it)
    {
        delete *it;
    }
}

void Headmaster::receiveForm(Form* p_form) 
{
    //print the form type
    std::cout << "Headmaster received form of type: " << p_form->getFormType() << std::endl;
    _formToValidate.push_back(p_form);
}

void Headmaster::signForm(Form* p_form)
{
    // check if the p_form is in the vector of forms
    for (std::vector<Form*>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it)
    {
        if ((*it)->getFormType() == p_form->getFormType())
        {
            (*it)->signForm();
            std::cout << "Headmaster signs form" << std::endl;
            return;
        }
    }
    std::cout << "Form not found in the list. Cannot sign." << std::endl;
}

void Headmaster::executeForm(Form* p_form)
{
    // loop through the vector of forms
    for (std::vector<Form*>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it)
    {
        if ((*it)->getFormType() == p_form->getFormType())
        {
            if ((*it)->isSigned())
            {
                p_form->execute();
                _formToValidate.erase(it);
                return;
            }
            else
            {
                std::cout << "Form not signed yet. Cannot execute." << std::endl;
                return;
            }
        }
    }
    std::cout << "Form not found in the list. Cannot execute." << std::endl;
}

void Headmaster::addProfessor(Professor *professor)
{
    _professors.push_back(professor);
}

void Headmaster::setSecretary(Secretary *secretary)
{
    _secretary = secretary;
}

void Headmaster::addStudent(Student *student)
{
    _students.push_back(student);
}

void Headmaster::addCourse(Course *course)
{
    _courses.push_back(course);
}

void Headmaster::addRoom(Room *room)
{
    _rooms.push_back(room);
}

std::vector<Form*> Headmaster::getFormToValidate() const
{
    return _formToValidate;
}

std::vector<Professor*> Headmaster::getProfessors() const
{
    return _professors;
}

Secretary* Headmaster::getSecretary() const
{
    return _secretary;
}

std::vector<Student*> Headmaster::getStudents() const
{
    return _students;
}

std::vector<Course*> Headmaster::getCourses() const
{
    return _courses;
}

std::vector<Room*> Headmaster::getRooms() const
{
    return _rooms;
}

Course* Headmaster::findCourse(const std::string &courseName)
{
    for (std::vector<Course*>::iterator it = _courses.begin(); it != _courses.end(); ++it)
    {
        if ((*it)->getCourseName() == courseName)
        {
            return *it;
        }
    }
    return nullptr;
}

void Headmaster::goTeachCourse(Professor* p_professor)
{
    p_professor->doClass();
}

void Headmaster::goAttendClass(Student* p_student, Classroom* p_classroom)
{
    p_classroom->enter(p_student);
}

void Headmaster::makeStudentsEnterRoom(Classroom* p_classroom)
{
    std::vector<Student*> students = getStudents();
    if (students.empty())
    {
        std::cout << "No students to attend class." << std::endl;
        return;
    }
    for (std::vector<Student*>::iterator it = students.begin(); it != students.end(); ++it)
    {
        goAttendClass(*it, p_classroom);
    }
}

/* void Headmaster::notify(const std::string &sender, const std::string &event)
{
    if (sender == "Professor" && event == "CourseFinished")
    {
        std::cout << "Headmaster: Notifying Secretary to create a graduation form.\n";
        _secretary->createForm(FormType::CourseFinished);
    }
    else if (sender == "Professor" && event == "NeedsMoreClasses")
    {
        std::cout << "Headmaster: Notifying Secretary to create a form for more classes.\n";
        _secretary->createForm(FormType::NeedMoreClassRoom);
    }
    else if (sender == "Student" && event == "RequestCourseSubscription")
    {
        std::cout << "Headmaster: Notifying Secretary to create a subscription form.\n";
        _secretary->createForm(FormType::SubscriptionToCourse);
    }
    else if (sender == "Professor" && event == "CreateCourse")
    {
        std::cout << "Headmaster: Notifying Secretary to create a course creation form.\n";
        _secretary->createForm(FormType::NeedCourseCreation);
    }
}
 */
/* same as above but with an extra parameter */
void Headmaster::notify(Person &sender, const std::string &event, const std::string &target)
{
    // what type of Person is the sender
    if (Professor *professor = dynamic_cast<Professor*>(&sender))
    {
        if (event == "CreateCourse")
        {
            std::cout << "Headmaster: Notifying Secretary to create a course creation form.\n";
            Form *type = _secretary->createForm(FormType::NeedCourseCreation);
            if (type)
            {
                signForm(type);
                executeForm(type);
                // dealocate form
                delete type;
                Course *course = new Course(target);
                course->setMediator(this);
                course->assignProfessor(professor);
                professor->assignCourse(course);
                addCourse(course);
            }
        }
        else if (event == "CourseFinished")
        {
            std::cout << "Headmaster: Notifying Secretary to create a graduation form.\n";
            Form *type = _secretary->createForm(FormType::CourseFinished);
            if (type)
            {
                // find the course that professor is responsible for
                Course *course = professor->getCurrentCourse();
                if (course)
                {
                    // find if target (student) is subscribed to the course
                    Student *student = course->findStudent(target);
                    if (student)
                    {
                        // cam he graduate?
                        bool canGraduate = course->canGraduate(student);
                        if (!canGraduate)
                        {
                            std::cout << "Student cannot graduate. Not enough classes attended." << std::endl;
                            return;
                        }
                        signForm(type);
                        executeForm(type);
                        // dealocate form
                        delete type;
                        student->graduate(course);
                        student->removeCourse(course->getCourseName());
                        course->unsubscribeStudent(student);
                    }
                    else
                    {
                        std::cout << "Student not found. Cannot graduate." << std::endl;
                    }
                }
                else 
                {
                    std::cout << "Course not found. Cannot graduate students." << std::endl;
                }
            }
        }
        else if (event == "NeedsMoreClasses")
        {
            std::cout << "Headmaster: Notifying Secretary to create a form for more classes.\n";
            Form *type = _secretary->createForm(FormType::NeedMoreClassRoom);
            if (type)
            {
                signForm(type);
                executeForm(type);
                // dealocate form
                delete type;
                // create classroom
                Room *room = new Classroom();
                addRoom(room);
                std::cout << "Room created id: " << room->getId() << std::endl;
            }
        }
    }
    else if (Student *student = dynamic_cast<Student*>(&sender))
    {
        if (event == "RequestCourseSubscription")
        {
            std::cout << "Headmaster: Notifying Secretary to create a subscription form.\n";
            Form *type = _secretary->createForm(FormType::SubscriptionToCourse);
            if (type)
            {
                Course *course = findCourse(target);
                if (course)
                {
                    signForm(type);
                    executeForm(type);
                    // dealocate form
                    delete type;
                    course->subscribeStudent(student);
                    student->setSubscribedCourse(course);
                    std::cout << "Student " << student->name() << " subscribed to course " << target << std::endl;
                }
                else
                {
                    std::cout << "Course not found. Cannot subscribe student." << std::endl;
                }
            }
        }
    }
}


void Headmaster::addBellObserver(IBellObserver* observer)
{
    _bellObservers.push_back(observer);
}

void Headmaster::removeBellObserver(IBellObserver* observer)
{
    _bellObservers.erase(std::remove(_bellObservers.begin(), _bellObservers.end(), observer), _bellObservers.end());
}

void Headmaster::ringBell()
{
    std::cout << "Headmaster rings the bell" << std::endl;
    for (IBellObserver* observer : _bellObservers)
    {
        observer->onBellRing(Event::RingBell);
    }
}




