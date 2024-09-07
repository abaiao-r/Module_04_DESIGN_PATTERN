/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:56:03 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/07 17:04:03 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"
#include "Course.hpp"

class Course;

class Professor : public Staff
{
    private:
        Course* _currentCourse;
    
    public:
        explicit Professor(const std::string &staffName);
        Professor(const Professor &src);
        Professor &operator=(const Professor &src);
        virtual ~Professor();

        void assignCourse(Course* course);
        void doClass();
        void closeCourse();
};