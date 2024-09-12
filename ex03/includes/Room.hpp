/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Room.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:33:09 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/12 16:32:44 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>

#include "Person.hpp"
#include "Headmaster.hpp"

// class Person;
class Headmaster;

class Room
{
    private:
        long long _id;
        std::vector<Person*> _occupants;
        static long long ID;
        Headmaster *_mediator;

    public:
        Room();
        virtual ~Room();

        //Methods
        bool canEnter(const Person* person) const;
        void enter(Person* person);
        void exit(Person* person);
        void printOccupants() const;

        //setters
        void setMediator(Headmaster* mediator);

        //Getters
        long long getId() const;
        std::vector<Person*> getOccupants() const;
};

