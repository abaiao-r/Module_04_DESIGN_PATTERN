/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaffRestRoom.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:23:02 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 17:23:17 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/StaffRestRoom.hpp"

StaffRestRoom::StaffRestRoom() : Room()
{
}

StaffRestRoom::StaffRestRoom(const StaffRestRoom &src) : Room(src)
{
}

StaffRestRoom &StaffRestRoom::operator=(const StaffRestRoom &src)
{
    if (this != &src)
    {
        Room::operator=(src);
    }
    return (*this);
}

StaffRestRoom::~StaffRestRoom()
{
}
