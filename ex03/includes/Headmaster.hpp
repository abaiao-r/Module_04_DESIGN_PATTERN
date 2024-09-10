/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:14:53 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/09 19:40:10 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

#include "Staff.hpp"
#include "Form.hpp"
#include "IMediator.hpp"
#include "Professor.hpp"
#include "Student.hpp"
#include "Secretary.hpp"

class Professor;
class Student;
class Secretary;

class Headmaster : public Staff, public IMediator
{
    private:
        std::vector<Form*> _formToValidate;
        Professor *_professor;
        Secretary *_secretary;
        std::vector<Student*> _students;

    public:
        Headmaster();
        virtual ~Headmaster();

        void setProfessor(Professor *professor);
        void setSecretary(Secretary *secretary);
        void addStudent(Student *student);
        void notify(const std::string &sender, const std::string &event) const override;

        //Methods
        void receiveForm(Form* p_form);
        void signForm(Form* p_form);
        void executeForm(Form* p_form); 

          /*
        Professor Methods
        Go teach a course
        Assign a course
             - request form to create a course
             - request professor to fill the form
             - sign the form and execute it
             - then assign the professor to the course
        Graduate  a student
            - request form to graduate a student
            - request professor to fill the form
            - sign the form and execute it

        No class room available
            - request form to create a class room
            - request professor to fill the form
            - sign the form and execute it

        Student Methods
        Attend a course
        Request a course
            - request form to create a course
            - request student to fill the form
            - sign the form and execute it
            - then assign the student to the course
        */       
};