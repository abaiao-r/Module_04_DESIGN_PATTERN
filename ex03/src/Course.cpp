/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Course.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:14:01 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 18:48:34 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Course.hpp"

Course::Course(const std::string &courseName) : _courseName(courseName), _responsableProfessor(nullptr), _students(), _numberOfClassToGraduate(0), _maximumNumberOfStudent(0)
{
}

Course::Course(const Course &src) : _courseName(src._courseName), _responsableProfessor(src._responsableProfessor), _students(src._students), _numberOfClassToGraduate(src._numberOfClassToGraduate), _maximumNumberOfStudent(src._maximumNumberOfStudent)
{
}

Course &Course::operator=(const Course &src)
{
    if (this != &src)
    {
        this->_courseName = src._courseName;
        this->_responsableProfessor = src._responsableProfessor;
        this->_students = src._students;
        this->_numberOfClassToGraduate = src._numberOfClassToGraduate;
        this->_maximumNumberOfStudent = src._maximumNumberOfStudent;
    }
    return (*this);
}

Course::~Course()
{
}

void Course::assignProfessor(const std::shared_ptr<Professor> professor)
{
    this->_responsableProfessor = professor;
}

void Course::subscribeStudent(const std::shared_ptr<Student> student)
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
