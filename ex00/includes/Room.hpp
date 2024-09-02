/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Room.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:33:09 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 16:53:08 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "Person.hpp"

class Person;

class Room
{
    private:
        long long _id;
        std::vector<std::shared_ptr<Person>> _occupants;
        static long long ID;

    public:
        Room();
        Room(const Room &src);
        Room &operator=(const Room &src);
        virtual ~Room();

        //Methods
        bool canEnter(const std::shared_ptr<Person> person) const;
        void enter(const std::shared_ptr<Person> person);
        void exit(const std::shared_ptr<Person> person);
        void printOccupants() const;
};

