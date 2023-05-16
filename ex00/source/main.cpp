/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:39:20 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/16 15:22:10 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"
#include <exception>
#include <vector>
#include <iostream>

int main()
{
	try
	{
		std::vector<int> some_numbers;

		some_numbers.push_back(0);
		some_numbers.push_back(-4);
		some_numbers.push_back(6);

		std::cout << *easyfind(some_numbers, 5) << std::endl; // dereferenced iterator of std::vector
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
