/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:58:29 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/07 17:14:02 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Professor.hpp"

Professor::Professor(const std::string &staffName) : Staff(staffName), _currentCourse(nullptr)
{
}

Professor::Professor(const Professor &src) : Staff(src), _currentCourse(src._currentCourse)
{
}

Professor &Professor::operator=(const Professor &src)
{
    if (this != &src)
    {
        Staff::operator=(src);
        this->_currentCourse = src._currentCourse;
    }
    return (*this);
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
    
}

void Professor::closeCourse()
{
    // Implement the closeCourse method here
    this->_currentCourse = nullptr;
}

