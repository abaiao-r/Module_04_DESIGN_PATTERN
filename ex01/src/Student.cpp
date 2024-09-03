/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:49:19 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 18:56:46 by andrefranci      ###   ########.fr       */
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

void Student::attendClass(const std::shared_ptr<Classroom> classroom)
{
    // Implement the attendClass method here
    //classroom->enter(std::make_shared<Person>(*this));
    (void) classroom;
}

void Student::exitClass()
{
    // Implement the exitClass method here
}

void Student::graduate(const std::shared_ptr<Course> course)
{
    // Implement the graduate method here
    (void) course;
}
