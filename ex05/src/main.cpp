/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:33:59 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/14 16:29:25 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/one.hpp"
#include "../includes/School.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>
#include <string>


int main(void) 
{
    School school;

    school.recruteProfessor();
    school.recruteProfessor();
    school.recruteStudent();
    school.recruteStudent();
    

    school.runDayRoutine();

    school.recruteStudent();
    school.graduationCeremony();
    
    std::cout << "--------------------------------" << std::endl;
    //print  all courses
    std::vector<Course*> courses = school.getHeadmaster().getCourses();
    for (auto it = courses.begin(); it != courses.end(); it++)
    {
        std::cout << "Course: " << (*it)->getCourseName() << std::endl;
    }
      std::cout << "--------------------------------" << std::endl;
    // print all students
    std::vector<Student*> students = school.getStudents();
    for (auto it = students.begin(); it != students.end(); it++)
    {
        std::cout << "Student: " << (*it)->name() << std::endl;
    }
  std::cout << "--------------------------------" << std::endl;
    // print all professors
    std::vector<Professor*> professors = school.getProfessors();
    for (auto it = professors.begin(); it != professors.end(); it++)
    {
        std::cout << "Professor: " << (*it)->name() << std::endl;
    }
  std::cout << "--------------------------------" << std::endl;
    //print the secretary
    std::cout << "Secretary: " << school.getSecretary().name() << std::endl;
    //print the headmaster

    return 0;

}

