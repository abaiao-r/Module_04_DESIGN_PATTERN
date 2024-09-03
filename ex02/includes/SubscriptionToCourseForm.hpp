/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubscriptionToCourseForm.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:48:26 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 16:55:17 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class SubscriptionToCourseForm : public Form
{
    public:
        SubscriptionToCourseForm();
        SubscriptionToCourseForm(const SubscriptionToCourseForm &src);
        SubscriptionToCourseForm &operator=(const SubscriptionToCourseForm &src);
        virtual ~SubscriptionToCourseForm();

        void execute();
};
