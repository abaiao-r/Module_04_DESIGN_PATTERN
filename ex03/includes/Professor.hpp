/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:56:03 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/09 19:38:15 by andrefranci      ###   ########.fr       */
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