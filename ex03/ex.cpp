
#pragma once
#include "Form.hpp"
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
#include "Room.hpp"
class Courtyard : public Room
{
    private:
    public:
        Courtyard();
        virtual ~Courtyard();
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
inline std::string toString(FormType formType) {
    switch (formType) {
        case FormType::CourseFinished:
            return "CourseFinished";
        case FormType::NeedMoreClassRoom:
            return "NeedMoreClassRoom";
        case FormType::NeedCourseCreation:
            return "NeedCourseCreation";
        case FormType::SubscriptionToCourse:
            return "SubscriptionToCourse";
        default:
            return "UnknownFormType";
    }
}
inline std::ostream& operator<<(std::ostream& os, FormType formType) {
    os << toString(formType);
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
        explicit Form(FormType formType, const std::string &target, const std::string &sender);
        virtual ~Form();
        virtual void execute() = 0;
        void signForm();
        bool isSigned() const;
        FormType getFormType() const;
        std::string getTarget() const;
        std::string getSender() const;
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
#include "Form.hpp"
#include "Course.hpp"
class SubscriptionToCourseForm : public Form
{
    public:
        SubscriptionToCourseForm();
        SubscriptionToCourseForm(const std::string &target);
        virtual ~SubscriptionToCourseForm();
        void execute();
};



#pragma once
#include "Staff.hpp"
#include "Headmaster.hpp"
#include "Form.hpp"
#include "CourseFinishedForm.hpp"
#include "NeedCourseCreationForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "CourseFinishedForm.hpp"
#include "SubscriptionToCourseForm.hpp"
class Form;
class Headmaster;
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
        Form* createForm(FormType formType);
        Form *createForm(FormType formType, const std::string &target);
        void setMediator(Headmaster* mediator);
};



#pragma once
#include "Staff.hpp"
#include "Course.hpp"
#include <iostream>
#include "Headmaster.hpp"
class Course;
class Headmaster;
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
    };


#pragma once
#include "Person.hpp"
#include "Headmaster.hpp"
#include "Course.hpp"
#include "Classroom.hpp"
#include <iostream>
#include <vector>
class Course;
class Classroom;
class Headmaster;
class Student : public Person
{
    private:
        std::vector<Course*> _subscribedCourse;
        Headmaster *_mediator;
    public:
        explicit Student(const std::string &studentName);
        virtual ~Student();
        void attendClass(Classroom* classroom);
        void exitClass();
        void graduate(Course* course);
        void requestToSubscribeToCourse(const std::string &courseName);
        void setMediator(Headmaster* mediator);
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
#include "Form.hpp"
class NeedMoreClassRoomForm : public Form
{
    public:
        NeedMoreClassRoomForm();
        NeedMoreClassRoomForm(const std::string &target);
        virtual ~NeedMoreClassRoomForm();
        void execute();
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
#include <iostream>
#include <vector>
#include "Staff.hpp"
#include "Form.hpp"
#include "IMediator.hpp"
#include "Professor.hpp"
#include "Student.hpp"
#include "Secretary.hpp"
#include "Course.hpp"
class Secretary;
class Course;
class Professor;
class Student;
class Headmaster : public Staff, public IMediator
{
    private:
        std::vector<Form*> _formToValidate;
        std::vector<Professor*> _professors;
        Secretary *_secretary;
        std::vector<Student*> _students;
        std::vector<Course*> _courses;
    public:
        Headmaster();
        virtual ~Headmaster();
        void addProfessor(Professor *professor);
        void setSecretary(Secretary *secretary);
        void addStudent(Student *student);
        void addCourse(Course *course);
        void notify(const std::string &sender, const std::string &event) override;
        void notify(const std::string &sender, const std::string &event, const std::string &target) override;
        template <typename T>
        void notify(T *sender, const std::string &event, const std::string &target)
        {
            std::string senderType = typeid(*sender).name();
            if (senderType == "Professor")
            {
                if (event == "CourseFinished")
                {
                    std::cout << "Headmaster: Notifying Secretary to create a graduation form.\n";
                    _secretary->createForm(FormType::CourseFinished, target);
                }
                else if (event == "NeedsMoreClasses")
                {
                    std::cout << "Headmaster: Notifying Secretary to create a form for more classes.\n";
                    _secretary->createForm(FormType::NeedMoreClassRoom, target);
                }
                else if (event == "CreateCourse")
                {
                    std::cout << "Headmaster: Notifying Secretary to create a course creation form.\n";
                    Form *type = _secretary->createForm(FormType::NeedCourseCreation, target);
                    if (type)
                    {
                        signForm(type);
                        executeForm(type);
                        Course *course = new Course(target);
                        course->setMediator(this);
                        addCourse(course);
                        course->assignProfessor(static_cast<Professor*>(sender));
                    }
                }
            }
            else if (senderType == "Student")
            {
                if (event == "RequestCourseSubscription")
                {
                    std::cout << "Headmaster: Notifying Secretary to create a subscription form.\n";
                    Form *type = _secretary->createForm(FormType::SubscriptionToCourse, target);
                    if (type)
                    {
                        for (std::vector<Course*>::iterator it = _courses.begin(); it != _courses.end(); ++it)
                        {
                            if ((*it)->getCourseName() == target)
                            {
                                (*it)->subscribeStudent(static_cast<Student*>(sender));
                            }
                            else
                            {
                                std::cout << "Course not found. Cannot assign student.\n";
                            }
                        }
                }
            }
        }
    }
        void receiveForm(Form* p_form);
        void signForm(Form* p_form);
        void executeForm(Form* p_form);
        void goTeachCourse(const std::string &Professor);
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
#include <string>
#include <iostream>
class IMediator
{
    public:
        virtual ~IMediator() = default;
        virtual void notify(const std::string &sender, const std::string &event) = 0;
        virtual void notify(const std::string &sender, const std::string &event, const std::string &target) = 0;
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
enum class Event
{
    RingBell
};



#pragma once
#include "Form.hpp"
#include "Course.hpp"
class NeedCourseCreationForm : public Form
{
    public:
        NeedCourseCreationForm();
        NeedCourseCreationForm(const std::string &target);
        virtual ~NeedCourseCreationForm();
        void execute();
};


#pragma once
#include <string>
#include <vector>
#include "Professor.hpp"
#include "Student.hpp"
#include "Headmaster.hpp"
class Professor;
class Student;
class Headmaster;
class Course
{
    private:
        std::string _courseName;
        Professor* _responsableProfessor;
        std::vector<Student*> _students;
        int _numberOfClassToGraduate;
        int _maximumNumberOfStudent;
        Headmaster *_mediator;
    public:
        explicit Course(const std::string &courseName);
        virtual ~Course();
        void setNumberOfClassToGraduate(int numberOfClassToGraduate);
        void setMaximumNumberOfStudent(int maximumNumberOfStudent);
        void assignProfessor(Professor* professor);
        void subscribeStudent(Student* student);
        void setMediator(Headmaster* mediator);
        std::string getCourseName() const;
};



#include "../includes/Headmaster.hpp"
Headmaster::Headmaster() : Staff("Headmaster"), _formToValidate(), _professors(), _secretary(nullptr), _students(), 
{
}
Headmaster::~Headmaster()
{
}
void Headmaster::receiveForm(Form* p_form) 
{
    std::cout << "Headmaster received form of type: " << p_form->getFormType() << std::endl;
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
void Headmaster::addProfessor(Professor *professor)
{
    _professors.push_back(professor);
}
void Headmaster::setSecretary(Secretary *secretary)
{
    _secretary = secretary;
}
void Headmaster::addStudent(Student *student)
{
    _students.push_back(student);
}
void Headmaster::addCourse(Course *course)
{
    _courses.push_back(course);
}
void Headmaster::notify(const std::string &sender, const std::string &event)
{
    if (sender == "Professor" && event == "CourseFinished")
    {
        std::cout << "Headmaster: Notifying Secretary to create a graduation form.\n";
        _secretary->createForm(FormType::CourseFinished);
    }
    else if (sender == "Professor" && event == "NeedsMoreClasses")
    {
        std::cout << "Headmaster: Notifying Secretary to create a form for more classes.\n";
        _secretary->createForm(FormType::NeedMoreClassRoom);
    }
    else if (sender == "Student" && event == "RequestCourseSubscription")
    {
        std::cout << "Headmaster: Notifying Secretary to create a subscription form.\n";
        _secretary->createForm(FormType::SubscriptionToCourse);
    }
    else if (sender == "Professor" && event == "CreateCourse")
    {
        std::cout << "Headmaster: Notifying Secretary to create a course creation form.\n";
        _secretary->createForm(FormType::NeedCourseCreation);
    }
}
void Headmaster::notify(const std::string &sender, const std::string &event, const std::string &target)
{
    if (sender == "Professor" && event == "CourseFinished")
    {
        std::cout << "Headmaster: Notifying Secretary to create a graduation form.\n";
        _secretary->createForm(FormType::CourseFinished, target);
    }
    else if (sender == "Professor" && event == "NeedsMoreClasses")
    {
        std::cout << "Headmaster: Notifying Secretary to create a form for more classes.\n";
        _secretary->createForm(FormType::NeedMoreClassRoom, target);
    }
    else if (sender == "Student" && event == "RequestCourseSubscription")
    {
        std::cout << "Headmaster: Notifying Secretary to create a subscription form.\n";
        Form *type = _secretary->createForm(FormType::SubscriptionToCourse, target);
        if (type)
        {
            signForm(type);
            executeForm(type);
        }
    }
    else if (sender == "Professor" && event == "CreateCourse")
    {
        std::cout << "Headmaster: Notifying Secretary to create a course creation form.\n";
        Form *type = _secretary->createForm(FormType::NeedCourseCreation, target);
        std::cout << "Returning NeedCourseCreationForm to be filled by the professor.\n";
    }
}



#include "../includes/Form.hpp"
Form::Form(FormType formType) : _formType(formType), _isSigned(false), _target(""), _sender("")
{
}
Form::Form(FormType formType, const std::string &target, const std::string &sender) : _formType(formType), _isSigned(false), _target(target), _sender(sender)
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
std::string Form::getTarget() const
{
    return (this->_target);
}
std::string Form::getSender() const
{
    return (this->_sender);
}



#include "../includes/SecretarialOffice.hpp"
SecretarialOffice::SecretarialOffice() : Room()
{
}
SecretarialOffice::~SecretarialOffice()
{
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
void Course::setNumberOfClassToGraduate(int numberOfClassToGraduate)
{
    this->_numberOfClassToGraduate = numberOfClassToGraduate;
}
void Course::setMaximumNumberOfStudent(int maximumNumberOfStudent)
{
    this->_maximumNumberOfStudent = maximumNumberOfStudent;
}
void Course::setMediator(Headmaster* mediator)
{
    this->_mediator = mediator;
}
std::string Course::getCourseName() const
{
    return (this->_courseName);
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



#include "../includes/Student.hpp"
Student::Student(const std::string &studentName) : Person(studentName), _subscribedCourse(), _mediator(nullptr)
{
}
Student::~Student()
{
}
void Student::attendClass(Classroom* classroom)
{
    (void) classroom;
    std::cout << "Student attended class" << std::endl;
}
void Student::exitClass()
{
    std::cout << "Student exited class" << std::endl;
}
void Student::graduate(Course* course)
{
    (void) course;
    std::cout << "Student graduated" << std::endl;
}
void Student::requestToSubscribeToCourse(const std::string &course)
{
    (void) course;
    if (_mediator)
    {
        std::cout << "Student requests to subscribe to course" << std::endl;
        _mediator->notify("Student", "RequestCourseSubscription", course);
    }
}
void Student::setMediator(Headmaster* mediator)
{
    _mediator = mediator;
}



#include "../includes/Secretary.hpp"
#include "../includes/Headmaster.hpp"
Secretary::Secretary(const std::string &staffName) : Staff(staffName), _mediator(nullptr)
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
            return createAndReceiveForm<CourseFinishedForm>();
        case FormType::NeedMoreClassRoom:
            return createAndReceiveForm<NeedMoreClassRoomForm>();
        case FormType::NeedCourseCreation:
            return createAndReceiveForm<NeedCourseCreationForm>();
        case FormType::SubscriptionToCourse:
            return createAndReceiveForm<SubscriptionToCourseForm>();
        default:
            return nullptr;
    }
}
Form* Secretary::createForm(FormType formType, const std::string &target)
{
    switch (formType)
    {
        case FormType::CourseFinished:
            return createAndReceiveForm<CourseFinishedForm>(target);
        case FormType::NeedMoreClassRoom:
            return createAndReceiveForm<NeedMoreClassRoomForm>(target);
        case FormType::NeedCourseCreation:
            return createAndReceiveForm<NeedCourseCreationForm>(target);
        case FormType::SubscriptionToCourse:
            return createAndReceiveForm<SubscriptionToCourseForm>(target);
        default:
            return nullptr;
    }
}
void Secretary::setMediator(Headmaster* mediator)
{
    _mediator = mediator;
}
template <typename T>
T* Secretary::createAndReceiveForm()
{
    if (!_mediator)
        return nullptr;
    T* form = new T();
    _mediator->receiveForm(form); 
    return form;
}
template <typename T>
T* Secretary::createAndReceiveForm(const std::string &target)
{
    if (!_mediator)
        return nullptr;
    T* form = new T(target);
    _mediator->receiveForm(form); 
    return form;
}



#include "../includes/CourseFinishedForm.hpp"
CourseFinishedForm::CourseFinishedForm() : Form(FormType::CourseFinished)
{
}
CourseFinishedForm::CourseFinishedForm(const std::string &target) : Form(FormType::CourseFinished, target)
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


#include "../includes/HeadmasterOffice.hpp"
HeadmasterOffice::HeadmasterOffice() : Room()
{
}
HeadmasterOffice::~HeadmasterOffice()
{
}



#include "../includes/SubscriptionToCourseForm.hpp"
SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse)
{
}
SubscriptionToCourseForm::SubscriptionToCourseForm(const std::string &target) : Form(FormType::SubscriptionToCourse, target)
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



#include "../includes/NeedCourseCreationForm.hpp"
NeedCourseCreationForm::NeedCourseCreationForm() : Form(FormType::NeedCourseCreation)
{
}
NeedCourseCreationForm::NeedCourseCreationForm(const std::string &target) : Form(FormType::NeedCourseCreation, target)
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



#include "../includes/StaffRestRoom.hpp"
StaffRestRoom::StaffRestRoom() : Room()
{
}
StaffRestRoom::~StaffRestRoom()
{
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



#include "../includes/NeedMoreClassRoomForm.hpp"
NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom)
{
}
NeedMoreClassRoomForm::NeedMoreClassRoomForm(const std::string &target) : Form(FormType::NeedMoreClassRoom, target)
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



#include "../includes/Professor.hpp"
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
    if (this->_currentCourse)
    {
       std::cout << "Professor gave class" << std::endl;
    }
    else
    {
        std::cout << "No course assigned" << std::endl;
    }
}
void Professor::closeCourse()
{
    this->_currentCourse = nullptr;
}
void Professor::requestCourseCreation(const std::string &courseName)
{
    if (this->_mediator)
    {
        std::cout << "Professor requests course creation" << std::endl;
        _mediator->notify("Professor", "CreateCourse", courseName);
    }
}
void Professor::setMediator(Headmaster* mediator)
{
    this->_mediator = mediator;
}
void Professor::requestGraduation(const std::string &studentName)
{
    (void) studentName;
    if (this->_mediator)
    {
        std::cout << "Professor requests graduation" << std::endl;
        _mediator->notify("Professor", "CourseFinished");
    }
}
void Professor::requestMoreClassRoom(const std::string &courseName)
{
    (void) courseName;
    if (this->_mediator)
    {
        std::cout << "Professor requests more classroom" << std::endl;
        _mediator->notify("Professor", "NeedsMoreClasses");
    }
}


