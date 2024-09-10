/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedMoreClassRoomForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:47:34 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/08 00:10:57 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class NeedMoreClassRoomForm : public Form
{
    public:
        NeedMoreClassRoomForm();
        virtual ~NeedMoreClassRoomForm();

        void execute();
};
