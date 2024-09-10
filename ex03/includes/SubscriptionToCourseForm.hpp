/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubscriptionToCourseForm.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:48:26 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/08 00:11:48 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class SubscriptionToCourseForm : public Form
{
    public:
        SubscriptionToCourseForm();
        virtual ~SubscriptionToCourseForm();

        void execute();
};
