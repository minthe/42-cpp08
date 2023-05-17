/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:25:54 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/17 14:56:49 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.class.hpp"
#include <stdexcept>

Span::Span() : _max_integers(0), _added(0) {}

Span::Span(unsigned int n)
{
	if (n > INT_MAX)
		throw std::out_of_range ("\x1b[31minput exceeds max integer range\x1b[0m");
	_max_integers = n;
	_added = 0;
}

Span::Span(const Span& src)
{
	_max_integers = src._max_integers;
	_array = src._array;
	_added = src._added;
}

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs)
	{
		_max_integers = rhs._max_integers;
		_array = rhs._array;
		_added = rhs._added;
	}
	return *this;
}

Span::~Span() {}

// FUNCTIONS

int		Span::shortestSpan()
{
	if (_array.size())
	{
		std::sort(_array.begin(), _array.end());
		return 1;
	}
	throw std::out_of_range ("no Span can be found");
}

int		Span::longestSpan()
{
	if (_array.size())
	{
		std::sort(_array.begin(), _array.end());
		return (*--_array.end() - *_array.begin());
	}
	throw std::out_of_range ("no Span can be found");
}

void	Span::addNumber(int value)
{
	if (_array.size() >= _max_integers)
		throw SpanException();
	_array.push_back(value);
	_added++;
}

static int RandGenerator()
{
	return (std::rand() % 1000);
}

void	Span::fillRandom()
{
	if (_array.size() >= _max_integers)
		throw SpanException();
    std::srand(time(0));
	_array.resize(_max_integers);
	printArray();
	std::vector<int>::iterator temp = _array.begin();
	if (_added)
		std::advance(temp, _added);
	std::generate(temp, _array.end(), RandGenerator);
}

void	Span::printArray() const
{
	if (_array.size())
	{	
		size_t temp = 200;
		if (_max_integers < 200)
			temp = _max_integers;
		for (size_t i = 0; i < temp; i++)
		{
			std::cout << _array[i];
			if (i < temp - 1)
				std::cout << ", ";
		}
		if (_max_integers > 199)
			std::cout << " [...]\n" << std::endl;
		else
			std::cout << "\n" << std::endl;
	}
	std::cout << "empty array" << std::endl;
}

// ACCESSORS

int		Span::getSize() const
{
	return _array.size();
}

// EXCEPTIONS

const char* Span::SpanException::what() const throw()
{
	return ("\x1b[31mOperation not possible\x1b[0m");
}
