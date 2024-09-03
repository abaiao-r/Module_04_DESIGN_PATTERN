/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Course.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:07:05 by andrefranci       #+#    #+#             */
/*   Updated: 2024/08/31 17:14:32 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Professor.hpp"
#include "Student.hpp"

class Professor;
class Student;

class Course
{
    private:
        std::string _courseName;
        std::shared_ptr<Professor> _responsableProfessor;
        std::vector<std::shared_ptr<Student>> _students;
        int _numberOfClassToGraduate;
        int _maximumNumberOfStudent;

    public:
        explicit Course(const std::string &courseName);
        Course(const Course &src);
        Course &operator=(const Course &src);
        virtual ~Course();
        
        //Methods
        void assignProfessor(const std::shared_ptr<Professor> professor);
        void subscribeStudent(const std::shared_ptr<Student> student);
        
};

