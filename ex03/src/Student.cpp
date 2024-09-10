/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:49:19 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/09 19:36:20 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Student.hpp"


Student::Student(const std::string &studentName) : Person(studentName), _subscribedCourse(), _mediator(nullptr)
{
}

Student::~Student()
{
}

void Student::attendClass(Classroom* classroom)
{
    // Implement the attendClass method here
    // classroom->enter(this);
    (void) classroom;
    std::cout << "Student attended class" << std::endl;
}

void Student::exitClass()
{
    // Implement the exitClass method here
    std::cout << "Student exited class" << std::endl;
}

void Student::graduate(Course* course)
{
    // Implement the graduate method here
    (void) course;
    std::cout << "Student graduated" << std::endl;
}

void Student::requestToSubscribeToCourse(Course* course)
{
    (void) course;
    // Implement the requestToSubscribeToCourse method here
    if (_mediator)
    {
        std::cout << "Student requests to subscribe to course" << std::endl;
        _mediator->notify("Student", "RequestCourseSubscription");
    }
}

void Student::setMediator(Headmaster* mediator)
{
    // Implement the setMediator method here
    _mediator = mediator;
}


