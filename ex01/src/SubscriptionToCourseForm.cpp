/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SubscriptionToCourseForm.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:48:42 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 17:48:52 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SubscriptionToCourseForm.hpp"

SubscriptionToCourseForm::SubscriptionToCourseForm() : Form(FormType::SubscriptionToCourse)
{
}

SubscriptionToCourseForm::SubscriptionToCourseForm(const SubscriptionToCourseForm &src) : Form(src)
{
}

SubscriptionToCourseForm &SubscriptionToCourseForm::operator=(const SubscriptionToCourseForm &src)
{
    if (this != &src)
    {
        Form::operator=(src);
    }
    return (*this);
}

SubscriptionToCourseForm::~SubscriptionToCourseForm()
{
}

void SubscriptionToCourseForm::execute()
{
    // Implement the execute method here
}

