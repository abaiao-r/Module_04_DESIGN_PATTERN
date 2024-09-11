/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedCourseCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:37:36 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/11 17:02:55 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include "Course.hpp"

class NeedCourseCreationForm : public Form
{
    public:
        NeedCourseCreationForm();
        NeedCourseCreationForm(const std::string &target);
        virtual ~NeedCourseCreationForm();

        void execute();
};