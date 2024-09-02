/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StaffRestRoom.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:22:19 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 17:22:43 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Room.hpp"

class StaffRestRoom : public Room
{
    private:
        
    public:
        StaffRestRoom();
        StaffRestRoom(const StaffRestRoom &src);
        StaffRestRoom &operator=(const StaffRestRoom &src);
        virtual ~StaffRestRoom();
};
