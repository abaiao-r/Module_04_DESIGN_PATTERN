/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Room.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:37:19 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/07 17:14:37 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Room.hpp"

long long Room::ID = 0;

Room::Room()
{
    this->_id = Room::ID++;
    this->_occupants = std::vector<Person*>();
}

Room::Room(const Room &src) : _id(Room::ID++)
{
    this->_occupants = src._occupants;
}

Room &Room::operator=(const Room &src)
{
    if (this != &src)
    {
        this->_id = Room::ID++;
        this->_occupants = src._occupants;
    }
    return (*this);
}

Room::~Room()
{
}

bool Room::canEnter(const Person* person) const
{
    // Implement the canEnter method here
    (void)person;
    return (true);
}

void Room::enter(Person* person)
{
    // check if the person can enter the room
    if (!this->canEnter(person))
    {
        return;
    }
    // Implement the enter method here
    this->_occupants.push_back(person);
}

void Room::exit(Person* person)
{
    // Implement the exit method here
    for (auto it = this->_occupants.begin(); it != this->_occupants.end(); it++)
    {
        if (*it == person)
        {
            this->_occupants.erase(it);
            break;
        }
    }
}

void Room::printOccupants() const
{
    std::cout << "Occupants of the room " << this->_id << ":" << std::endl;
    // Implement the printOccupants method here
    for (auto it = this->_occupants.begin(); it != this->_occupants.end(); it++)
    {
        std::cout << (*it)->name() << std::endl;
    }
}
