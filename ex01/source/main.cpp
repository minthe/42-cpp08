/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:30:42 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/17 13:47:35 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.class.hpp"
#include <exception>
#include <iostream>

int main()
{
	// {
	// 	std::cout << "\n\x1b[47mTest 1 (from Subject)\x1b[0m\n"<< std::endl;

	// 	Span sp = Span(5);
	// 	sp.addNumber(6);
	// 	sp.addNumber(3);
	// 	sp.addNumber(17);
	// 	sp.addNumber(9);
	// 	sp.addNumber(11);

	// 	std::cout << sp.shortestSpan() << std::endl;
	// 	std::cout << sp.longestSpan() << std::endl;
	// }
	{
		try
		{
			std::cout << "\x1b[47mTest 2\x1b[0m\n"<< std::endl;

			Span sp = Span(-5);
			sp.addNumber(-999);
			sp.addNumber(+6);
			std::cout << "size: " << sp.getSize() << std::endl;
			sp.fillRandom();
			std::cout << "size: " << sp.getSize() << std::endl;
			sp.printArray();
			std::cout << "size: " << sp.getSize() << std::endl;

			// std::cout << sp.shortestSpan() << std::endl;
			// std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}

	return 0;
}
