/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classroom.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:42:24 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/08 00:10:07 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Room.hpp"
#include "Course.hpp"

class Course;

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