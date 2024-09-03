/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedCourseCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:39:49 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 17:33:29 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/NeedCourseCreationForm.hpp"

NeedCourseCreationForm::NeedCourseCreationForm() : Form(FormType::NeedCourseCreation)
{
}

NeedCourseCreationForm::NeedCourseCreationForm(const NeedCourseCreationForm &src) : Form(src)
{
}

NeedCourseCreationForm &NeedCourseCreationForm::operator=(const NeedCourseCreationForm &src)
{
    if (this != &src)
    {
        Form::operator=(src);
    }
    return (*this);
}

NeedCourseCreationForm::~NeedCourseCreationForm()
{
}

void NeedCourseCreationForm::execute()
{
    // Implement the execute method here
    if (this->isSigned())
    {
        std::cout << "Execute NeedCourseCreationForm" << std::endl;
    }
    else
    {
        std::cout << "Form not signed yet. Cannot execute." << std::endl;
    }
}

