/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMediator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:11:36 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/10 22:39:39 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class IMediator
{
    public:
        virtual ~IMediator() = default;

        virtual void notify(const std::string &sender, const std::string &event) = 0;
        virtual void notify(Person &sender, const std::string &event, const std::string &target) = 0;
};
