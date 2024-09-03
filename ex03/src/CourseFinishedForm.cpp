/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourseFinishedForm.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:47:03 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 15:30:26 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/CourseFinishedForm.hpp"

CourseFinishedForm::CourseFinishedForm() : Form(FormType::CourseFinished)
{
}

CourseFinishedForm::CourseFinishedForm(const CourseFinishedForm &src) : Form(src)
{
}

CourseFinishedForm &CourseFinishedForm::operator=(const CourseFinishedForm &src)
{
    if (this != &src)
    {
        Form::operator=(src);
    }
    return (*this);
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