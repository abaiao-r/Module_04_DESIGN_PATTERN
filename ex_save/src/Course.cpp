/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Course.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:14:01 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/13 18:37:12 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/one.hpp"

Course::Course(const std::string &courseName) : _courseName(courseName), _responsableProfessor(nullptr), _students(), _numberOfClassToGraduate(2), _maximumNumberOfStudent(0), _mediator(nullptr)
{
    std::cout << "Course " << courseName << " created" << std::endl;
}

Course::~Course()
{
}

void Course::assignProfessor(Professor* professor)
{
    this->_responsableProfessor = professor;
}

void Course::subscribeStudent(Student* student)
{
    this->_students.push_back(student);
    this->_attendanceTimes[student] = 0;
}

void Course::unsubscribeStudent(Student* student)
{
    for (auto it = this->_students.begin(); it != this->_students.end(); it++)
    {
        if (*it == student)
        {
            this->_students.erase(it);
            break;
        }
    }
}

void Course::setNumberOfClassToGraduate(int numberOfClassToGraduate)
{
    this->_numberOfClassToGraduate = numberOfClassToGraduate;
}

void Course::setMaximumNumberOfStudent(int maximumNumberOfStudent)
{
    this->_maximumNumberOfStudent = maximumNumberOfStudent;
}

void Course::setMediator(Headmaster* mediator)
{
    this->_mediator = mediator;
}

std::string Course::getCourseName() const
{
    return (this->_courseName);
}

Professor* Course::getResponsableProfessor() const
{
    return (this->_responsableProfessor);
}

std::vector<Student*> Course::getStudents() const
{
    return (this->_students);
}

int Course::getNumberOfClassToGraduate() const
{
    return (this->_numberOfClassToGraduate);
}

int Course::getMaximumNumberOfStudent() const
{
    return (this->_maximumNumberOfStudent);
}

Student* Course::findStudent(const std::string &studentName) const
{
    for (auto it = this->_students.begin(); it != this->_students.end(); it++)
    {
        if ((*it)->name() == studentName)
        {
            return (*it);
        }
    }
    return nullptr;
}

bool Course::canGraduate(Student *student)
{
    std::cout << "Attendance times: " << this->_attendanceTimes[student] << " Number of class to graduate: " << this->_numberOfClassToGraduate << std::endl;
    if (this->_attendanceTimes[student] >= this->_numberOfClassToGraduate)
    {
        return true;
    }
    return false;
}

void Course::setAttendanceTimes(Student *student)
{
    this->_attendanceTimes[student]++;
}