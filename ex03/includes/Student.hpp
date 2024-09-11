/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:47:04 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/11 16:13:36 by abaiao-r         ###   ########.fr       */
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

        //setters
        void setSubscribedCourse(Course* course);
        void setMediator(Headmaster* mediator);

        //Getters
        std::vector<Course*> getSubscribedCourse() const;

        // find a specific course in the subscribed courses
        Course* findCourse(const std::string &courseName) const;

        //remove a course from the subscribed courses
        void removeCourse(const std::string &courseName);
};
