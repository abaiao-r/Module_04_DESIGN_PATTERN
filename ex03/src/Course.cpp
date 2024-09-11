/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Course.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:14:01 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/11 09:47:30 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Course.hpp"

Course::Course(const std::string &courseName) : _courseName(courseName), _responsableProfessor(nullptr), _students(), _numberOfClassToGraduate(0), _maximumNumberOfStudent(0)
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
    if(this->_students.size() < (size_t)this->_maximumNumberOfStudent)
    {
        this->_students.push_back(student);
    }
    else
    {
        std::cout << "The course is full" << std::endl;
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

