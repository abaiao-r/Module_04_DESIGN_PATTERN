/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classroom.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:42:24 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/12 16:30:34 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Room.hpp"
#include "Course.hpp"


class Course;

class Classroom : public Room
{
    private:
        Course *_currentRoom;

    public:
        Classroom();
        virtual ~Classroom();
        
        //Methods
        void assignCourse(Course* p_course);
};
