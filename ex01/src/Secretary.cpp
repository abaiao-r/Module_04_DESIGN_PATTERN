/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Secretary.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:54:02 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 18:55:44 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Secretary.hpp"

Secretary::Secretary(const std::string &staffName) : Staff(staffName)
{
}

Secretary::Secretary(const Secretary &src) : Staff(src)
{
}

Secretary &Secretary::operator=(const Secretary &src)
{
    if (this != &src)
    {
        Staff::operator=(src);
    }
    return (*this);
}

Secretary::~Secretary()
{
}

std::shared_ptr<Form> Secretary::createForm(FormType formType)
{
    // Implement the createForm method here
    (void)formType;
    return (nullptr);
}
