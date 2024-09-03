/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Staff.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:30:09 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 19:46:04 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Staff.hpp"

Staff::Staff(const std::string &staffName) : Person(staffName)
{
}

Staff::Staff(const Staff &src) : Person(src)
{
}

Staff &Staff::operator=(const Staff &src)
{
    if (this != &src)
    {
        Person::operator=(src);
    }
    return (*this);
}

Staff::~Staff()
{
}

void Staff::sign(const std::shared_ptr<Form> &form)
{
    // Implement the sign method here
    form->signForm();
}

