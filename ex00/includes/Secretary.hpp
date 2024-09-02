/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Secretary.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:51:01 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 18:30:54 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include "Staff.hpp"
#include "Form.hpp"

class Form;

class Secretary : public Staff
{
    public:
        explicit Secretary(const std::string &staffName);
        Secretary(const Secretary &src);
        Secretary &operator=(const Secretary &src);
        virtual ~Secretary();

        //Methods
        std::shared_ptr<Form> createForm(FormType formType);
};
