/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourseFinishedForm.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:45:44 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/07 17:01:26 by andrefranci      ###   ########.fr       */
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
        CourseFinishedForm(const CourseFinishedForm &src);
        CourseFinishedForm &operator=(const CourseFinishedForm &src);
        virtual ~CourseFinishedForm();

        void execute();
        void setCourseName(const std::string &courseName);
};
