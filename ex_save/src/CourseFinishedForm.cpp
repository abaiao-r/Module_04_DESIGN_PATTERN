/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourseFinishedForm.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:47:03 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/12 17:33:36 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/one.hpp"

CourseFinishedForm::CourseFinishedForm() : Form(FormType::CourseFinished)
{
}

CourseFinishedForm::CourseFinishedForm(const std::string &target) : Form(FormType::CourseFinished, target)
{
}

CourseFinishedForm::~CourseFinishedForm()
{
}

void CourseFinishedForm::execute()
{
    // Implement the execute method here
    if (this->isSigned())
    {
        std::cout << "Execute CourseFinishedForm for course " << this->_courseName << std::endl;
    }
    else
    {
        std::cout << "Form not signed yet. Cannot execute." << std::endl;
    }
}

void CourseFinishedForm::setCourseName(const std::string &courseName)
{
    this->_courseName = courseName;
}
