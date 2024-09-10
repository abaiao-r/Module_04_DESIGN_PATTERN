/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubscriptionToCourseForm.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:48:26 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/10 16:40:38 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"
#include "Course.hpp"

class SubscriptionToCourseForm : public Form
{
    public:
        SubscriptionToCourseForm();
        SubscriptionToCourseForm(const std::string &target);
        virtual ~SubscriptionToCourseForm();

        void execute();
};
