/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeadmasterOffice.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:20:01 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 19:58:51 by andrefranci      ###   ########.fr       */
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
        HeadmasterOffice(const HeadmasterOffice &src);
        HeadmasterOffice &operator=(const HeadmasterOffice &src);
        virtual ~HeadmasterOffice();

};