/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:39:58 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/10 22:22:58 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Headmaster.hpp"

Headmaster::Headmaster() : Staff("Headmaster"), _formToValidate(), _professors(), _secretary(nullptr), _students(), 
{
}

Headmaster::~Headmaster()
{
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
                // remove the form from the vector
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

void Headmaster::notify(const std::string &sender, const std::string &event)
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

/* same as above but with an extra parameter */
void Headmaster::notify(Person &sender, const std::string &event, const std::string &target)
{
    // what type of Person is the sender
    if (Professor *professor = dynamic_cast<Professor*>(&sender))
    {
        if (event == "CreateCourse")
        {
            std::cout << "Headmaster: Notifying Secretary to create a course creation form.\n";
            Form *type = _secretary->createForm(FormType::NeedCourseCreation, target);
            if (type)
            {
                signForm(type);
                executeForm(type);
                Course *course = new Course(target);
                course->setMediator(this);
                course->assignProfessor(professor);
                addCourse(course);
            }
        }
        else if (event == "CourseFinished")
        {
            std::cout << "Headmaster: Notifying Secretary to create a graduation form.\n";
            _secretary->createForm(FormType::CourseFinished, target);
        }
        else if (event == "NeedsMoreClasses")
        {
            std::cout << "Headmaster: Notifying Secretary to create a form for more classes.\n";
            _secretary->createForm(FormType::NeedMoreClassRoom, target);
        }
    }
    else if (Student *student = dynamic_cast<Student*>(&sender))
    {
        if (event == "RequestCourseSubscription")
        {
            std::cout << "Headmaster: Notifying Secretary to create a subscription form.\n";
            _secretary->createForm(FormType::SubscriptionToCourse, target);
        }
    }
}





