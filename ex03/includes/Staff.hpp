/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Staff.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:21:12 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/11 16:44:45 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Person.hpp"
#include "Form.hpp"

class Form;

class Staff : public Person
{
    public:
        explicit Staff(const std::string &staffName);
        virtual ~Staff();

        //Methods
        void sign(Form* form);
};