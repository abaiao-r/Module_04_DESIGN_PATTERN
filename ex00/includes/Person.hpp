/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Person.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:55:18 by andrefranci       #+#    #+#             */
/*   Updated: 2024/08/31 17:14:49 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <memory>

#include "Room.hpp"

class Room;

class Person
{
    private:
        std::string _name;
        std::shared_ptr<Room> _currentRoom;
    
    public:
        explicit Person(const std::string &personName); 
        Person(const Person &src);
        Person &operator=(const Person &src);
        virtual ~Person();

        // Getters
        const std::shared_ptr<Room> &room() const;
        const std::string &name() const;

        // Setters
        void setRoom(const std::shared_ptr<Room> room);
};
