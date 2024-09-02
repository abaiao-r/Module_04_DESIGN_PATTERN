/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:46:15 by andrefranci       #+#    #+#             */
/*   Updated: 2024/08/31 17:46:35 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(FormType formType) : _formType(formType)
{
}

Form::Form(const Form &src) : _formType(src._formType)
{
}

Form &Form::operator=(const Form &src)
{
    if (this != &src)
    {
        this->_formType = src._formType;
    }
    return (*this);
}

Form::~Form()
{
}
