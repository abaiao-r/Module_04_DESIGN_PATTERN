/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:56:03 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/10 19:10:28 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"
#include "Course.hpp"
#include <iostream>
#include "Headmaster.hpp"

class Course;
class Headmaster;

class Professor : public Staff
{
    private:
        Course* _currentCourse;
        Headmaster *_mediator;
    
    public:
        explicit Professor(const std::string &staffName);
        virtual ~Professor();

        void assignCourse(Course* course);
        void doClass();
        void closeCourse();

        void requestCourseCreation(const std::string &courseName);
        void setMediator(Headmaster* mediator);
        void requestGraduation(const std::string &studentName);
        void requestMoreClassRoom(const std::string &courseName);  
        
          
    };