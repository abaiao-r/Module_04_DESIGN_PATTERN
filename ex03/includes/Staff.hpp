/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Staff.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:21:12 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/07 17:16:44 by andrefranci      ###   ########.fr       */
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
        Staff(const Staff &src);
        Staff &operator=(const Staff &src);
        virtual ~Staff();

        //Methods
        void sign(Form* form);
};