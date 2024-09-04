/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Headmaster.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:14:53 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 20:16:44 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <iostream>
#include <vector>

#include "Staff.hpp"
#include "Form.hpp"

class Headmaster : public Staff
{
    private:
        std::vector<std::shared_ptr<Form>> _formToValidate;

    public:
        Headmaster();
        Headmaster(const Headmaster &src);
        Headmaster &operator=(const Headmaster &src);
        virtual ~Headmaster();

        //Methods
        void receiveForm(std::shared_ptr<Form> p_form);
        void signForm(std::shared_ptr<Form> p_form);
        void executeForm(std::shared_ptr<Form> p_form);      
};
