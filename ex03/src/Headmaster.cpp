/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:39:58 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 21:05:31 by andrefranci      ###   ########.fr       */
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

    // check if the p_form is in the vector of forms
    for (std::vector<std::shared_ptr<Form>>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it)
    {
        if ((*it)->getFormType() == p_form->getFormType())
        {
            (*it)->signForm();
            std::cout << "Headmaster signs form" << std::endl;
            return;
        }
    }
    std::cout << "Form not found in the list. Cannot sign." << std::endl;
}

void Headmaster::executeForm(std::shared_ptr<Form> p_form)
{
   //loop through the vector of forms
    for (std::vector<std::shared_ptr<Form>>::iterator it = _formToValidate.begin(); it != _formToValidate.end(); ++it)
    {
        if ((*it)->getFormType() == p_form->getFormType())
        {
            if ((*it)->isSigned())
            {
                p_form->execute();
                //remove the form from the vector
                _formToValidate.erase(it);
                return;
            }
            else
            {
                std::cout << "Form not signed yet. Cannot execute." << std::endl;
                return;
            }
        }
    }
    std::cout << "Form not found in the list. Cannot execute." << std::endl;
}