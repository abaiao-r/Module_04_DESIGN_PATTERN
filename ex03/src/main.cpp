/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:33:59 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/12 16:33:32 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../includes/Room.hpp"
#include "../includes/Person.hpp"
#include "../includes/IMediator.hpp"
#include "../includes/Staff.hpp"
#include "../includes/Form.hpp"
#include "../includes/Course.hpp"
#include "../includes/Headmaster.hpp"
#include "../includes/StaffRestRoom.hpp"
#include "../includes/Classroom.hpp"
#include "../includes/NeedCourseCreationForm.hpp"
#include "../includes/NeedMoreClassRoomForm.hpp"
#include "../includes/CourseFinishedForm.hpp"
#include "../includes/SubscriptionToCourseForm.hpp"
#include "../includes/Secretary.hpp"
#include "../includes/Professor.hpp"
#include "../includes/Student.hpp"
#include "../includes/Courtyard.hpp"
#include "../includes/SecretarialOffice.hpp"
#include "../includes/Singleton.hpp"
#include "../includes/HeadmasterOffice.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>
#include <string>

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

#include "../includes/Room.hpp"
#include "../includes/Person.hpp"
#include "../includes/IMediator.hpp"
#include "../includes/Staff.hpp"
#include "../includes/Form.hpp"
#include "../includes/Course.hpp"
#include "../includes/Headmaster.hpp"
#include "../includes/StaffRestRoom.hpp"
#include "../includes/Classroom.hpp"
#include "../includes/NeedCourseCreationForm.hpp"
#include "../includes/NeedMoreClassRoomForm.hpp"
#include "../includes/CourseFinishedForm.hpp"
#include "../includes/SubscriptionToCourseForm.hpp"
#include "../includes/Secretary.hpp"
#include "../includes/Professor.hpp"
#include "../includes/Student.hpp"
#include "../includes/Courtyard.hpp"
#include "../includes/SecretarialOffice.hpp"
#include "../includes/Singleton.hpp"
#include "../includes/HeadmasterOffice.hpp"

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

    std::cout << "-----------------------------------" << std::endl;

    professor.requestCourseCreation("Math");
    Course *course = headmaster.findCourse("Math");
    Professor *responsibleProfessor = course->getResponsableProfessor();
    std::string professorName = responsibleProfessor->name();
    std::cout << "Professor name: " << professorName << std::endl;

    std::cout << "-----------------------------------" << std::endl;

    professor.requestMoreClassRoom("Math");
    std::cout << "-----------------------------------" << std::endl;

    professor.requestGraduation("Student");
    std::cout << "-----------------------------------" << std::endl;

    student.requestToSubscribeToCourse("Math");
    std::cout << "-----------------------------------" << std::endl;

    return 0;
}

