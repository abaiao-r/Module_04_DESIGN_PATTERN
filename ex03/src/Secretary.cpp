/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Secretary.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:54:02 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/09 19:55:51 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void Secretary::setMediator(Headmaster* mediator)
{
    // Implement the setMediator method here
    _mediator = mediator;
}

// Moved template method definition here
template <typename T>
T* Secretary::createAndReceiveForm()
{
    if (!_mediator)
        return nullptr;
    T* form = new T();
    _mediator->receiveForm(form); // Requires full type
    return form;
}