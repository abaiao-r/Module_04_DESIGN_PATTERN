/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeadmasterOffice.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:20:01 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/08 00:10:48 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <memory>
#include <iostream>

#include "Room.hpp"
#include "Form.hpp"

class HeadmasterOffice : public Room
{
    private:
        
    public:
        HeadmasterOffice();
        virtual ~HeadmasterOffice();

};