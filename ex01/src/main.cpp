/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:33:59 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 14:30:30 by andrefranci      ###   ########.fr       */
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
#include "../includes/Singleton.hpp"

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

// Custom assert function to print error messages
#define ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            std::cerr << "Assertion failed: (" #condition "), function " << __FUNCTION__ \
                      << ", file " << __FILE__ << ", line " << __LINE__ << ".\n" \
                      << "Message: " << message << std::endl; \
            std::terminate(); \
        } \
    } while (false)

// Test functions
void testSingletonInstance() {
    auto& studentList1 = StudentList::getInstance();
    auto& studentList2 = StudentList::getInstance();
    ASSERT(&studentList1 == &studentList2, "StudentList instances are not the same");

    auto& staffList1 = StaffList::getInstance();
    auto& staffList2 = StaffList::getInstance();
    ASSERT(&staffList1 == &staffList2, "StaffList instances are not the same");

    auto& courseList1 = CourseList::getInstance();
    auto& courseList2 = CourseList::getInstance();
    ASSERT(&courseList1 == &courseList2, "CourseList instances are not the same");

    auto& roomList1 = RoomList::getInstance();
    auto& roomList2 = RoomList::getInstance();
    ASSERT(&roomList1 == &roomList2, "RoomList instances are not the same");
}

void testAddMethod() {
    auto& studentList = StudentList::getInstance();
    studentList.add("Alice");
    studentList.add("Bob");
    studentList.add("Charlie");
    const auto& students = studentList.getList();
    ASSERT(students.size() == 3, "StudentList size is incorrect");
    ASSERT(students[0] == "Alice", "First student is incorrect");
    ASSERT(students[1] == "Bob", "Second student is incorrect");
    ASSERT(students[2] == "Charlie", "Third student is incorrect");

    auto& staffList = StaffList::getInstance();
    staffList.add("Dr. Smith");
    staffList.add("Prof. Johnson");
    const auto& staff = staffList.getList();
    ASSERT(staff.size() == 2, "StaffList size is incorrect");
    ASSERT(staff[0] == "Dr. Smith", "First staff member is incorrect");
    ASSERT(staff[1] == "Prof. Johnson", "Second staff member is incorrect");

    auto& courseList = CourseList::getInstance();
    courseList.add("Math 101");
    courseList.add("Physics 202");
    const auto& courses = courseList.getList();
    ASSERT(courses.size() == 2, "CourseList size is incorrect");
    ASSERT(courses[0] == "Math 101", "First course is incorrect");
    ASSERT(courses[1] == "Physics 202", "Second course is incorrect");

    auto& roomList = RoomList::getInstance();
    roomList.add("Room A");
    roomList.add("Room B");
    const auto& rooms = roomList.getList();
    ASSERT(rooms.size() == 2, "RoomList size is incorrect");
    ASSERT(rooms[0] == "Room A", "First room is incorrect");
    ASSERT(rooms[1] == "Room B", "Second room is incorrect");
}

void testRemoveMethod() {
    auto& studentList = StudentList::getInstance();
    studentList.remove("Bob");
    const auto& students = studentList.getList();
    ASSERT(students.size() == 2, "StudentList size after removal is incorrect");
    ASSERT(students[0] == "Alice", "First student after removal is incorrect");
    ASSERT(students[1] == "Charlie", "Second student after removal is incorrect");

    auto& staffList = StaffList::getInstance();
    staffList.remove("Dr. Smith");
    const auto& staff = staffList.getList();
    ASSERT(staff.size() == 1, "StaffList size after removal is incorrect");
    ASSERT(staff[0] == "Prof. Johnson", "First staff member after removal is incorrect");

    auto& courseList = CourseList::getInstance();
    courseList.remove("Math 101");
    const auto& courses = courseList.getList();
    ASSERT(courses.size() == 1, "CourseList size after removal is incorrect");
    ASSERT(courses[0] == "Physics 202", "First course after removal is incorrect");

    auto& roomList = RoomList::getInstance();
    roomList.remove("Room A");
    const auto& rooms = roomList.getList();
    ASSERT(rooms.size() == 1, "RoomList size after removal is incorrect");
    ASSERT(rooms[0] == "Room B", "First room after removal is incorrect");
}

void testGetListMethod() {
    auto& studentList = StudentList::getInstance();
    const auto& students = studentList.getList();
    ASSERT(students.size() == 2, "StudentList size is incorrect");
    ASSERT(students[0] == "Alice", "First student is incorrect");
    ASSERT(students[1] == "Charlie", "Second student is incorrect");

    auto& staffList = StaffList::getInstance();
    const auto& staff = staffList.getList();
    ASSERT(staff.size() == 1, "StaffList size is incorrect");
    ASSERT(staff[0] == "Prof. Johnson", "First staff member is incorrect");

    auto& courseList = CourseList::getInstance();
    const auto& courses = courseList.getList();
    ASSERT(courses.size() == 1, "CourseList size is incorrect");
    ASSERT(courses[0] == "Physics 202", "First course is incorrect");

    auto& roomList = RoomList::getInstance();
    const auto& rooms = roomList.getList();
    ASSERT(rooms.size() == 1, "RoomList size is incorrect");
    ASSERT(rooms[0] == "Room B", "First room is incorrect");
}

void testOperatorMethod() {
    auto& studentList = StudentList::getInstance();
    ASSERT(studentList[0] == "Alice", "First student is incorrect");
    ASSERT(studentList[1] == "Charlie", "Second student is incorrect");
    try {
        studentList[2]; // This should throw an exception
        ASSERT(false, "Exception not thrown for out-of-range index");
    } catch (const std::out_of_range& e) {
        ASSERT(true, "Exception caught as expected");
    }

    auto& staffList = StaffList::getInstance();
    ASSERT(staffList[0] == "Prof. Johnson", "First staff member is incorrect");
    try {
        staffList[1]; // This should throw an exception
        ASSERT(false, "Exception not thrown for out-of-range index");
    } catch (const std::out_of_range& e) {
        ASSERT(true, "Exception caught as expected");
    }

    auto& courseList = CourseList::getInstance();
    ASSERT(courseList[0] == "Physics 202", "First course is incorrect");
    try {
        courseList[1]; // This should throw an exception
        ASSERT(false, "Exception not thrown for out-of-range index");
    } catch (const std::out_of_range& e) {
        ASSERT(true, "Exception caught as expected");
    }

    auto& roomList = RoomList::getInstance();
    ASSERT(roomList[0] == "Room B", "First room is incorrect");
    try {
        roomList[1]; // This should throw an exception
        ASSERT(false, "Exception not thrown for out-of-range index");
    } catch (const std::out_of_range& e) {
        ASSERT(true, "Exception caught as expected");
    }
}

int main() {
    testSingletonInstance();
    testAddMethod();
    testRemoveMethod();
    testGetListMethod();
    testOperatorMethod();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}


