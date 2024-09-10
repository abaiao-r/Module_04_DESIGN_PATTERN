/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubscriptionToCourseForm.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:48:42 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/10 16:40:33 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SubscriptionToCourseForm.hpp"

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse)
{
}

SubscriptionToCourseForm::SubscriptionToCourseForm(const std::string &target) : Form(FormType::SubscriptionToCourse, target)
{
}

SubscriptionToCourseForm::~SubscriptionToCourseForm()
{
}

void SubscriptionToCourseForm::execute()
{
    // Implement the execute method here
    if (this->isSigned())
    {
        std::cout << "Execute SubscriptionToCourseForm" << std::endl;
    }
    else
    {
        std::cout << "Form not signed yet. Cannot execute." << std::endl;
    }
}

