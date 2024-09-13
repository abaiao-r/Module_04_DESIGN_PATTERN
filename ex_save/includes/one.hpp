/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:11:47 by abaiao-r          #+#    #+#             */
/*   Updated: 2024/09/13 19:26:06 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
#include <cassert>
#include <string>
#include <algorithm>  // For std::remove

// Forward declarations
class Person;
class Headmaster;
class Staff;
class Course;
class Classroom;
class Room;
class Form;
class Secretary;
class Professor;
class Student;
class IMediator;

// Enums
enum class FormType
{
    CourseFinished,
    NeedMoreClassRoom,
    NeedCourseCreation,
    SubscriptionToCourse
};

enum class Event
{
    RingBell
};

// Interfaces
class IMediator
{
public:
    virtual ~IMediator() = default;
    virtual void notify(Person &sender, const std::string &event, const std::string &target) = 0;
};

// Base Classes
class Person
{
private:
    std::string _name;
    Room* _currentRoom;

public:
    explicit Person(const std::string &personName);
    virtual ~Person();

    // Getters
    Room* room() const;
    const std::string &name() const;

    // Setters
    void setRoom(Room* room);
};

// Overload the `operator<<` for `FormType`
inline std::ostream& operator<<(std::ostream& os, const FormType& formType) {
    switch (formType) {
        case FormType::NeedCourseCreation:
            os << "NeedCourseCreation";
            break;
        case FormType::CourseFinished:
            os << "CourseFinished";
            break;
        case FormType::NeedMoreClassRoom:
            os << "NeedMoreClassRoom";
            break;
        case FormType::SubscriptionToCourse:
            os << "SubscriptionToCourse";
            break;
        default:
            os << "Unknown FormType";
            break;
    }
    return os;
}


class Form
{
protected:
    FormType _formType;
    bool _isSigned;
    std::string _target;
    std::string _sender;

public:
    explicit Form(FormType formType);
    explicit Form(FormType formType, const std::string &target);
    virtual ~Form();

    // Pure virtual method
    virtual void execute() = 0;

    // Methods
    void signForm();
    bool isSigned() const;
    FormType getFormType() const;
    std::string getTarget() const;
    std::string getSender() const;
};

class Staff : public Person
{
public:
    explicit Staff(const std::string &staffName);
    virtual ~Staff();

    // Methods
    void sign(Form* form);
};

// Derived Classes

class Course
{
private:
    std::string _courseName;
    Professor* _responsableProfessor;
    std::vector<Student*> _students;
    //student attendance times map
    std::map<Student *, int> _attendanceTimes;
    int _numberOfClassToGraduate;
    int _maximumNumberOfStudent;
    Headmaster *_mediator;

public:
    explicit Course(const std::string &courseName);
    virtual ~Course();

    // Setters
    void setNumberOfClassToGraduate(int numberOfClassToGraduate);
    void setMaximumNumberOfStudent(int maximumNumberOfStudent);

    // Getters
    std::string getCourseName() const;
    Professor* getResponsableProfessor() const;
    std::vector<Student*> getStudents() const;
    int getNumberOfClassToGraduate() const;
    int getMaximumNumberOfStudent() const;

    //setter
    void setAttendanceTimes(Student *student);

    // Methods
    void assignProfessor(Professor* professor);
    void subscribeStudent(Student* student);
    void setMediator(Headmaster* mediator);
    void unsubscribeStudent(Student* student);

    // check if student attendace is enough to graduate
    bool canGraduate(Student* student);

    // Find a specific student in the subscribed students
    Student* findStudent(const std::string &studentName) const;
};

class Room
{
private:
    long long _id;
    std::vector<Person*> _occupants;
    static long long ID;
    Headmaster *_mediator;

public:
    Room();
    virtual ~Room();

    // Methods
    bool canEnter(const Person* person) const;
    void enter(Person* person);
    void exit(Person* person);
    void printOccupants() const;

    // check if person is in the room
    bool isOccupant(Person* person) const;

    // Setters
    void setMediator(Headmaster* mediator);

    // Getters
    long long getId() const;
    std::vector<Person*> getOccupants() const;
};

class Secretary : public Staff
{
private:
    Headmaster* _mediator;
    template <typename T>
    T* createAndReceiveForm();
    template <typename T>
    T* createAndReceiveForm(const std::string &target);

public:
    explicit Secretary(const std::string &staffName);
    virtual ~Secretary();

    // Methods
    Form* createForm(FormType formType);
    Form* createForm(FormType formType, const std::string &target);

    void setMediator(Headmaster* mediator);
};

class Professor : public Staff
{
private:
    Course* _currentCourse;
    Headmaster *_mediator;

public:
    explicit Professor(const std::string &staffName);
    virtual ~Professor();

    void assignCourse(Course* course);
    void doClass();
    void closeCourse();

    void requestCourseCreation(const std::string &courseName);
    void setMediator(Headmaster* mediator);
    void requestGraduation(const std::string &studentName);
    void requestMoreClassRoom(const std::string &courseName);

    // Getters
    Course* getCurrentCourse() const;
};

class Student : public Person
{
private:
    std::vector<Course*> _subscribedCourse;
    Headmaster *_mediator;

public:
    explicit Student(const std::string &studentName);
    virtual ~Student();

    // Methods
    void attendClass(Classroom* classroom);
    void exitClass();
    void graduate(Course* course);
    void requestToSubscribeToCourse(const std::string &courseName);
    void lookForCourseToSubscribe();

    // Setters
    void setSubscribedCourse(Course* course);
    void setMediator(Headmaster* mediator);

    // Getters
    std::vector<Course*> getSubscribedCourse() const;

    // Find a specific course in the subscribed courses
    Course* findCourse(const std::string &courseName) const;

    // Remove a course from the subscribed courses
    void removeCourse(const std::string &courseName);
};

class Headmaster : public Staff, public IMediator
{
private:
    std::vector<Form*> _formToValidate;
    std::vector<Professor*> _professors;
    Secretary *_secretary;
    std::vector<Student*> _students;
    std::vector<Course*> _courses;
    std::vector<Room*> _rooms;

public:
    Headmaster();
    virtual ~Headmaster();

    void addProfessor(Professor *professor);
    void setSecretary(Secretary *secretary);
    void addStudent(Student *student);
    void addCourse(Course *course);
    void addRoom(Room *room);
    void notify(Person &sender, const std::string &event, const std::string &target) override;

    // Getters
    std::vector<Form*> getFormToValidate() const;
    std::vector<Professor*> getProfessors() const;
    Secretary* getSecretary() const;
    std::vector<Student*> getStudents() const;
    std::vector<Course*> getCourses() const;
    std::vector<Room*> getRooms() const;

    // Find specific course
    Course* findCourse(const std::string &courseName);



    // Methods
    void receiveForm(Form* p_form);
    void signForm(Form* p_form);
    void executeForm(Form* p_form);
    void goTeachCourse(Professor* p_professor);
    void goAttendClass(Student* p_student, Classroom* p_classroom);
    //make all students enter the room
    void makeStudentsEnterRoom(Classroom* p_classroom);

};

class Classroom : public Room
{
private:
    Course *_currentRoom;

public:
    Classroom();
    virtual ~Classroom();

    // Methods
    void assignCourse(Course* p_course);
};

// Form Classes

class CourseFinishedForm : public Form
{
private:
    std::string _courseName;

public:
    CourseFinishedForm();
    CourseFinishedForm(const std::string &target);
    virtual ~CourseFinishedForm();

    void execute();
    void setCourseName(const std::string &courseName);
};

class NeedMoreClassRoomForm : public Form
{
public:
    NeedMoreClassRoomForm();
    NeedMoreClassRoomForm(const std::string &target);
    virtual ~NeedMoreClassRoomForm();

    void execute();
};

class NeedCourseCreationForm : public Form
{
public:
    NeedCourseCreationForm();
    NeedCourseCreationForm(const std::string &target);
    virtual ~NeedCourseCreationForm();

    void execute();
};

class SubscriptionToCourseForm : public Form
{
public:
    SubscriptionToCourseForm();
    SubscriptionToCourseForm(const std::string &target);
    virtual ~SubscriptionToCourseForm();

    void execute();
};

// Additional Room Classes

class Courtyard : public Room
{
public:
    Courtyard();
    virtual ~Courtyard();
};

class StaffRestRoom : public Room
{
public:
    StaffRestRoom();
    virtual ~StaffRestRoom();
};

class SecretarialOffice : public Room
{
private:
    std::vector<Form*> _archivedForms;

public:
    SecretarialOffice();
    virtual ~SecretarialOffice();
};

class HeadmasterOffice : public Room
{
public:
    HeadmasterOffice();
    virtual ~HeadmasterOffice();
};

// Singleton Template Class
template <typename T, typename Tag>
class Singleton 
{
private:
    std::vector<T> _list; // List to hold items

protected:
    Singleton() = default; // Private constructor

public:
    // Delete copy constructor and assignment operator
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton&) = delete;

    // Static method to access the singleton instance
    static Singleton &getInstance() 
    {
        static Singleton instance; // Guaranteed to be destroyed and instantiated on first use
        return instance;
    }

    void add(const T &item)
    {
        _list.push_back(item);
    }

    void remove(const T &item) 
    {
        _list.erase(std::remove(_list.begin(), _list.end(), item), _list.end());
    }

    const std::vector<T> &getList() const
    {
        return _list;
    }

    T operator[](int index) const
    {
        if (index < 0 || index >= static_cast<int>(_list.size()))
        {
            throw std::out_of_range("Index out of range");
        }
        return _list[index];
    }
};
