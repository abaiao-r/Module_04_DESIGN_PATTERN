/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:33:59 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/11 16:21:16 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Secretary.hpp"
#include "../includes/NeedMoreClassRoomForm.hpp"
#include "../includes/NeedCourseCreationForm.hpp"
#include "../includes/SubscriptionToCourseForm.hpp"
#include "../includes/CourseFinishedForm.hpp"
#include "../includes/StaffRestRoom.hpp"
#include "../includes/Classroom.hpp"
#include "../includes/Student.hpp"
#include "../includes/Professor.hpp"
#include "../includes/Staff.hpp"
#include "../includes/Room.hpp"
#include "../includes/Form.hpp"
#include "../includes/Person.hpp"
#include "../includes/Course.hpp"
#include "../includes/Courtyard.hpp"
#include "../includes/SecretarialOffice.hpp"
#include "../includes/Singleton.hpp"
#include "../includes/HeadmasterOffice.hpp"
#include "../includes/Headmaster.hpp"
#include "../includes/IMediator.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>
#include <string>

// Define specific Singleton types
using StudentList = Singleton<std::string, struct StudentTag>;
using StaffList = Singleton<std::string, struct StaffTag>;
using CourseList = Singleton<std::string, struct CourseTag>;
using RoomList = Singleton<std::string, struct RoomTag>;

int main(void) 
{
/*     // create  staff list, student list, course list, room list
    auto& studentList = StudentList::getInstance();
    auto& staffList = StaffList::getInstance();
    auto& courseList = CourseList::getInstance();
    auto& roomList = RoomList::getInstance(); */

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
}
