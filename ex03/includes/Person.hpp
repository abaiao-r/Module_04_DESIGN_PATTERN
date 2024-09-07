/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:55:18 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/07 17:02:53 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#include "Room.hpp"

class Room;

class Person
{
    private:
        std::string _name;
        Room* _currentRoom;
    
    public:
        explicit Person(const std::string &personName); 
        Person(const Person &src);
        Person &operator=(const Person &src);
        virtual ~Person();

        // Getters
        Room* room() const;
        const std::string &name() const;

        // Setters
        void setRoom(Room* room);
};
