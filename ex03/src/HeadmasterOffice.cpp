/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeadmasterOffice.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:20:58 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 16:34:17 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HeadmasterOffice.hpp"

HeadmasterOffice::HeadmasterOffice() : Room()
{
}

HeadmasterOffice::HeadmasterOffice(const HeadmasterOffice &src) : Room(src)
{
}

HeadmasterOffice &HeadmasterOffice::operator=(const HeadmasterOffice &src)
{
    if (this != &src)
    {
        Room::operator=(src);
    }
    return (*this);
}

HeadmasterOffice::~HeadmasterOffice()
{
}

void HeadmasterOffice::signForm(std::shared_ptr<Form> form)
{
    form->signForm();
    std::cout << "HeadmasterOffice signs form" << std::endl;
}

void HeadmasterOffice::executeForm(std::shared_ptr<Form> form)
{
    if (form->isSigned())
    {
        form->execute();
    }
    else
    {
        std::cout << "Form not signed yet. Cannot execute." << std::endl;
    }
}