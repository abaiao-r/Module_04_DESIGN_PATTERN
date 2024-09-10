/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:47:04 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/09 18:50:22 by andrefranci      ###   ########.fr       */
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
        
        void requestToSubscribeToCourse(Course* course);
        void setMediator(Headmaster* mediator);
};
