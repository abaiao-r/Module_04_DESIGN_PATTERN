/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Secretary.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:51:01 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/10 21:23:05 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Staff.hpp"

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

        //Methods
        Form* createForm(FormType formType);
        Form *createForm(FormType formType, const std::string &target);

        void setMediator(Headmaster* mediator);

};
