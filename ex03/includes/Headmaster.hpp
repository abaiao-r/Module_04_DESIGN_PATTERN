/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:14:53 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/07 17:02:05 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

#include "Staff.hpp"
#include "Form.hpp"

class Headmaster : public Staff
{
    private:
        std::vector<Form*> _formToValidate;

    public:
        Headmaster();
        Headmaster(const Headmaster &src);
        Headmaster &operator=(const Headmaster &src);
        virtual ~Headmaster();

        //Methods
        void receiveForm(Form* p_form);
        void signForm(Form* p_form);
        void executeForm(Form* p_form);      
};