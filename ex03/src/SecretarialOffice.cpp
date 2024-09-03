/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SecretarialOffice.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:15:25 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 17:19:22 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SecretarialOffice.hpp"

SecretarialOffice::SecretarialOffice() : Room()
{
}

SecretarialOffice::SecretarialOffice(const SecretarialOffice &src) : Room(src)
{
}

SecretarialOffice &SecretarialOffice::operator=(const SecretarialOffice &src)
{
    if (this != &src)
    {
        Room::operator=(src);
    }
    return (*this);
}

SecretarialOffice::~SecretarialOffice()
{
}
