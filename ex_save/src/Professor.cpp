/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Professor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:58:29 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/12 20:50:04 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/one.hpp"

Professor::Professor(const std::string &staffName) : Staff(staffName), _currentCourse(nullptr), _mediator(nullptr)
{
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
    // Implement the doClass method here
    // if professor has a course assigned and has a classroom
    // then professor gives class
    if (this->_currentCourse)
    {
        // loop through all classrooms using the mediator and check if can enter
        std::vector<Room*> rooms = this->_mediator->getRooms();
        for (auto it = rooms.begin(); it != rooms.end(); it++)
        {
            Classroom* classroom = dynamic_cast<Classroom*>(*it);
            if (classroom && classroom->canEnter(this))
            {
                // if professor already in classroom then skip
                // loop through the occupants of the classroom and check if professor is already in
                // if professor not there yet then enter
                std::vector<Person*> occupants = classroom->getOccupants();
                // if end of occupants then professor not in classroom
                // enter the classroom
                auto occupantIt = occupants.begin();
                for (; occupantIt != occupants.end(); occupantIt++)
                {
                    if (*occupantIt == this)
                    {
                        break;
                    }
                }
                if (occupantIt == occupants.end())
                {
                    classroom->enter(this);
                }
                // function for students to enter this classroom through mediator
                // get students from mediator
                std::vector<Student*> students = this->_mediator->getStudents();
                for (auto studentIt = students.begin(); studentIt != students.end(); studentIt++)
                {
                    // if student is subscribed to the course then enter the classroom
                    if ((*studentIt)->findCourse(this->_currentCourse->getCourseName()))
                    {
                        classroom->enter(*studentIt);
                        // update course _attendanceTimes
                        this->_currentCourse->setAttendanceTimes(*studentIt);
                        if (this->_currentCourse->canGraduate(*studentIt))
                        {
                            this->requestGraduation((*studentIt)->name());
                        }
                    }
                }
                std::cout << "Professor gave class" << std::endl;
                // make students exit the classroom and professor exit
                classroom->exit(this);
                for (auto studentIt = students.begin(); studentIt != students.end(); studentIt++)
                {
                    classroom->exit(*studentIt);
                }
                return;
            }
        }
        std::cout << "No classroom available" << std::endl;
        // if no classroom available then request more classroom
        this->requestMoreClassRoom(this->_currentCourse->getCourseName());
    }
    else
    {
        std::cout << "No course assigned" << std::endl;
        // if no course assigned then request course creation
        this->requestCourseCreation("someCourse");
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


