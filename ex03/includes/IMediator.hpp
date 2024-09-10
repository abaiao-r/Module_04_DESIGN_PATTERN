/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMediator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:11:36 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/09 15:29:44 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class IMediator
{
    public:
        virtual ~IMediator() = default;

        virtual void notify(const std::string &sender, const std::string &event) const = 0;
};
