/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourseFinishedForm.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:45:44 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/11 17:02:58 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class CourseFinishedForm : public Form
{
    private:
        std::string _courseName;
        
    public:
        CourseFinishedForm();
        CourseFinishedForm(const std::string &target);
        virtual ~CourseFinishedForm();

        void execute();
        void setCourseName(const std::string &courseName);
};
