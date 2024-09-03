/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedMoreClassRoomForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:47:54 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 17:33:02 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/NeedMoreClassRoomForm.hpp"

NeedMoreClassRoomForm::NeedMoreClassRoomForm() : Form(FormType::NeedMoreClassRoom)
{
}

NeedMoreClassRoomForm::NeedMoreClassRoomForm(const NeedMoreClassRoomForm &src) : Form(src)
{
}

NeedMoreClassRoomForm &NeedMoreClassRoomForm::operator=(const NeedMoreClassRoomForm &src)
{
    if (this != &src)
    {
        Form::operator=(src);
    }
    return (*this);
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
