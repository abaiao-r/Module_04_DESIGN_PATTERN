/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Room.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:37:19 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/13 20:59:11 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/one.hpp"

long long Room::ID = 0;

Room::Room() : _id(0), _occupants(), _mediator(nullptr)
{
    this->_id = Room::ID++;
}

Room::~Room()
{
}

bool Room::canEnter(const Person* person) const
{
    Professor* professor = dynamic_cast<Professor*>(const_cast<Person*>(person));
    Student* student = dynamic_cast<Student*>(const_cast<Person*>(person));

    // if professor and room is not empty return false
    if (professor && !this->_occupants.empty())
    {
        return false;
    }

    // if student and no teacher in room return false
    if (student && this->_occupants.empty())
    {
        return false;
    }

    // check if student is subscribed to the course
    if (student)
    {
        // check if the student is subscribed to any course
        if (student->getSubscribedCourse().empty())
        {
            return false;
        }
    }

    // if student and teacher from different course return false
    if (student && !this->_occupants.empty())
    {
        for (auto it = this->_occupants.begin(); it != this->_occupants.end(); it++)
        {
            Professor* professorInRoom = dynamic_cast<Professor*>(*it); // Renamed to avoid shadowing
            if (professorInRoom)
            {
                // store the course of the professor
                Course* course = professorInRoom->getCurrentCourse();
                // check if the student is subscribed to the course
                if (!student->findCourse(course->getCourseName()))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void Room::enter(Person* person)
{
    // check if the person can enter the room
    if (!this->canEnter(person))
    {
        return;
    }
    // Implement the enter method here
    std::cout << "Person: " << person->name() << " enters room " << this->_id << std::endl;
    this->_occupants.push_back(person);
    person->setRoom(this);
}

void Room::exit(Person* person)
{
    // Implement the exit method here
    for (auto it = this->_occupants.begin(); it != this->_occupants.end(); it++)
    {
        if (*it == person)
        {
            std::cout << "Person: " << person->name() << " exits room " << this->_id << std::endl;
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

void Room::setMediator(Headmaster* mediator)
{
    // Implement the setMediator method here
    this->_mediator = mediator;
}

long long Room::getId() const
{
    return this->_id;
}

std::vector<Person*> Room::getOccupants() const
{
    return this->_occupants;
}

bool Room::isOccupant(Person* person) const
{
    // Implement the isOccupant method here
    for (auto it = this->_occupants.begin(); it != this->_occupants.end(); it++)
    {
        if (*it == person)
        {
            return true;
        }
    }
    return false;
}
