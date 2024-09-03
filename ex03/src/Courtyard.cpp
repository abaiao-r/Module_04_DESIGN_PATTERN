/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Courtyard.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:25:55 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 17:29:29 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Courtyard.hpp"

Courtyard::Courtyard() : Room()
{
}

Courtyard::Courtyard(const Courtyard &src) : Room(src)
{
}

Courtyard &Courtyard::operator=(const Courtyard &src)
{
    if (this != &src)
    {
        Room::operator=(src);
    }
    return (*this);
}

Courtyard::~Courtyard()
{
}
