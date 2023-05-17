/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:25:54 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/17 12:49:31 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.class.hpp"
#include <algorithm>

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

// FUNCTIONS

void	Span::addNumber(int value)
{
	if (_array.size() >= _max_integers)
		throw SpanException();
	_array.push_back(value);
}

static int RandGenerator()
{
	return (std::rand() % 1000);
}

void	Span::fillRandom()
{
    std::srand(time(0));
	_array.resize(_max_integers);
	std::generate(_array.begin(), _array.end(), RandGenerator);
}

void	Span::printArray() const
{
	size_t temp = _max_integers;
	if (_max_integers > 200)
	{	
		temp = 200;
		for (size_t i = 0; i < temp; i++)
		{
			std::cout << _array[i];
			if (i < temp - 1)
				std::cout << ", ";
		}
		std::cout << " [...]\n" << std::endl;
		return ;
	}
	for (size_t i = 0; i < temp; i++)
	{
		std::cout << _array[i];
		if (i < temp - 1)
			std::cout << ", ";
	}
	std::cout << "\n" << std::endl;
}

// ACCESSORS

int		Span::getSize() const
{
	return _array.size();
}

// EXCEPTIONS

const char* Span::SpanException::what() const throw()
{
	return ("\x1b[31mSpan not possible\x1b[0m");
}
