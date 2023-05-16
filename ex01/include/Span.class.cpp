/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:25:54 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/16 21:48:26 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.class.hpp"

Span::Span() : _max_integers(0) {}

Span::Span(unsigned int n) : _max_integers(n) {}

Span::Span(const Span& src)
{
	_max_integers = src._max_integers;
	_array = src._array;
}

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		_max_integers = rhs._max_integers;
		_array = rhs._array;
	}
	return *this;
}

Span::~Span() {}

// EXCEPTIONS

const char* Span::SpanException::what() const throw()
{
	return ("\x1b[31mSpan not possible\x1b[0m");
}
