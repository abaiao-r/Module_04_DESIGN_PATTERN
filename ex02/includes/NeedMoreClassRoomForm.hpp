/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NeedMoreClassRoomForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:47:34 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/02 17:47:44 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class NeedMoreClassRoomForm : public Form
{
    public:
        NeedMoreClassRoomForm();
        NeedMoreClassRoomForm(const NeedMoreClassRoomForm &src);
        NeedMoreClassRoomForm &operator=(const NeedMoreClassRoomForm &src);
        virtual ~NeedMoreClassRoomForm();

        void execute();
};
