/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:44:35 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/04 12:10:52 by andrefranci      ###   ########.fr       */
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

        //Pure virtual method
        virtual void execute() = 0;

        //New methods
        void signForm();
        bool isSigned() const;
        FormType getFormType() const;
};
