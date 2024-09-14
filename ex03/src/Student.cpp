/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Student.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:49:19 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/13 19:29:13 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/one.hpp"


Student::Student(const std::string &studentName) : Person(studentName), _subscribedCourse(), _mediator(nullptr)
{
}

Student::~Student()
{
}

void Student::attendClass(Classroom* classroom)
{
    // Implement the attendClass method here
    classroom->enter(this);
    std::cout << "Student attended class" << std::endl;
}

void Student::exitClass()
{
    // Implement the exitClass method here
    std::cout << "Student exited class" << std::endl;
}

void Student::graduate(Course* course)
{
    // Implement the graduate method here
    std::cout << "Student name: " << this->name() << " graduated from course: " << course->getCourseName() << std::endl;
}

void Student::requestToSubscribeToCourse(const std::string &course)
{
    // Implement the requestToSubscribeToCourse method here
    if (_mediator)
    {
        std::cout << "Student requests to subscribe to course" << std::endl;
        //_mediator->notify("Student", "RequestCourseSubscription");
        _mediator->notify(*this, "RequestCourseSubscription", course);
    }
}

void Student::setMediator(Headmaster* mediator)
{
    // Implement the setMediator method here
    _mediator = mediator;
}

void Student::setSubscribedCourse(Course* course)
{
    // Implement the setSubscribedCourse method here
    _subscribedCourse.push_back(course);

}

std::vector<Course*> Student::getSubscribedCourse() const
{
    // Implement the getSubscribedCourse method here
    return (_subscribedCourse);
}

Course* Student::findCourse(const std::string &courseName) const
{
    // Implement the findCourse method here
    for (auto it = _subscribedCourse.begin(); it != _subscribedCourse.end(); it++)
    {
        if ((*it)->getCourseName() == courseName)
        {
            return (*it);
        }
    }
    return (nullptr);
}

void Student::removeCourse(const std::string &courseName)
{
    // Implement the removeCourse method here
    for (auto it = _subscribedCourse.begin(); it != _subscribedCourse.end(); it++)
    {
        if ((*it)->getCourseName() == courseName)
        {
            _subscribedCourse.erase(it);
            break;
        }
    }
}

void Student::lookForCourseToSubscribe()
{
    // if student is subscribed to any course then return
    if (!_subscribedCourse.empty())
    {
        return;
    }
    // Implement the lookForCourseToSubscribe method here
    // loop through the courses using the mediator, if there is a course then subscribe
    std::vector<Course*> courses = _mediator->getCourses();
    for (auto it = courses.begin(); it != courses.end(); it++)
    {
        // request to subscribe to the course and then break
        this->requestToSubscribeToCourse((*it)->getCourseName());
        break;
    }
}

