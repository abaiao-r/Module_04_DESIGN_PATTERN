/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Secretary.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:54:02 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/13 18:15:55 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/one.hpp"

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

template <typename T>
T* Secretary::createAndReceiveForm(const std::string &target)
{
    if (!_mediator)
        return nullptr;
    T* form = new T(target);
    _mediator->receiveForm(form); // Requires full type
    return form;
}

