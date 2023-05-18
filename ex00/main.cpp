/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:39:20 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/18 11:24:32 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <exception>
#include <vector>
#include <iostream>

int main()
{
	try
	{
		std::vector<int> some_numbers;

		some_numbers.push_back(6);
		some_numbers.push_back(2147483647);
		some_numbers.push_back(-2147483648);

		std::cout << *easyfind(some_numbers, -2147483648) << std::endl; // dereferenced iterator of std::vector
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
