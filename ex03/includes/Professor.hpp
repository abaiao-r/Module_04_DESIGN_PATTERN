/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:56:03 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/12 15:59:18 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"
#include "Course.hpp"
#include "Person.hpp"
#include <iostream>

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

        //Getters
        Course* getCurrentCourse() const;  
        
          
    };