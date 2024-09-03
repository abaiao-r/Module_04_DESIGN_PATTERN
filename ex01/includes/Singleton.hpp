/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Singleton.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:54:20 by andrefranci       #+#    #+#             */
/*   Updated: 2024/09/03 14:27:35 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm> // For std::remove
#include <stdexcept> // For std::out_of_range

template <typename T, typename Tag>
class Singleton 
{
    private:
        std::vector<T> _list; // List to hold items
        
    protected:
        Singleton() = default; // Private constructor

    public:
        // Delete copy constructor and assignment operator
        Singleton(const Singleton &) = delete;
        Singleton &operator=(const Singleton&) = delete;

        // Static method to access the singleton instance
        static Singleton &getInstance() 
        {
            static Singleton instance; // Guaranteed to be destroyed and instantiated on first use
            return (instance);
        }

        void add(const T &item)
        {
            _list.push_back(item);
        }

        void remove(const T &item) 
        {
            _list.erase(std::remove(_list.begin(), _list.end(), item), _list.end());
        }

        const std::vector<T> &getList() const
        {
            return (_list);
        }

        T operator[](int index) const
        {
            if (index < 0 || index >= (int)_list.size())
            {
                throw std::out_of_range("Index out of range");
            }
            return (_list[index]);
        }

};

