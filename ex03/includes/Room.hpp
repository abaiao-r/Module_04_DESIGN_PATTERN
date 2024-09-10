/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Room.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:33:09 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/08 00:11:13 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>

#include "Person.hpp"

class Person;

class Room
{
    private:
        long long _id;
        std::vector<Person*> _occupants;
        static long long ID;

    public:
        Room();
        virtual ~Room();

        //Methods
        bool canEnter(const Person* person) const;
        void enter(Person* person);
        void exit(Person* person);
        void printOccupants() const;
};

