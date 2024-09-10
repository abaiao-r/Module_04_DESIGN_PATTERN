/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classroom.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:45:01 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/08 00:11:57 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Classroom.hpp"

Classroom::Classroom() : Room(), _currentRoom(nullptr)
{
}


Classroom::~Classroom()
{
}

void Classroom::assignCourse(Course* p_course)
{
    this->_currentRoom = p_course;
}
