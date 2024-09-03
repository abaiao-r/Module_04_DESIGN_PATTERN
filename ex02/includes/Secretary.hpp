/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Secretary.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:51:01 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 15:38:53 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include "Staff.hpp"
#include "Form.hpp"
#include "CourseFinishedForm.hpp"
#include "NeedCourseCreationForm.hpp"
#include "NeedMoreClassRoomForm.hpp"
#include "CourseFinishedForm.hpp"
#include "SubscriptionToCourseForm.hpp"

class Form;

class Secretary : public Staff
{
    public:
        explicit Secretary(const std::string &staffName);
        Secretary(const Secretary &src);
        Secretary &operator=(const Secretary &src);
        virtual ~Secretary();

        //Methods
        std::shared_ptr<Form> createForm(FormType formType);
};
