/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:39:20 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/16 17:07:12 by vfuhlenb         ###   ########.fr       */
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
		some_numbers.push_back(5);

		std::cout << *easyfind(some_numbers, 5) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
