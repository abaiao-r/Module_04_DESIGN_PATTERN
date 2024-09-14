/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:58:29 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/14 16:13:41 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/one.hpp"

Professor::Professor(const std::string &staffName) : Staff(staffName), _currentCourse(nullptr), _mediator(nullptr)
{
    std::cout << "Professor " << staffName << " created" << std::endl;
}

Professor::~Professor()
{
}

void Professor::assignCourse(Course* course)
{
    this->_currentCourse = course;
}

void Professor::doClass()
{
        while (true) {
        if (this->_currentCourse)
        {
            Room* currentRoom = room();
            // print current room for debug
            std::cout << "Current room: " << currentRoom << std::endl;
            if (!currentRoom) {
                // look for a room to enter by checking if can enter any room
                std::vector<Room*> rooms = this->_mediator->getRooms();
                auto it = rooms.begin();
                for (; it != rooms.end(); it++) {
                    if ((*it)->canEnter(this)) {
                        (*it)->enter(this);
                        break;
                    }
                }
                if (it == rooms.end()) {
                    // if no room available then request more room
                    this->requestMoreClassRoom(this->_currentCourse->getCourseName());
                    // restart the function
                    continue;
                }       
            }
            // make subscribed students enter the room through the mediator
            Classroom* classroom = dynamic_cast<Classroom*>(this->room());
            if (classroom) {
                this->_mediator->makeStudentsEnterRoom(classroom);
                // print the room occupants for debug
                classroom->printOccupants();
                std::cout << "Professor does class in room " << classroom->getId() << std::endl;
                // set attendanceTimes for all the room occupants that are students
                std::vector<Person*> occupants = classroom->getOccupants();
                for (auto it = occupants.begin(); it != occupants.end(); it++) {
                    Student* student = dynamic_cast<Student*>(*it);
                    if (student) {
                        this->_currentCourse->setAttendanceTimes(student);
                        // if student can graduate then request graduation
                        /* if (this->_currentCourse->canGraduate(student)) {
                            this->requestGraduation(student->name());
                        } */
                    }
                }
            } else {
                std::cout << "No classroom" << std::endl;
            }
        } else {
            std::cout << "No course assigned" << std::endl;
            // if no course assigned then request course creation
            this->requestCourseCreation("someCourse");
        }
        break; // exit the loop if no need to restart
    }
}

void Professor::closeCourse()
{
    // Implement the closeCourse method here
    this->_currentCourse = nullptr;
}

void Professor::requestCourseCreation(const std::string &courseName)
{
    // Implement the requestCourseCreation method here
    if (this->_mediator)
    {
        std::cout << "Professor requests course creation" << std::endl;
        //_mediator->notify("Professor", "CreateCourse");
        _mediator->notify(*this, "CreateCourse", courseName);
    }
}

void Professor::setMediator(Headmaster* mediator)
{
    // Implement the setMediator method here
    this->_mediator = mediator;
}

void Professor::requestGraduation(const std::string &studentName)
{
    (void) studentName;
    // Implement the requestGraduation method here
    if (this->_mediator)
    {
        std::cout << "Professor requests graduation" << std::endl;
        //_mediator->notify("Professor", "CourseFinished");
        _mediator->notify(*this, "CourseFinished", studentName);
    }
}

void Professor::requestMoreClassRoom(const std::string &courseName)
{
    (void) courseName;
    // Implement the requestMoreClassRoom method here
    if (this->_mediator)
    {
        std::cout << "Professor requests more classroom" << std::endl;
        //_mediator->notify("Professor", "NeedsMoreClasses");
        _mediator->notify(*this, "NeedsMoreClasses", courseName);
    }
}

Course* Professor::getCurrentCourse() const
{
    // Implement the getCurrentCourse method here
    return (this->_currentCourse);
}

void Professor::onBellRing(Event event)
{
    // Implement the onBellRing method here
    if (event == Event::RingBell)
    {
        std::cout << "Professor " << this->name() << " heard the bell ring" << std::endl;
        // if professor is in a room then make him exit
        Room* currentRoom = room();
        if (currentRoom)
        {
            currentRoom->exit(this);
            this->setRoom(nullptr);
        }
        else
        {
            // make him do class
            this->doClass();
        }
    }
}

