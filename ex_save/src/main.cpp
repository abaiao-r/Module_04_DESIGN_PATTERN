/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:33:59 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/12 19:07:31 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/one.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>
#include <string>

/* #include "../includes/Room.hpp"


int main(void) 
{
    // request forms through headmaster
    Headmaster headmaster;
    Secretary secretary("Secretary");
    Professor professor("Professor");
    Student student("Student");

    headmaster.setSecretary(&secretary);
    headmaster.addProfessor(&professor);
    headmaster.addStudent(&student);

    // set mediator
    professor.setMediator(&headmaster);
    student.setMediator(&headmaster);
    secretary.setMediator(&headmaster);
    
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    // create, sign and execute forms through headmaster
    professor.requestCourseCreation("Math");
    // return "Math" course
    Course *course = headmaster.findCourse("Math");
    // find who is the responsible professor for the course
    Professor *responsibleProfessor = course->getResponsableProfessor();
    // get professor name
    std::string professorName = responsibleProfessor->name();
    //print professor name
    std::cout << "Professor name: " << professorName << std::endl;
    
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    professor.requestMoreClassRoom("Math");
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    professor.requestGraduation("Student");
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    student.requestToSubscribeToCourse("Math");
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
} */



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

    std::cout << "-----------------------------------" << std::endl;

    professor.requestCourseCreation("Math");
    Course *course = headmaster.findCourse("Math");
    Professor *responsibleProfessor = course->getResponsableProfessor();
    std::string professorName = responsibleProfessor->name();
    std::cout << "Professor name: " << professorName << std::endl;

    std::cout << "-----------------------------------" << std::endl;


    student.requestToSubscribeToCourse("Math");

    std::cout << "-----------------------------------" << std::endl;
    
    professor.requestGraduation("Student");

    std::cout << "-----------------------------------" << std::endl;
    
    std::cout << "here" << std::endl;
    // test if professor can enter the room
    std::vector<Room*> rooms = headmaster.getRooms();
    if (rooms.empty())
    {
        std::cout << "No rooms" << std::endl;
        professor.requestMoreClassRoom("Math");
    }
    rooms = headmaster.getRooms();
    // loop through the rooms and see if professor can enter
    for (auto it = rooms.begin(); it != rooms.end(); it++)
    {
        // if professor can enter the room then enter
        if ((*it)->canEnter(&professor))
        {
            (*it)->enter(&professor);
            break;
        }
        else
        {
            std::cout << "Professor cannot enter the room" << std::endl;
            professor.requestMoreClassRoom("Math");
        }
    }

    std::cout << "-----------------------------------" << std::endl;

    return 0;
}

