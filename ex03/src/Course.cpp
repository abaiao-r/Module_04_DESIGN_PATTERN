/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Course.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:14:01 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/10 21:09:24 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Course.hpp"

Course::Course(const std::string &courseName) : _courseName(courseName), _responsableProfessor(nullptr), _students(), _numberOfClassToGraduate(0), _maximumNumberOfStudent(0)
{
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
