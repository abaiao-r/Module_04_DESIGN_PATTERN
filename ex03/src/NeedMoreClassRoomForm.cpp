/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedMoreClassRoomForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:47:54 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/10 19:12:26 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/one.hpp"

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom)
{
}

NeedMoreClassRoomForm::NeedMoreClassRoomForm(const std::string &target) : Form(FormType::NeedMoreClassRoom, target)
{
}


NeedMoreClassRoomForm::~NeedMoreClassRoomForm()
{
}

void NeedMoreClassRoomForm::execute()
{
    // Implement the execute method here
    if (this->isSigned())
    {
        std::cout << "Execute NeedMoreClassRoomForm" << std::endl;
    }
    else
    {
        std::cout << "Form not signed yet. Cannot execute." << std::endl;
    }
}
