/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classroom.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:45:01 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 18:45:44 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Classroom.hpp"

Classroom::Classroom() : Room(), _currentRoom(nullptr)
{
}

Classroom::Classroom(const Classroom &src) : Room(src), _currentRoom(src._currentRoom)
{
}

Classroom &Classroom::operator=(const Classroom &src)
{
    if (this != &src)
    {
        this->_currentRoom = src._currentRoom;
    }
    return (*this);
}

Classroom::~Classroom()
{
}

void Classroom::assignCourse(std::shared_ptr<Course> p_course)
{
    this->_currentRoom = p_course;
}

