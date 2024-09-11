/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:46:15 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/11 09:30:23 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form(FormType formType) : _formType(formType), _isSigned(false), _target(""), _sender("")
{
}

Form::Form(FormType formType, const std::string &target) : _formType(formType), _isSigned(false), _target(target), _sender("")
{
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

std::string Form::getTarget() const
{
    return (this->_target);
}

std::string Form::getSender() const
{
    return (this->_sender);
}
