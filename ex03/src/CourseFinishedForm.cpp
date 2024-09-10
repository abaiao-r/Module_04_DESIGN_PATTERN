/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourseFinishedForm.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:47:03 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/08 00:12:13 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/CourseFinishedForm.hpp"

CourseFinishedForm::CourseFinishedForm() : Form(FormType::CourseFinished)
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