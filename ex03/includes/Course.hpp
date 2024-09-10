/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Course.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:07:05 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/08 00:10:15 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <vector>

#include "Professor.hpp"
#include "Student.hpp"

class Professor;
class Student;

class Course
{
    private:
        std::string _courseName;
        Professor* _responsableProfessor;
        std::vector<Student*> _students;
        int _numberOfClassToGraduate;
        int _maximumNumberOfStudent;

    public:
        explicit Course(const std::string &courseName);
        virtual ~Course();
        
        //Methods
        void assignProfessor(Professor* professor);
        void subscribeStudent(Student* student);
};
