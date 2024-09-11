/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SecretarialOffice.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:06:26 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/11 16:44:47 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

#include "Room.hpp"
#include "Form.hpp"

class Form;

class SecretarialOffice : public Room
{
    private:
        std::vector<Form*> _archivedForms;
        
    public:
        SecretarialOffice();
        virtual ~SecretarialOffice();
};
