/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:25:54 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/18 11:20:00 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.class.hpp"

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

long long	Span::shortestSpan()
{
	std::vector<int>::iterator	it;
	long long					shortestSpan;
	long long					difference = 0;
	
	shortestSpan = 4294967295;

	std::sort(_array.begin(), _array.end()); // sort ascending order
	if (_array.size() > 1)
	{
		for (it = _array.begin() + 1; it != _array.end(); ++it)
		{
			difference = static_cast<long long>(*it) - static_cast<long long>(*(it - 1));
			// std::cout << "DEBUG" << difference << std::endl; // DEBUG
			shortestSpan = std::min(shortestSpan, difference);
		}
		return shortestSpan;
	}
	throw std::out_of_range ("\x1b[31mSpan not possible\x1b[0m");
}

long long	Span::longestSpan()
{
	if (_array.size() > 1)
	{
		std::sort(_array.begin(), _array.end()); // sort with ascending order
		return (static_cast<long long>(*_array.rbegin()) - (static_cast<long long>(*_array.begin())));
	}
	throw std::out_of_range ("\x1b[31mSpan not possible\x1b[0m");
}

void	Span::addNumber(int value)
{
	if (!(value >= INT_MIN && value <= INT_MAX))
		throw std::out_of_range ("\x1b[31minput exceeds max integer range\x1b[0m");
	if (_array.size() >= _max_integers)
		throw SpanException();
	_array.push_back(value);
	_added += 1;
}

static int RandGenerator()
{
	return (std::rand() % 1000); // random range
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
	else
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
