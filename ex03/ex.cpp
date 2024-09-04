











#pragma once

#include <memory>
#include <iostream>
#include <vector>

#include "Staff.hpp"
#include "Form.hpp"

class Headmaster : public Staff
{
    private:
        std::vector<std::shared_ptr<Form>> _formToValidate;

    public:
        Headmaster();
        Headmaster(const Headmaster &src);
        Headmaster &operator=(const Headmaster &src);
        virtual ~Headmaster();

        
        void receiveForm(std::shared_ptr<Form> p_form);
        void signForm(std::shared_ptr<Form> p_form);
        void executeForm(std::shared_ptr<Form> p_form);      
};














#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Professor.hpp"
#include "Student.hpp"

class Professor;
class Student;

class Course
{
    private:
        std::string _courseName;
        std::shared_ptr<Professor> _responsableProfessor;
        std::vector<std::shared_ptr<Student>> _students;
        int _numberOfClassToGraduate;
        int _maximumNumberOfStudent;

    public:
        explicit Course(const std::string &courseName);
        Course(const Course &src);
        Course &operator=(const Course &src);
        virtual ~Course();
        
        
        void assignProfessor(const std::shared_ptr<Professor> professor);
        void subscribeStudent(const std::shared_ptr<Student> student);
        
};















#pragma once

#include "Person.hpp"
#include "Form.hpp"

class Form;

class Staff : public Person
{
    public:
        explicit Staff(const std::string &staffName);
        Staff(const Staff &src);
        Staff &operator=(const Staff &src);
        virtual ~Staff();

        
        void sign(const std::shared_ptr<Form> &form);
};














#pragma once

#include <iostream>
#include <vector>
#include <algorithm> 
#include <stdexcept> 

template <typename T, typename Tag>
class Singleton 
{
    private:
        std::vector<T> _list; 
        
    protected:
        Singleton() = default; 

    public:
        
        Singleton(const Singleton &) = delete;
        Singleton &operator=(const Singleton&) = delete;

        
        static Singleton &getInstance() 
        {
            static Singleton instance; 
            return (instance);
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
            return (_list);
        }

        T operator[](int index) const
        {
            if (index < 0 || index >= (int)_list.size())
            {
                throw std::out_of_range("Index out of range");
            }
            return (_list[index]);
        }

};















#pragma once

#include <memory>
#include "Staff.hpp"
#include "Course.hpp"

class Course;

class Professor : public Staff
{
    private:
        std::shared_ptr<Course> _currentCourse;
    
    public:
        explicit Professor(const std::string &staffName);
        Professor(const Professor &src);
        Professor &operator=(const Professor &src);
        virtual ~Professor();

        void assignCourse(const std::shared_ptr<Course> course);
        void doClass();
        void closeCourse();
};














#pragma once

#include <iostream>

enum class FormType
{
    CourseFinished,
    NeedMoreClassRoom,
    NeedCourseCreation,
    SubscriptionToCourse
};


std::ostream& operator<<(std::ostream& os, const FormType& formType);

class Form
{
    private:
        FormType _formType;
        bool _isSigned;

    public:
        explicit Form(FormType formType);
        Form(const Form &src);
        Form &operator=(const Form &src);
        virtual ~Form();

        
        virtual void execute() = 0;

        
        void signForm();
        bool isSigned() const;
        FormType getFormType() const;
};














#pragma once

#include <string>
#include <memory>

#include "Room.hpp"

class Room;

class Person
{
    private:
        std::string _name;
        std::shared_ptr<Room> _currentRoom;
    
    public:
        explicit Person(const std::string &personName); 
        Person(const Person &src);
        Person &operator=(const Person &src);
        virtual ~Person();

        
        const std::shared_ptr<Room> &room() const;
        const std::string &name() const;

        
        void setRoom(const std::shared_ptr<Room> room);
};














#pragma once

#include "Room.hpp"

class StaffRestRoom : public Room
{
    private:
        
    public:
        StaffRestRoom();
        StaffRestRoom(const StaffRestRoom &src);
        StaffRestRoom &operator=(const StaffRestRoom &src);
        virtual ~StaffRestRoom();
};














#pragma once

#include <memory>
#include "Staff.hpp"
#include "Form.hpp"
#include "CourseFinishedForm.hpp"
#include "NeedCourseCreationForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "CourseFinishedForm.hpp"
#include "SubscriptionToCourseForm.hpp"

class Form;

class Secretary : public Staff
{
    public:
        explicit Secretary(const std::string &staffName);
        Secretary(const Secretary &src);
        Secretary &operator=(const Secretary &src);
        virtual ~Secretary();

        
        std::shared_ptr<Form> createForm(FormType formType);
};














#pragma once

#include "Room.hpp"
#include "Course.hpp"
#include <memory>

class Course;

class Classroom : public Room
{
    private:
        std::shared_ptr<Course> _currentRoom;

    public:
        Classroom();
        Classroom(const Classroom &src);
        Classroom &operator=(const Classroom &src);
        virtual ~Classroom();
        
        
        void assignCourse(std::shared_ptr<Course> p_course);
};














#pragma once

#include "Form.hpp"

class SubscriptionToCourseForm : public Form
{
    public:
        SubscriptionToCourseForm();
        SubscriptionToCourseForm(const SubscriptionToCourseForm &src);
        SubscriptionToCourseForm &operator=(const SubscriptionToCourseForm &src);
        virtual ~SubscriptionToCourseForm();

        void execute();
};














#pragma once

enum class Event
{
    RingBell
};















#pragma once


#include <memory>
#include <iostream>

#include "Room.hpp"
#include "Form.hpp"

class HeadmasterOffice : public Room
{
    private:
        
    public:
        HeadmasterOffice();
        HeadmasterOffice(const HeadmasterOffice &src);
        HeadmasterOffice &operator=(const HeadmasterOffice &src);
        virtual ~HeadmasterOffice();

};













#pragma once

#include "Form.hpp"

class NeedCourseCreationForm : public Form
{
    public:
        NeedCourseCreationForm();
        NeedCourseCreationForm(const NeedCourseCreationForm &src);
        NeedCourseCreationForm &operator=(const NeedCourseCreationForm &src);
        virtual ~NeedCourseCreationForm();

        void execute();
};













#pragma once

#include "Person.hpp"
#include "Course.hpp"
#include "Classroom.hpp"
#include <vector>
#include <memory>

class Course;
class Classroom;

class Student : public Person
{
    private:
        std::vector<std::shared_ptr<Course>> _subscribedCourse;

    public:
        explicit Student(const std::string &studentName);
        Student(const Student &src);
        Student &operator=(const Student &src);
        virtual ~Student();

        
        void attendClass(const std::shared_ptr<Classroom> classroom);
        void exitClass();
        void graduate(const std::shared_ptr<Course> course);
};













#pragma once

#include <vector>
#include <memory>

#include "Room.hpp"
#include "Form.hpp"

class Form;

class SecretarialOffice : public Room
{
    private:
        std::vector<std::shared_ptr<Form>> _archivedForms;
        
    public:
        SecretarialOffice();
        SecretarialOffice(const SecretarialOffice &src);
        SecretarialOffice &operator=(const SecretarialOffice &src);
        virtual ~SecretarialOffice();
};














#pragma once

#include <vector>
#include <memory>
#include <iostream>

#include "Person.hpp"

class Person;

class Room
{
    private:
        long long _id;
        std::vector<std::shared_ptr<Person>> _occupants;
        static long long ID;

    public:
        Room();
        Room(const Room &src);
        Room &operator=(const Room &src);
        virtual ~Room();

        
        bool canEnter(const std::shared_ptr<Person> person) const;
        void enter(const std::shared_ptr<Person> person);
        void exit(const std::shared_ptr<Person> person);
        void printOccupants() const;
};















#pragma once

#include "Room.hpp"

class Courtyard : public Room
{
    private:
        
    public:
        Courtyard();
        Courtyard(const Courtyard &src);
        Courtyard &operator=(const Courtyard &src);
        virtual ~Courtyard();
};














#pragma once

#include "Form.hpp"

class NeedMoreClassRoomForm : public Form
{
    public:
        NeedMoreClassRoomForm();
        NeedMoreClassRoomForm(const NeedMoreClassRoomForm &src);
        NeedMoreClassRoomForm &operator=(const NeedMoreClassRoomForm &src);
        virtual ~NeedMoreClassRoomForm();

        void execute();
};














#pragma once

#include "Form.hpp"

class CourseFinishedForm : public Form
{
    private:
        std::string _courseName;
        
    public:
        CourseFinishedForm();
        CourseFinishedForm(const CourseFinishedForm &src);
        CourseFinishedForm &operator=(const CourseFinishedForm &src);
        virtual ~CourseFinishedForm();

        void execute();
        void setCourseName(const std::string &courseName);
};














#include "../includes/CourseFinishedForm.hpp"

CourseFinishedForm::CourseFinishedForm() : Form(FormType::CourseFinished)
{
}

CourseFinishedForm::CourseFinishedForm(const CourseFinishedForm &src) : Form(src)
{
}

CourseFinishedForm &CourseFinishedForm::operator=(const CourseFinishedForm &src)
{
    if (this != &src)
    {
        Form::operator=(src);
    }
    return (*this);
}

CourseFinishedForm::~CourseFinishedForm()
{
}

void CourseFinishedForm::execute()
{
    
    if (this->isSigned())
    {
        std::cout << "Execute CourseFinishedForm for course " << this->_courseName << std::endl;
    }
    else
    {
        std::cout << "Form not signed yet. Cannot execute." << std::endl;
    }
}

void CourseFinishedForm::setCourseName(const std::string &courseName)
{
    this->_courseName = courseName;
}













#include "../includes/Classroom.hpp"

Classroom::Classroom() : Room(), _currentRoom(nullptr)
{
}

Classroom::Classroom(const Classroom &src) : Room(src), _currentRoom(src._currentRoom)
{
}

Classroom &Classroom::operator=(const Classroom &src)
{
    if (this != &src)
    {
        this->_currentRoom = src._currentRoom;
    }
    return (*this);
}

Classroom::~Classroom()
{
}

void Classroom::assignCourse(std::shared_ptr<Course> p_course)
{
    this->_currentRoom = p_course;
}















#include "../includes/Courtyard.hpp"

Courtyard::Courtyard() : Room()
{
}

Courtyard::Courtyard(const Courtyard &src) : Room(src)
{
}

Courtyard &Courtyard::operator=(const Courtyard &src)
{
    if (this != &src)
    {
        Room::operator=(src);
    }
    return (*this);
}

Courtyard::~Courtyard()
{
}














#include "../includes/Room.hpp"

long long Room::ID = 0;

Room::Room()
{
    this->_id = Room::ID++;
    this->_occupants = std::vector<std::shared_ptr<Person>>();
}

Room::Room(const Room &src) : _id(Room::ID++)
{
    this->_occupants = src._occupants;
}

Room &Room::operator=(const Room &src)
{
    if (this != &src)
    {
        this->_id = Room::ID++;
        this->_occupants = src._occupants;
    }
    return (*this);
}

Room::~Room()
{
}

bool Room::canEnter(const std::shared_ptr<Person> person) const
{
    
    (void)person;
    return (true);
}

void Room::enter(const std::shared_ptr<Person> person)
{
    
    if (!this->canEnter(person))
    {
        return;
    }
    
    this->_occupants.push_back(person);
}

void Room::exit(const std::shared_ptr<Person> person)
{
    
    for (auto it = this->_occupants.begin(); it != this->_occupants.end(); it++)
    {
        if (*it == person)
        {
            this->_occupants.erase(it);
            break;
        }
    }
}

void Room::printOccupants() const
{
    std::cout << "Occupants of the room " << this->_id << ":" << std::endl;
    
    for (auto it = this->_occupants.begin(); it != this->_occupants.end(); it++)
    {
        std::cout << (*it)->name() << std::endl;
    }
}















#include "../includes/Headmaster.hpp"

Headmaster::Headmaster() : Staff("Headmaster")
{
}

Headmaster::Headmaster(const Headmaster &src) : Staff(src)
{
}

Headmaster &Headmaster::operator=(const Headmaster &src)
{
    if (this != &src)
    {
        Staff::operator=(src);
    }
    return (*this);
}

Headmaster::~Headmaster()
{
}

void Headmaster::receiveForm(std::shared_ptr<Form> p_form)
{
    _formToValidate.push_back(p_form);
}

void Headmaster::signForm(std::shared_ptr<Form> p_form)
{

    
    for (std::vector<std::shared_ptr<Form>>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it)
    {
        if ((*it)->getFormType() == p_form->getFormType())
        {
            (*it)->signForm();
            std::cout << "Headmaster signs form" << std::endl;
            return;
        }
    }
    std::cout << "Form not found in the list. Cannot sign." << std::endl;
}

void Headmaster::executeForm(std::shared_ptr<Form> p_form)
{
   
    for (std::vector<std::shared_ptr<Form>>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it)
    {
        if ((*it)->getFormType() == p_form->getFormType())
        {
            if ((*it)->isSigned())
            {
                p_form->execute();
                
                _formToValidate.erase(it);
                return;
            }
            else
            {
                std::cout << "Form not signed yet. Cannot execute." << std::endl;
                return;
            }
        }
    }
    std::cout << "Form not found in the list. Cannot execute." << std::endl;
}













#include "../includes/StaffRestRoom.hpp"

StaffRestRoom::StaffRestRoom() : Room()
{
}

StaffRestRoom::StaffRestRoom(const StaffRestRoom &src) : Room(src)
{
}

StaffRestRoom &StaffRestRoom::operator=(const StaffRestRoom &src)
{
    if (this != &src)
    {
        Room::operator=(src);
    }
    return (*this);
}

StaffRestRoom::~StaffRestRoom()
{
}














#include "../includes/Form.hpp"

Form::Form(FormType formType) : _formType(formType), _isSigned(false)
{
}

Form::Form(const Form &src) : _formType(src._formType), _isSigned(src._isSigned)
{
}

Form &Form::operator=(const Form &src)
{
    if (this != &src)
    {
        this->_formType = src._formType;
        this->_isSigned = src._isSigned;
    }
    return (*this);
}

Form::~Form()
{
}


void Form::signForm()
{
    this->_isSigned = true;
}

bool Form::isSigned() const
{
    return (this->_isSigned);
}

FormType Form::getFormType() const
{
    return (this->_formType);
}














#include "../includes/HeadmasterOffice.hpp"

HeadmasterOffice::HeadmasterOffice() : Room()
{
}

HeadmasterOffice::HeadmasterOffice(const HeadmasterOffice &src) : Room(src)
{
}

HeadmasterOffice &HeadmasterOffice::operator=(const HeadmasterOffice &src)
{
    if (this != &src)
    {
        Room::operator=(src);
    }
    return (*this);
}

HeadmasterOffice::~HeadmasterOffice()
{
}














#include "../includes/SecretarialOffice.hpp"

SecretarialOffice::SecretarialOffice() : Room()
{
}

SecretarialOffice::SecretarialOffice(const SecretarialOffice &src) : Room(src)
{
}

SecretarialOffice &SecretarialOffice::operator=(const SecretarialOffice &src)
{
    if (this != &src)
    {
        Room::operator=(src);
    }
    return (*this);
}

SecretarialOffice::~SecretarialOffice()
{
}














#include "../includes/Staff.hpp"

Staff::Staff(const std::string &staffName) : Person(staffName)
{
}

Staff::Staff(const Staff &src) : Person(src)
{
}

Staff &Staff::operator=(const Staff &src)
{
    if (this != &src)
    {
        Person::operator=(src);
    }
    return (*this);
}

Staff::~Staff()
{
}

void Staff::sign(const std::shared_ptr<Form> &form)
{
    
    form->signForm();
}















#include "../includes/Secretary.hpp"

Secretary::Secretary(const std::string &staffName) : Staff(staffName)
{
}

Secretary::Secretary(const Secretary &src) : Staff(src)
{
}

Secretary &Secretary::operator=(const Secretary &src)
{
    if (this != &src)
    {
        Staff::operator=(src);
    }
    return (*this);
}

Secretary::~Secretary()
{
}

std::shared_ptr<Form> Secretary::createForm(FormType formType)
{
    
    switch (formType)
    {
        case FormType::CourseFinished:
            return (std::make_shared<CourseFinishedForm>());
        case FormType::NeedMoreClassRoom:
            return (std::make_shared<NeedMoreClassRoomForm>());
        case FormType::NeedCourseCreation:
            return (std::make_shared<NeedCourseCreationForm>());
        case FormType::SubscriptionToCourse:    
            return (std::make_shared<SubscriptionToCourseForm>());
        default:
            return (nullptr);
    }
}














#include "../includes/Student.hpp"

Student::Student(const std::string &studentName) : Person(studentName), _subscribedCourse()
{
}

Student::Student(const Student &src) : Person(src), _subscribedCourse(src._subscribedCourse)
{
}

Student &Student::operator=(const Student &src)
{
    if (this != &src)
    {
        Person::operator=(src);
        this->_subscribedCourse = src._subscribedCourse;
    }
    return (*this);
}

Student::~Student()
{
}

void Student::attendClass(const std::shared_ptr<Classroom> classroom)
{
    
    
    (void) classroom;
}

void Student::exitClass()
{
    
}

void Student::graduate(const std::shared_ptr<Course> course)
{
    
    (void) course;
}














#include "../includes/NeedMoreClassRoomForm.hpp"

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom)
{
}

NeedMoreClassRoomForm::NeedMoreClassRoomForm(const NeedMoreClassRoomForm &src) : Form(src)
{
}

NeedMoreClassRoomForm &NeedMoreClassRoomForm::operator=(const NeedMoreClassRoomForm &src)
{
    if (this != &src)
    {
        Form::operator=(src);
    }
    return (*this);
}

NeedMoreClassRoomForm::~NeedMoreClassRoomForm()
{
}

void NeedMoreClassRoomForm::execute()
{
    
    if (this->isSigned())
    {
        std::cout << "Execute NeedMoreClassRoomForm" << std::endl;
    }
    else
    {
        std::cout << "Form not signed yet. Cannot execute." << std::endl;
    }
}














#include "../includes/SubscriptionToCourseForm.hpp"

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse)
{
}

SubscriptionToCourseForm::SubscriptionToCourseForm(const SubscriptionToCourseForm &src) : Form(src)
{
}

SubscriptionToCourseForm &SubscriptionToCourseForm::operator=(const SubscriptionToCourseForm &src)
{
    if (this != &src)
    {
        Form::operator=(src);
    }
    return (*this);
}

SubscriptionToCourseForm::~SubscriptionToCourseForm()
{
}

void SubscriptionToCourseForm::execute()
{
    
    if (this->isSigned())
    {
        std::cout << "Execute SubscriptionToCourseForm" << std::endl;
    }
    else
    {
        std::cout << "Form not signed yet. Cannot execute." << std::endl;
    }
}















#include "../includes/NeedCourseCreationForm.hpp"

NeedCourseCreationForm::NeedCourseCreationForm() : Form(FormType::NeedCourseCreation)
{
}

NeedCourseCreationForm::NeedCourseCreationForm(const NeedCourseCreationForm &src) : Form(src)
{
}

NeedCourseCreationForm &NeedCourseCreationForm::operator=(const NeedCourseCreationForm &src)
{
    if (this != &src)
    {
        Form::operator=(src);
    }
    return (*this);
}

NeedCourseCreationForm::~NeedCourseCreationForm()
{
}

void NeedCourseCreationForm::execute()
{
    
    if (this->isSigned())
    {
        std::cout << "Execute NeedCourseCreationForm" << std::endl;
    }
    else
    {
        std::cout << "Form not signed yet. Cannot execute." << std::endl;
    }
}















#include "../includes/Person.hpp"

Person::Person(const std::string &personName) : _name(personName), _currentRoom(nullptr)
{
}

Person::Person(const Person &src) : _name(src._name), _currentRoom(src._currentRoom)
{
}

Person &Person::operator=(const Person &src)
{
    if (this != &src)
    {
        this->_name = src._name;
        this->_currentRoom = src._currentRoom;
    }
    return (*this);
}

Person::~Person()
{
}

const std::shared_ptr<Room> &Person::room() const
{
    return (this->_currentRoom);
}

const std::string &Person::name() const
{
    return (this->_name);
}

void Person::setRoom(const std::shared_ptr<Room> room)
{
    this->_currentRoom = room;
}














#include "../includes/Course.hpp"

Course::Course(const std::string &courseName) : _courseName(courseName), _responsableProfessor(nullptr), _students(), _numberOfClassToGraduate(0), _maximumNumberOfStudent(0)
{
}

Course::Course(const Course &src) : _courseName(src._courseName), _responsableProfessor(src._responsableProfessor), _students(src._students), _numberOfClassToGraduate(src._numberOfClassToGraduate), _maximumNumberOfStudent(src._maximumNumberOfStudent)
{
}

Course &Course::operator=(const Course &src)
{
    if (this != &src)
    {
        this->_courseName = src._courseName;
        this->_responsableProfessor = src._responsableProfessor;
        this->_students = src._students;
        this->_numberOfClassToGraduate = src._numberOfClassToGraduate;
        this->_maximumNumberOfStudent = src._maximumNumberOfStudent;
    }
    return (*this);
}

Course::~Course()
{
}

void Course::assignProfessor(const std::shared_ptr<Professor> professor)
{
    this->_responsableProfessor = professor;
}

void Course::subscribeStudent(const std::shared_ptr<Student> student)
{
    if(this->_students.size() < (size_t)this->_maximumNumberOfStudent)
    {
        this->_students.push_back(student);
    }
    else
    {
        std::cout << "The course is full" << std::endl;
    }
}














#include "../includes/Professor.hpp"

Professor::Professor(const std::string &staffName) : Staff(staffName), _currentCourse(nullptr)
{
}

Professor::Professor(const Professor &src) : Staff(src), _currentCourse(src._currentCourse)
{
}

Professor &Professor::operator=(const Professor &src)
{
    if (this != &src)
    {
        Staff::operator=(src);
        this->_currentCourse = src._currentCourse;
    }
    return (*this);
}

Professor::~Professor()
{
}

void Professor::assignCourse(const std::shared_ptr<Course> course)
{
    this->_currentCourse = course;
}

void Professor::doClass()
{
    
    
}

void Professor::closeCourse()
{
    
}



