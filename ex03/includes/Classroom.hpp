/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classroom.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:42:24 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/07 16:58:23 by andrefranci      ###   ########.fr       */
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
        Classroom(const Classroom &src);
        Classroom &operator=(const Classroom &src);
        virtual ~Classroom();
        
        //Methods
        void assignCourse(Course* p_course);
};