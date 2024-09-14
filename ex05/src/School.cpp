/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   School.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:12:36 by abaiao-r          #+#    #+#             */
/*   Updated: 2024/09/14 16:22:06 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/School.hpp"

School::School() : _headmaster(Headmaster()), _secretary(Secretary("Secretary"))
{
    // Initialize resources if needed
    _headmaster.setSecretary(&_secretary);
    _secretary.setMediator(&_headmaster);
}

School::~School()
{
    // Cleanup resources if needed
    for (Professor* professor : _professors)
    {
        delete professor;
    }
    for (Student* student : _students)
    {
        delete student;
    }
}

void School::runDayRoutine()
{
    std::cout << "--------------------------------" << std::endl;
    std::cout << "School day routine started" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "1st period: Launch classes" << std::endl;
    
    // 1. Launch classes
    launchClasses();
    
    std::cout << "--------------------------------" << std::endl;
    std::cout << "2nd period: Recreation time" << std::endl;
    // 2. Recreation time
    requestRingBell();

std::cout << "--------------------------------" << std::endl;
    std::cout << "3rd period: Launch classes" << std::endl;
    // 3. Launch classes again
    launchClasses();


    std::cout << "--------------------------------" << std::endl;
    std::cout << "4th period: Lunch break" << std::endl;
    // 4. Lunch break
    requestRingBell();

    std::cout << "--------------------------------" << std::endl;
    std::cout << "5th period: Launch classes" << std::endl;
    // 5. Launch classes again
    launchClasses();

    std::cout << "--------------------------------" << std::endl;
    std::cout << "6th period: Recreation time" << std::endl;
    // 6. Recreation time
    requestRingBell();

    std::cout << "--------------------------------" << std::endl;
    // 7. Launch classes again
    launchClasses();
    std::cout << "--------------------------------" << std::endl;
}

void School::launchClasses()
{
    // first garantee that all professors have a course
    for (Professor* professor : _professors)
    {
        if (!professor->getCurrentCourse())
        {
            static int courseCount = 1;
            std::string courseName = "Course" + std::to_string(courseCount++);
            professor->requestCourseCreation(courseName);
        }
    }
    
    // check if all students are subscribed to a course
    for (Student* student : _students)
    {
        student->lookForCourseToSubscribe();
    }
    
    // loop throuh all professors and make them start their classes
    for (Professor* professor : _professors)
    {
        _headmaster.goTeachCourse(professor);
    }
}

void School::requestRingBell()
{
    _headmaster.ringBell();
}

void School::recruteProfessor()
{
    static int professorCount = 1;
    std::string professorName = "Professor" + std::to_string(professorCount++);
    Professor* professor = new Professor(professorName);
    _professors.push_back(professor);
    _headmaster.addProfessor(professor);
    professor->setMediator(&_headmaster);
    //add professor as bell observer
    _headmaster.addBellObserver(professor);
}

void School::recruteStudent()
{
    static int studentCount = 1;
    std::string studentName = "Student" + std::to_string(studentCount++);
    Student* student = new Student(studentName);
    _students.push_back(student);
    _headmaster.addStudent(student);
    student->setMediator(&_headmaster);
    //add student as bell observer
    _headmaster.addBellObserver(student);
}

Course* School::getCourse(const std::string &courseName)
{
    return _headmaster.findCourse(courseName);
}

std::vector<Student*> School::getStudents() const
{
    return _students;
}

std::vector<Professor*> School::getProfessors() const
{
    return _professors;
}

Headmaster& School::getHeadmaster()
{
    return _headmaster;
}

Secretary& School::getSecretary()
{
    return _secretary;
}

void School::graduationCeremony()
{
    for (Student* student : _students)
    {
        for (Course* course : student->getSubscribedCourse())
        {
            if (course->canGraduate(student))
            {
                student->graduate(course);
            }
        }
    }
}