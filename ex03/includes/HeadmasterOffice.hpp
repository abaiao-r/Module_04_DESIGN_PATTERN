/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeadmasterOffice.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:20:01 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/11 17:02:56 by abaiao-r         ###   ########.fr       */
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