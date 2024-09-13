/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Staff.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:30:09 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/08 00:14:04 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/one.hpp"

Staff::Staff(const std::string &staffName) : Person(staffName)
{
}

Staff::~Staff()
{
}

void Staff::sign(Form* form)
{
    // Implement the sign method here
    form->signForm();
}

