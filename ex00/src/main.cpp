/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:33:59 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 18:42:41 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Secretary.hpp"
#include "../includes/NeedMoreClassRoomForm.hpp"
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


int main()
{
    // Create some rooms
    std::shared_ptr<Classroom> classroom = std::make_shared<Classroom>();
    std::shared_ptr<Courtyard> courtyard = std::make_shared<Courtyard>();
    std::shared_ptr<StaffRestRoom> staffRestRoom = std::make_shared<StaffRestRoom>();
    std::shared_ptr<SecretarialOffice> secretarialOffice = std::make_shared<SecretarialOffice>();

    // Create a professor
    std::shared_ptr<Professor> professor = std::make_shared<Professor>("Dr. Smith");

    // Create a course and assign a professor
    std::shared_ptr<Course> course = std::make_shared<Course>("Advanced C++");
    course->assignProfessor(professor);
    professor->assignCourse(course);

    // Create some students
    std::shared_ptr<Student> student1 = std::make_shared<Student>("Alice");
    std::shared_ptr<Student> student2 = std::make_shared<Student>("Bob");

    // Subscribe students to the course
    course->subscribeStudent(student1);
    course->subscribeStudent(student2);

    // Students attend class
    student1->attendClass(classroom);
    student2->attendClass(classroom);

    // Print classroom occupants
    classroom->printOccupants();

    // Students exit class
    student1->exitClass();
    student2->exitClass();

    // Professor conducts a class
    professor->doClass();

    // Professor closes the course
    professor->closeCourse();

    // Students graduate
    student1->graduate(course);
    student2->graduate(course);

    // Staff using staff restroom
    professor->setRoom(staffRestRoom);
    staffRestRoom->enter(professor);
    staffRestRoom->printOccupants();

    // Staff leaving the restroom
    staffRestRoom->exit(professor);

    // Moving to courtyard
    professor->setRoom(courtyard);
    courtyard->enter(professor);
    courtyard->printOccupants();

    // All students and professor enter the secretarial office
    student1->setRoom(secretarialOffice);
    student2->setRoom(secretarialOffice);
    professor->setRoom(secretarialOffice);

    secretarialOffice->enter(student1);
    secretarialOffice->enter(student2);
    secretarialOffice->enter(professor);

    secretarialOffice->printOccupants();

    // Clean up before exiting
    secretarialOffice->exit(student1);
    secretarialOffice->exit(student2);
    secretarialOffice->exit(professor);

    return (0);
}
