/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:25:53 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/17 13:09:43 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
#define SPAN_CLASS_HPP

#include <exception>
#include <iterator>
#include <vector>
#include <iostream>

class Span
{
	public:
		Span(const unsigned int n);
		Span(const Span& src);
		Span&	operator=(const Span& rhs);
		~Span();

		class SpanException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		void	addNumber(int value);
		int		getSize() const;
		void	fillRandom();
		int		shortestSpan() const;
		int		longestSpan() const;
		void	printArray() const;

	private:
		Span();
		std::vector<int>	_array;
		unsigned int		_max_integers;
		int					_added;
};

#endif
