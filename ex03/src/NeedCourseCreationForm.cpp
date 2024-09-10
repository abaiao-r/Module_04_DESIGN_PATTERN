/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedCourseCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:39:49 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/10 19:10:31 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/NeedCourseCreationForm.hpp"

NeedCourseCreationForm::NeedCourseCreationForm() : Form(FormType::NeedCourseCreation)
{
}

NeedCourseCreationForm::NeedCourseCreationForm(const std::string &target) : Form(FormType::NeedCourseCreation, target)
{
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

