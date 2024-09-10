/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SecretarialOffice.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:06:26 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/08 00:11:18 by andrefranci      ###   ########.fr       */
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
