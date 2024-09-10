/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedCourseCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:37:36 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/10 16:41:39 by abaiao-r         ###   ########.fr       */
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