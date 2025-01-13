/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:58:33 by efarhat           #+#    #+#             */
/*   Updated: 2024/01/08 11:59:02 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int> 		vec;
		std::vector<int> 		mainVec;
		std::deque<int> 		deq;
		std::deque<int> 		mainDeq;
		PmergeMe();
	public:
		PmergeMe(char** const &args);
		PmergeMe(const PmergeMe &cpy);
		PmergeMe& operator=(const PmergeMe &cpy);
		~PmergeMe();

		void mergeInsertSort();
		void vectorSort();
		void dequeSort();
};

#endif
