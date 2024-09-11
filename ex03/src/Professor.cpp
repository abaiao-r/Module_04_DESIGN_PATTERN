/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:58:29 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/11 09:17:41 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Professor.hpp"

Professor::Professor(const std::string &staffName) : Staff(staffName), _currentCourse(nullptr), _mediator(nullptr)
{
}

Professor::~Professor()
{
}

void Professor::assignCourse(Course* course)
{
    this->_currentCourse = course;
}

void Professor::doClass()
{
    // Implement the doClass method here
    if (this->_currentCourse)
    {
       std::cout << "Professor gave class" << std::endl;
    }
    else
    {
        std::cout << "No course assigned" << std::endl;
    }
    
}

void Professor::closeCourse()
{
    // Implement the closeCourse method here
    this->_currentCourse = nullptr;
}

void Professor::requestCourseCreation(const std::string &courseName)
{
    // Implement the requestCourseCreation method here
    if (this->_mediator)
    {
        std::cout << "Professor requests course creation" << std::endl;
        //_mediator->notify("Professor", "CreateCourse");
        _mediator->notify(*this, "CreateCourse", courseName);
    }
}

void Professor::setMediator(Headmaster* mediator)
{
    // Implement the setMediator method here
    this->_mediator = mediator;
}

void Professor::requestGraduation(const std::string &studentName)
{
    (void) studentName;
    // Implement the requestGraduation method here
    if (this->_mediator)
    {
        std::cout << "Professor requests graduation" << std::endl;
        _mediator->notify("Professor", "CourseFinished");
    }
}

void Professor::requestMoreClassRoom(const std::string &courseName)
{
    (void) courseName;
    // Implement the requestMoreClassRoom method here
    if (this->_mediator)
    {
        std::cout << "Professor requests more classroom" << std::endl;
        _mediator->notify("Professor", "NeedsMoreClasses");
    }
}



