/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Courtyard.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:25:02 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 17:25:38 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Room.hpp"

class Courtyard : public Room
{
    private:
        
    public:
        Courtyard();
        Courtyard(const Courtyard &src);
        Courtyard &operator=(const Courtyard &src);
        virtual ~Courtyard();
};
