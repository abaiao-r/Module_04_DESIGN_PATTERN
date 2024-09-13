/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classroom.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:45:01 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/12 16:55:58 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/one.hpp"

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
