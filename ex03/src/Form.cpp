/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:46:15 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 15:26:28 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(FormType formType) : _formType(formType), _isSigned(false)
{
}

Form::Form(const Form &src) : _formType(src._formType), _isSigned(src._isSigned)
{
}

Form &Form::operator=(const Form &src)
{
    if (this != &src)
    {
        this->_formType = src._formType;
        this->_isSigned = src._isSigned;
    }
    return (*this);
}

Form::~Form()
{
}


void Form::signForm()
{
    this->_isSigned = true;
}

bool Form::isSigned() const
{
    return (this->_isSigned);
}

FormType Form::getFormType() const
{
    return (this->_formType);
}
