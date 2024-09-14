/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:05:05 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/12 17:33:16 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/one.hpp"

Person::Person(const std::string &personName) : _name(personName), _currentRoom(nullptr)
{
}

Person::~Person()
{
}

Room* Person::room() const
{
    return this->_currentRoom;
}

const std::string &Person::name() const
{
    return this->_name;
}

void Person::setRoom(Room* room)
{
    this->_currentRoom = room;
}
