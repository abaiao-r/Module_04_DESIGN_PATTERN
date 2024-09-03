/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:56:03 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 17:58:04 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include "Staff.hpp"
#include "Course.hpp"

class Course;

class Professor : public Staff
{
    private:
        std::shared_ptr<Course> _currentCourse;
    
    public:
        explicit Professor(const std::string &staffName);
        Professor(const Professor &src);
        Professor &operator=(const Professor &src);
        virtual ~Professor();

        void assignCourse(const std::shared_ptr<Course> course);
        void doClass();
        void closeCourse();
};
