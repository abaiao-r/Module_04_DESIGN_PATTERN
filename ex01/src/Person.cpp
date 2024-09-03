/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:05:05 by andrefranci       #+#    #+#             */
/*   Updated: 2024/08/31 17:13:16 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Person.hpp"

Person::Person(const std::string &personName) : _name(personName), _currentRoom(nullptr)
{
}

Person::Person(const Person &src) : _name(src._name), _currentRoom(src._currentRoom)
{
}

Person &Person::operator=(const Person &src)
{
    if (this != &src)
    {
        this->_name = src._name;
        this->_currentRoom = src._currentRoom;
    }
    return (*this);
}

Person::~Person()
{
}

const std::shared_ptr<Room> &Person::room() const
{
    return (this->_currentRoom);
}

const std::string &Person::name() const
{
    return (this->_name);
}

void Person::setRoom(const std::shared_ptr<Room> room)
{
    this->_currentRoom = room;
}
