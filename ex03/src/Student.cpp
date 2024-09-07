/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:49:19 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/07 17:18:35 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Student.hpp"

Student::Student(const std::string &studentName) : Person(studentName), _subscribedCourse()
{
}

Student::Student(const Student &src) : Person(src), _subscribedCourse(src._subscribedCourse)
{
}

Student &Student::operator=(const Student &src)
{
    if (this != &src)
    {
        Person::operator=(src);
        this->_subscribedCourse = src._subscribedCourse;
    }
    return (*this);
}

Student::~Student()
{
}

void Student::attendClass(Classroom* classroom)
{
    // Implement the attendClass method here
    // classroom->enter(this);
    (void) classroom;
}

void Student::exitClass()
{
    // Implement the exitClass method here
}

void Student::graduate(Course* course)
{
    // Implement the graduate method here
    (void) course;
}
