/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:25:54 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/17 17:52:20 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.class.hpp"
#include <cstddef>
#include <limits>
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

int		Span::shortestSpan() // TODO
{
	std::vector<int>::iterator	it;
	int							shortestSpan;
	int							difference = 0;
	
	shortestSpan = 2147483647;

	std::sort(_array.begin(), _array.end());
	if (_array.size() > 1)
	{
		for (it = _array.begin() + 1; it != _array.end(); ++it)
		{
			difference = *it - *(it - 1);
			// std::cout << "DEBUG" << difference << std::endl; // DEBUG
			shortestSpan = std::min(shortestSpan, difference);
		}
		return shortestSpan;
	}
	throw std::out_of_range ("\x1b[31mSpan not possible\x1b[0m");
}

int		Span::longestSpan()
{
	if (_array.size() > 1)
	{
		std::sort(_array.begin(), _array.end());
		return (*_array.rbegin() - *_array.begin());
	}
	throw std::out_of_range ("\x1b[31mSpan not possible\x1b[0m");
}

void	Span::addNumber(int value)
{
	if (_array.size() >= _max_integers)
		throw SpanException();
	_array.push_back(value);
	_added += 1;
}

static int RandGenerator()
{
	return (std::rand() % 10000); // random range
}

void	Span::fillRandom()
{
	if (_array.size() >= _max_integers)
		throw SpanException();
    std::srand(time(0));
	_array.resize(_max_integers);
	printArray();
	std::vector<int>::iterator it = _array.begin();
	if (_added)
		std::advance(it, _added);
	std::generate(it, _array.end(), RandGenerator);
}

void	Span::printArray()
{
	std::vector<int>::iterator	it = _array.begin();
	size_t						temp = 200;

	if (_array.size())
	{	
		if (_max_integers < 200)
			temp = _max_integers;
		for (it + 1; it < _array.end(); it++)
		{
			std::cout << *it;
			if (it < (_array.end() - 1))
				std::cout << ", ";
		}
		if (_max_integers > 199)
			std::cout << " [...]\n" << std::endl;
		else
			std::cout << "\n" << std::endl;
		return ;
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
	return ("\x1b[31mArray full\x1b[0m");
}
