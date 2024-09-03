/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classroom.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:42:24 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 17:08:36 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Room.hpp"
#include "Course.hpp"
#include <memory>

class Course;

class Classroom : public Room
{
    private:
        std::shared_ptr<Course> _currentRoom;

    public:
        Classroom();
        Classroom(const Classroom &src);
        Classroom &operator=(const Classroom &src);
        virtual ~Classroom();
        
        //Methods
        void assignCourse(std::shared_ptr<Course> p_course);
};
