/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:44:35 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/11 09:29:58 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

enum class FormType
{
    CourseFinished,
    NeedMoreClassRoom,
    NeedCourseCreation,
    SubscriptionToCourse
};

// Function to convert FormType to string
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

// Overload the << operator for FormType
// Overload the << operator for FormType
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
        explicit Form(FormType formType, const std::string &target);
        virtual ~Form();

        //Pure virtual method
        virtual void execute() = 0;

        //New methods
        void signForm();
        bool isSigned() const;
        FormType getFormType() const;
        std::string getTarget() const;
        std::string getSender() const;
};
