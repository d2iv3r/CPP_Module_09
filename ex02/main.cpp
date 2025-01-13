/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:57:20 by efarhat           #+#    #+#             */
/*   Updated: 2024/01/07 18:48:36 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Error: Invalid arguments!" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe merge_me(argv);
		merge_me.mergeInsertSort();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
