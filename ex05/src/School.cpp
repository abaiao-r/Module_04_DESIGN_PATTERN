/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   School.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:12:36 by abaiao-r          #+#    #+#             */
/*   Updated: 2024/09/13 22:12:51 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/School.hpp"

School::School()
{
    _secretary.setMediator(&_headmaster);
}

School::~School()
{
    // Cleanup resources if needed
}

void School::runDayRoutine()
{
    // 1. Launch classes
    launchClasses();
    
    // 2. Recreation time
    requestRingBell();

    // 3. Launch classes again
    launchClasses();

    // 4. Lunch break
    requestRingBell();

    // 5. Launch classes again
    launchClasses();

    // 6. Recreation time
    requestRingBell();

    // 7. Launch classes again
    launchClasses();
}

void School::launchClasses()
{
    // Notify headmaster to start classes
    _headmaster.goTeachCourse(nullptr); // Notify professors
    _headmaster.makeStudentsEnterRoom(nullptr); // Notify students
}

void School::requestRingBell()
{
    _headmaster.ringBell();
}

void School::recruteProfessor(Professor* professor)
{
    _professors.push_back(professor);
    _headmaster.addProfessor(professor);
    professor->setMediator(&_headmaster);
}

void School::recruteStudent(Student* student)
{
    _students.push_back(student);
    _headmaster.addStudent(student);
    student->setMediator(&_headmaster);
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