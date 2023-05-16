/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:39:25 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/16 17:07:32 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class ValueNotFound : public std::exception
{
	public:
		virtual const char* what() const throw();
};

template< typename T >
typename T::iterator	easyfind(T& a, const int b);

#include "easyfind.tpp"

#endif
