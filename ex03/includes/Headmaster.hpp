/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:14:53 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/11 09:41:28 by andrefranci      ###   ########.fr       */
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
#include "Course.hpp"

class Secretary;
class Course;
class Professor;
class Student;

class Headmaster : public Staff, public IMediator
{
    private:
        std::vector<Form*> _formToValidate;
        std::vector<Professor*> _professors;
        Secretary *_secretary;
        std::vector<Student*> _students;
        std::vector<Course*> _courses;

    public:
        Headmaster();
        virtual ~Headmaster();

        void addProfessor(Professor *professor);
        void setSecretary(Secretary *secretary);
        void addStudent(Student *student);
        void addCourse(Course *course);
        void notify(const std::string &sender, const std::string &event) override;
        void notify(Person &sender, const std::string &event, const std::string &target) override;

        //getters
        std::vector<Form*> getFormToValidate() const;
        std::vector<Professor*> getProfessors() const;
        Secretary* getSecretary() const;
        std::vector<Student*> getStudents() const;
        std::vector<Course*> getCourses() const;
        
        //find specific course
        Course* findCourse(const std::string &courseName);


        //Methods
        void receiveForm(Form* p_form);
        void signForm(Form* p_form);
        void executeForm(Form* p_form);

        

        //Professor Methods
        // Go teach a course
        void goTeachCourse(const std::string &Professor);

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