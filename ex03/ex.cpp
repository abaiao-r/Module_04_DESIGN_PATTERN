
#pragma once
#include <iostream>
#include <vector>
#include "Staff.hpp"
#include "Form.hpp"
class Headmaster : public Staff
{
    private:
        std::vector<Form*> _formToValidate;
    public:
        Headmaster();
        virtual ~Headmaster();
        void receiveForm(Form* p_form);
        void signForm(Form* p_form);
        void executeForm(Form* p_form);    
};


#pragma once
#include <string>
#include <vector>
#include "Professor.hpp"
#include "Student.hpp"
class Professor;
class Student;
class Course
{
    private:
        std::string _courseName;
        Professor* _responsableProfessor;
        std::vector<Student*> _students;
        int _numberOfClassToGraduate;
        int _maximumNumberOfStudent;
    public:
        explicit Course(const std::string &courseName);
        virtual ~Course();
        void assignProfessor(Professor* professor);
        void subscribeStudent(Student* student);
};



#pragma once
#include "Person.hpp"
#include "Form.hpp"
class Form;
class Staff : public Person
{
    public:
        explicit Staff(const std::string &staffName);
        virtual ~Staff();
        void sign(Form* form);
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
#include "Staff.hpp"
#include "Course.hpp"
class Course;
class Professor : public Staff
{
    private:
        Course* _currentCourse;
    public:
        explicit Professor(const std::string &staffName);
        virtual ~Professor();
        void assignCourse(Course* course);
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
class Form
{
    private:
        FormType _formType;
        bool _isSigned;
    public:
        explicit Form(FormType formType);
        virtual ~Form();
        virtual void execute() = 0;
        void signForm();
        bool isSigned() const;
        FormType getFormType() const;
};



#pragma once
#include <string>
#include "Room.hpp"
class Room;
class Person
{
    private:
        std::string _name;
        Room* _currentRoom;
    public:
        explicit Person(const std::string &personName); 
        virtual ~Person();
        Room* room() const;
        const std::string &name() const;
        void setRoom(Room* room);
};



#pragma once
#include "Room.hpp"
class StaffRestRoom : public Room
{
    private:
    public:
        StaffRestRoom();
        virtual ~StaffRestRoom();
};



#pragma once
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
        virtual ~Secretary();
        Form* createForm(FormType formType);
};



#pragma once
#include "Room.hpp"
#include "Course.hpp"
class Course;
class Classroom : public Room
{
    private:
        Course* _currentRoom;
    public:
        Classroom();
        virtual ~Classroom();
        void assignCourse(Course* p_course);
};


#pragma once
#include "Form.hpp"
class SubscriptionToCourseForm : public Form
{
    public:
        SubscriptionToCourseForm();
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
        virtual ~HeadmasterOffice();
};


#pragma once
#include "Form.hpp"
class NeedCourseCreationForm : public Form
{
    public:
        NeedCourseCreationForm();
        virtual ~NeedCourseCreationForm();
        void execute();
};


#pragma once
#include "Person.hpp"
#include "Course.hpp"
#include "Classroom.hpp"
#include <vector>
class Course;
class Classroom;
class Student : public Person
{
    private:
        std::vector<Course*> _subscribedCourse;
    public:
        explicit Student(const std::string &studentName);
        virtual ~Student();
        void attendClass(Classroom* classroom);
        void exitClass();
        void graduate(Course* course);
};



#pragma once
#include <vector>
#include "Room.hpp"
#include "Form.hpp"
class Form;
class SecretarialOffice : public Room
{
    private:
        std::vector<Form*> _archivedForms;
    public:
        SecretarialOffice();
        virtual ~SecretarialOffice();
};



#pragma once
#include <vector>
#include <iostream>
#include "Person.hpp"
class Person;
class Room
{
    private:
        long long _id;
        std::vector<Person*> _occupants;
        static long long ID;
    public:
        Room();
        virtual ~Room();
        bool canEnter(const Person* person) const;
        void enter(Person* person);
        void exit(Person* person);
        void printOccupants() const;
};



#pragma once
#include "Room.hpp"
class Courtyard : public Room
{
    private:
    public:
        Courtyard();
        virtual ~Courtyard();
};



#pragma once
#include "Form.hpp"
class NeedMoreClassRoomForm : public Form
{
    public:
        NeedMoreClassRoomForm();
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
        virtual ~CourseFinishedForm();
        void execute();
        void setCourseName(const std::string &courseName);
};



#include "../includes/CourseFinishedForm.hpp"
CourseFinishedForm::CourseFinishedForm() : Form(FormType::CourseFinished)
{
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
Classroom::~Classroom()
{
}
void Classroom::assignCourse(Course* p_course)
{
    this->_currentRoom = p_course;
}



#include "../includes/Courtyard.hpp"
Courtyard::Courtyard() : Room()
{
}
Courtyard::~Courtyard()
{
}



#include "../includes/Room.hpp"
long long Room::ID = 0;
Room::Room()
{
    this->_id = Room::ID++;
    this->_occupants = std::vector<Person*>();
}
Room::~Room()
{
}
bool Room::canEnter(const Person* person) const
{
    (void)person;
    return (true);
}
void Room::enter(Person* person)
{
    if (!this->canEnter(person))
    {
        return;
    }
    this->_occupants.push_back(person);
}
void Room::exit(Person* person)
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
Headmaster::~Headmaster()
{
}
void Headmaster::receiveForm(Form* p_form)
{
    _formToValidate.push_back(p_form);
}
void Headmaster::signForm(Form* p_form)
{
    for (std::vector<Form*>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it)
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
void Headmaster::executeForm(Form* p_form)
{
    for (std::vector<Form*>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it)
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
StaffRestRoom::~StaffRestRoom()
{
}



#include "../includes/Form.hpp"
Form::Form(FormType formType) : _formType(formType), _isSigned(false)
{
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
HeadmasterOffice::~HeadmasterOffice()
{
}



#include "../includes/SecretarialOffice.hpp"
SecretarialOffice::SecretarialOffice() : Room()
{
}
SecretarialOffice::~SecretarialOffice()
{
}



#include "../includes/Staff.hpp"
Staff::Staff(const std::string &staffName) : Person(staffName)
{
}
Staff::~Staff()
{
}
void Staff::sign(Form* form)
{
    form->signForm();
}



#include "../includes/Secretary.hpp"
Secretary::Secretary(const std::string &staffName) : Staff(staffName)
{
}
Secretary::~Secretary()
{
}
Form* Secretary::createForm(FormType formType)
{
    switch (formType)
    {
        case FormType::CourseFinished:
            return new CourseFinishedForm();
        case FormType::NeedMoreClassRoom:
            return new NeedMoreClassRoomForm();
        case FormType::NeedCourseCreation:
            return new NeedCourseCreationForm();
        case FormType::SubscriptionToCourse:    
            return new SubscriptionToCourseForm();
        default:
            return nullptr;
    }
}


#include "../includes/Student.hpp"
Student::Student(const std::string &studentName) : Person(studentName), _subscribedCourse()
{
}
Student::~Student()
{
}
void Student::attendClass(Classroom* classroom)
{
    (void) classroom;
}
void Student::exitClass()
{
}
void Student::graduate(Course* course)
{
    (void) course;
}



#include "../includes/NeedMoreClassRoomForm.hpp"
NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom)
{
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
Person::~Person()
{
}
Room* Person::room() const
{
    return this->_currentRoom;
}
const std::string &Person::name() const
{
    return this->_name;
}
void Person::setRoom(Room* room)
{
    this->_currentRoom = room;
}


#include "../includes/Course.hpp"
Course::Course(const std::string &courseName) : _courseName(courseName), _responsableProfessor(nullptr), _students(), _numberOfClassToGraduate(0), _maximumNumberOfStudent(0)
{
}
Course::~Course()
{
}
void Course::assignProfessor(Professor* professor)
{
    this->_responsableProfessor = professor;
}
void Course::subscribeStudent(Student* student)
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
Professor::~Professor()
{
}
void Professor::assignCourse(Course* course)
{
    this->_currentCourse = course;
}
void Professor::doClass()
{
}
void Professor::closeCourse()
{
    this->_currentCourse = nullptr;
}


