/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:47:04 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/07 17:09:50 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Person.hpp"
#include "Course.hpp"
#include "Classroom.hpp"
#include <vector>

class Course;
class Classroom;

class Student : public Person
{
    private:
        std::vector<Course*> _subscribedCourse;

    public:
        explicit Student(const std::string &studentName);
        Student(const Student &src);
        Student &operator=(const Student &src);
        virtual ~Student();

        //Methods
        void attendClass(Classroom* classroom);
        void exitClass();
        void graduate(Course* course);
};
