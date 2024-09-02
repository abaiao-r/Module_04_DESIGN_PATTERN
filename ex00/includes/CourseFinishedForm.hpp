/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourseFinishedForm.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:45:44 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 17:46:09 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class CourseFinishedForm : public Form
{
    public:
        CourseFinishedForm();
        CourseFinishedForm(const CourseFinishedForm &src);
        CourseFinishedForm &operator=(const CourseFinishedForm &src);
        virtual ~CourseFinishedForm();

        void execute();
};
