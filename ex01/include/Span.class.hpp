/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:25:53 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/17 17:13:45 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
#define SPAN_CLASS_HPP

#include <exception>
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <numeric>

class Span
{
	public:
		Span();
		Span(const unsigned int n);
		Span(const Span& src);
		Span&	operator=(const Span& rhs);
		~Span();

		class SpanException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		int		shortestSpan();
		int		longestSpan();

		int		getSize() const;
		void	addNumber(int value);
		void	fillRandom();
		void	printArray();

	private:
		std::vector<int>	_array;
		unsigned int		_max_integers;
		int					_added;
};

#endif
