/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedCourseCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:37:36 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 15:38:15 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class NeedCourseCreationForm : public Form
{
    public:
        NeedCourseCreationForm();
        NeedCourseCreationForm(const NeedCourseCreationForm &src);
        NeedCourseCreationForm &operator=(const NeedCourseCreationForm &src);
        virtual ~NeedCourseCreationForm();

        void execute();
};