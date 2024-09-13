/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   School.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 22:11:16 by abaiao-r          #+#    #+#             */
/*   Updated: 2024/09/13 22:11:56 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCHOOL_HPP
#define SCHOOL_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>
#include <string>
#include <map>
#include <algorithm>  // For std::remove

#include "one.hpp"

class School
{
private:
    Headmaster _headmaster;
    Secretary _secretary;
    std::vector<Professor*> _professors;
    std::vector<Student*> _students;
    std::vector<Course*> _courses;

public:
    // Constructor and Destructor
    School();
    virtual ~School();

    // Methods
    void runDayRoutine();
    void launchClasses();
    void requestRingBell();
    void recruteProfessor(Professor* professor);
    void recruteStudent(Student* student);
    Course* getCourse(const std::string &courseName);
    std::vector<Student*> getStudents() const;
    std::vector<Professor*> getProfessors() const;
    Headmaster& getHeadmaster();
    Secretary& getSecretary();
    void graduationCeremony();
};

#endif