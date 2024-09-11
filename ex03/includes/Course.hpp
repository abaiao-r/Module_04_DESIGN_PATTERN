/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Course.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:07:05 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/11 16:09:56 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <vector>

#include "Professor.hpp"
#include "Student.hpp"
#include "Headmaster.hpp"

class Professor;
class Student;
class Headmaster;

class Course
{
    private:
        std::string _courseName;
        Professor* _responsableProfessor;
        std::vector<Student*> _students;
        int _numberOfClassToGraduate;
        int _maximumNumberOfStudent;
        Headmaster *_mediator;

    public:
        explicit Course(const std::string &courseName);
        virtual ~Course();

        //setters
        void setNumberOfClassToGraduate(int numberOfClassToGraduate);
        void setMaximumNumberOfStudent(int maximumNumberOfStudent);

        //Getters
        std::string getCourseName() const;
        Professor* getResponsableProfessor() const;
        std::vector<Student*> getStudents() const;
        int getNumberOfClassToGraduate() const;
        int getMaximumNumberOfStudent() const;
        
        //Methods
        void assignProfessor(Professor* professor);
        void subscribeStudent(Student* student);
        void setMediator(Headmaster* mediator);
        void unsubscribeStudent(Student* student);
};
