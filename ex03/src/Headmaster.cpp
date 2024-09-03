/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:39:58 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 19:47:06 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Headmaster.hpp"

Headmaster::Headmaster() : Staff("Headmaster")
{
}

Headmaster::Headmaster(const Headmaster &src) : Staff(src)
{
}

Headmaster &Headmaster::operator=(const Headmaster &src)
{
    if (this != &src)
    {
        Staff::operator=(src);
    }
    return (*this);
}

Headmaster::~Headmaster()
{
}

void Headmaster::receiveForm(std::shared_ptr<Form> p_form)
{
    _formToValidate.push_back(p_form);
}

void Headmaster::signForm(std::shared_ptr<Form> p_form)
{
    p_form->signForm();
    std::cout << "Headmaster signs form" << std::endl;
}

void Headmaster::executeForm(std::shared_ptr<Form> p_form)
{
    if (p_form->isSigned())
    {
        // loop through the vector of forms to validate and execute the form
        for (std::vector<std::shared_ptr<Form>>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it)
        {
            if (*it == p_form)
            {
                p_form->execute();
                // remove the form from the vector
                _formToValidate.erase(it);
                return;
            }
        }
    }
    else
    {
        std::cout << "Form not signed yet. Cannot execute." << std::endl;
    }
}