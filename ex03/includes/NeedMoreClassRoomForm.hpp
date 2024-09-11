/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedMoreClassRoomForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:47:34 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/11 17:02:55 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class NeedMoreClassRoomForm : public Form
{
    public:
        NeedMoreClassRoomForm();
        NeedMoreClassRoomForm(const std::string &target);
        virtual ~NeedMoreClassRoomForm();

        void execute();
};
