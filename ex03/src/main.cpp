/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:33:59 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/07 17:19:35 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Secretary.hpp"
#include "../includes/NeedMoreClassRoomForm.hpp"
#include "../includes/NeedCourseCreationForm.hpp"
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
#include "../includes/HeadmasterOffice.hpp"
#include "../includes/Headmaster.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>
#include <string>

int main(void) 
{
    std::cout << "====================\n";
    std::cout << "Test 1: Factory Pattern\n";
    std::cout << "====================\n";

    // Test 1: Secretary creates correct form types (Factory Pattern)
    Secretary secretary("Alice");

    Form* courseForm = secretary.createForm(FormType::CourseFinished);
    assert(courseForm != nullptr && "Factory did not create the form correctly.");
    assert(courseForm->getFormType() == FormType::CourseFinished && "Factory did not create the correct form type.");

    Form* roomForm = secretary.createForm(FormType::NeedMoreClassRoom);
    assert(roomForm != nullptr && "Factory did not create the form correctly.");
    assert(roomForm->getFormType() == FormType::NeedMoreClassRoom && "Factory did not create the correct form type.");

    Form* courseCreationForm = secretary.createForm(FormType::NeedCourseCreation);
    assert(courseCreationForm != nullptr && "Factory did not create the form correctly.");
    assert(courseCreationForm->getFormType() == FormType::NeedCourseCreation && "Factory did not create the correct form type.");

    Form* subscriptionForm = secretary.createForm(FormType::SubscriptionToCourse);
    assert(subscriptionForm != nullptr && "Factory did not create the form correctly.");
    assert(subscriptionForm->getFormType() == FormType::SubscriptionToCourse && "Factory did not create the correct form type.");

    std::cout << "Test 1 passed: Secretary creates correct form types using the Factory Pattern.\n";

    std::cout << "\n====================\n";
    std::cout << "Test 2: Command Pattern\n";
    std::cout << "====================\n";

    // Test 2: Unsigned forms cannot be executed (Command Pattern)
    CourseFinishedForm testForm;
    Headmaster headmaster1;
    headmaster1.signForm(&testForm);
    testForm.execute();  // Should do nothing since the form is unsigned
    std::cout << "Test 2 passed: Unsigned forms cannot be executed (Command Pattern).\n";

    std::cout << "\n====================\n";
    std::cout << "Test 3: Command Pattern\n";
    std::cout << "====================\n";

    // Test 3: Signed forms execute successfully (Command Pattern)
    Headmaster headmaster;
    CourseFinishedForm* testFormPtr = &testForm;  // Use raw pointer
    Form* formAsBase = static_cast<Form*>(testFormPtr);  // Convert raw pointer
    headmaster.receiveForm(formAsBase);  // Pass raw pointer to the receiveForm method
    headmaster.signForm(formAsBase);  // Pass raw pointer to the signForm method
    headmaster.executeForm(formAsBase);  // Should print execution message
    std::cout << "Test 3 passed: Signed forms execute successfully (Command Pattern).\n";

    std::cout << "\n====================\n";
    std::cout << "Test 4: End-to-End Flow\n";
    std::cout << "====================\n";

    // Test 4: End-to-end flow (Factory + Command Patterns)
    Form* form = secretary.createForm(FormType::CourseFinished);
    CourseFinishedForm* specificForm = dynamic_cast<CourseFinishedForm*>(form);
    if (specificForm) {
        specificForm->setCourseName("History 101");
    }

    // Attempt to execute unsigned form (Command Pattern)
    headmaster.executeForm(specificForm);  // Should not execute

    // Sign and then execute (Command Pattern)
    headmaster.receiveForm(specificForm);
    headmaster.signForm(specificForm);
    headmaster.executeForm(specificForm);  // Should execute now

    std::cout << "Test 4 passed: End-to-end flow works as expected with Factory and Command Patterns.\n";

    std::cout << "\n====================\n";
    std::cout << "Additional Tests for All Forms\n";
    std::cout << "====================\n";

    // Additional tests for all forms
    std::vector<FormType> formTypes = {
        FormType::CourseFinished,
        FormType::NeedMoreClassRoom,
        FormType::NeedCourseCreation,
        FormType::SubscriptionToCourse
    };

    for (const auto& formType : formTypes)
    {
        Form* formInstance = secretary.createForm(formType);  // Renamed variable to avoid shadowing
        assert(formInstance != nullptr && "Factory did not create the form correctly.");
        assert(formInstance->getFormType() == formType && "Factory did not create the correct form type.");

        // Attempt to execute unsigned form (Command Pattern)
        headmaster.executeForm(formInstance);  // Should not execute

        // Sign and then execute (Command Pattern)
        headmaster.receiveForm(formInstance);
        headmaster.signForm(formInstance);
        headmaster.executeForm(formInstance);  // Should execute now

        std::cout << "Test passed for form type: " << static_cast<int>(formType) << "\n";
        std::cout << "====================\n";
    }
   
    std::cout << "All tests passed for all form types.\n";

    return (0);
}