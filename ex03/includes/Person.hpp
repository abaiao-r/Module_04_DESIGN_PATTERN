/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:55:18 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/08 00:11:03 by andrefranci      ###   ########.fr       */
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
        virtual ~Person();

        // Getters
        Room* room() const;
        const std::string &name() const;

        // Setters
        void setRoom(Room* room);
};
