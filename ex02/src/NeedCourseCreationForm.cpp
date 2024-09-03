/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedCourseCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:39:49 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 15:44:12 by andrefranci      ###   ########.fr       */
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

