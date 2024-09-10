/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:47:04 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/10 14:10:23 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Person.hpp"
#include "Headmaster.hpp"
#include "Course.hpp"
#include "Classroom.hpp"
#include <iostream>
#include <vector>

class Course;
class Classroom;
class Headmaster;

class Student : public Person
{
    private:
        std::vector<Course*> _subscribedCourse;
        Headmaster *_mediator;

    public:
        explicit Student(const std::string &studentName);
        virtual ~Student();

        //Methods
        void attendClass(Classroom* classroom);
        void exitClass();
        void graduate(Course* course);
        
        void requestToSubscribeToCourse(const std::string &courseName);
        void setMediator(Headmaster* mediator);
};
