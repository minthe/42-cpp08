/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:25:53 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/16 17:47:08 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CLASS_HPP
#define SPAN_CLASS_HPP

class Span
{
	public:
		Span(const unsigned int n);
		Span(const Span& src);
		Span&	operator=(const Span& rhs);
		~Span();

		void	addNumber(int value);
		int		shortestSpan() const;
		int		longestSpan() const;

	private:
		Span();
		const unsigned int	_max_integers;
};

#endif
