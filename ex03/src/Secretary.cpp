/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Secretary.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:54:02 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/07 17:15:05 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

Form* Secretary::createForm(FormType formType)
{
    // Implement the createForm method here
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