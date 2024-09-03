/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Secretary.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:54:02 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 16:50:05 by andrefranci      ###   ########.fr       */
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

std::shared_ptr<Form> Secretary::createForm(FormType formType)
{
    // Implement the createForm method here
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
