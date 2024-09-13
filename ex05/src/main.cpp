/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:33:59 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/13 21:11:41 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/one.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>
#include <string>


int main(void) 
{
    Headmaster headmaster;
    Secretary secretary("Secretary");
    Professor professor("Professor");
    Student student("Student");
    
    headmaster.setSecretary(&secretary);
    headmaster.addProfessor(&professor);
    headmaster.addStudent(&student);

    professor.setMediator(&headmaster);
    student.setMediator(&headmaster);
    secretary.setMediator(&headmaster);

    // register professor and student as bell observers
    headmaster.addBellObserver(&professor);
    headmaster.addBellObserver(&student);

    std::cout << "-----------------------------------" << std::endl;

    professor.requestCourseCreation("Math");
    Course *course = headmaster.findCourse("Math");
    Professor *responsibleProfessor = course->getResponsableProfessor();
    std::string professorName = responsibleProfessor->name();
    std::cout << "Professor name: " << professorName << std::endl;

    std::cout << "-----------------------------------" << std::endl;

    student.requestToSubscribeToCourse("Math");
    

    std::cout << "-----------------------------------" << std::endl;

    // professor reuest room
    professor.requestMoreClassRoom("Math");
    // professor do class
    professor.doClass();
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    headmaster.ringBell();
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    headmaster.ringBell();

    //print the room of professor and student
    std::cout << "Professor room: " << professor.room() << std::endl;
    std::cout << "Student room: " << student.room() << std::endl;

    return 0;
}

