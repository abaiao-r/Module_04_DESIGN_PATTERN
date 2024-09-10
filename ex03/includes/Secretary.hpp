/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Secretary.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:51:01 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/09 19:34:05 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        
    public:
        explicit Secretary(const std::string &staffName);
        virtual ~Secretary();

        //Methods
        Form* createForm(FormType formType);

        void setMediator(Headmaster* mediator);

};
