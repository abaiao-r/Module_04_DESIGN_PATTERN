/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedCourseCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:39:49 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/25 17:18:57 by abaiao-r         ###   ########.fr       */
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
    
}
