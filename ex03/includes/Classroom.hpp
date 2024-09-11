/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classroom.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:42:24 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/11 18:24:29 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Course.hpp"
#include "Room.hpp"

class Classroom : public Room
{
    private:
        Course* _currentRoom;

    public:
        Classroom();
        virtual ~Classroom();
        
        //Methods
        void assignCourse(Course* p_course);
};
