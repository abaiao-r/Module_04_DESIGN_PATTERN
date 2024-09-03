/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SecretarialOffice.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:06:26 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 17:14:34 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <memory>

#include "Room.hpp"
#include "Form.hpp"

class Form;

class SecretarialOffice : public Room
{
    private:
        std::vector<std::shared_ptr<Form>> _archivedForms;
        
    public:
        SecretarialOffice();
        SecretarialOffice(const SecretarialOffice &src);
        SecretarialOffice &operator=(const SecretarialOffice &src);
        virtual ~SecretarialOffice();
};
