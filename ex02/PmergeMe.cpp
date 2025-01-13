/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 11:05:39 by efarhat           #+#    #+#             */
/*   Updated: 2024/01/08 12:15:31 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

int getNumber(std::string const &str)
{
	if (str.empty())
		throw std::runtime_error("Error: Not a number!");
	int nb;
	char *endP;
	nb = std::strtod(str.c_str(), &endP);
	if (*endP)
		throw std::logic_error("Error: Invalid number!");
	return nb;
}

PmergeMe::PmergeMe(char** const &args)
{
	int i = 1;
	int nb;
	while (args[i])
	{
		nb = getNumber(args[i]);
		if (nb < 0)
			throw std::logic_error("Error: just positive numbers!");
		vec.push_back(nb);
		deq.push_back(nb);
		i++;
	}
}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
	*this = cpy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &cpy)
{
	if (this != &cpy)
	{
		vec = cpy.vec;
		mainVec = cpy.mainVec;
		deq = cpy.deq;
		mainDeq = cpy.mainDeq;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

static int JacobsthalNum(int flag)
{
	static int a = 1;
	static int b = 1;
	static int j;

	if (flag == 1)
	{
		a = 1;
		b = 1;
	}
	j = b + (2 * a);
	a = b;
	b = j;
	return (j);
}

//////////////////////////////////////
/////////		VECTOR		/////////
/////////////////////////////////////

void sortNumbers(std::vector< std::pair<int, int> > &l, std::vector< std::pair<int, int> > &r, std::vector< std::pair<int, int> > &pairs)
{
	size_t i = 0, j = 0, k = 0;

	while (i < l.size() && j < r.size())
	{
		if (l[i].first < r[j].first)
			pairs[k++] = l[i++];
		else
			pairs[k++] = r[j++];
	}
	for (; i < l.size(); i++)
		pairs[k++] = l[i];
	for (; j < r.size(); j++)
		pairs[k++] = r[j];
}

void mergeSort(std::vector< std::pair<int, int> > &pairs)
{
	if (pairs.size() == 1)
		return ;
	std::vector< std::pair<int, int> > left;
	std::vector< std::pair<int, int> > right;
	left.insert(left.end(), pairs.begin(), pairs.begin() + pairs.size() / 2);
	right.insert(right.end(), pairs.begin() + pairs.size() / 2, pairs.end());
	mergeSort(left);
	mergeSort(right);
	sortNumbers(left, right, pairs);
}

std::vector<int> insert_sort(std::vector< std::pair<int, int> > const &pairs, int unpaired)
{
	std::vector<int>main;
	std::vector<int>pend;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		main.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	if (unpaired != -1)
		pend.push_back(unpaired);
	main.insert(main.begin(), pend.front());
	size_t l = 1;
	size_t i = 1;
	size_t j = JacobsthalNum(0);
	int n = j;
	std::vector<int>::iterator it;
	if (pend.size() < 3)
	{
		j = 2;
		n = j;
	}
	while (i < pend.size())
	{
		it = std::lower_bound(main.begin(), main.begin() + (n + l - 1), pend[j - 1]);
		main.insert(it, pend[j - 1]);
		i++;
		j--;
		if (j == l)
		{
			l = n;
			j = JacobsthalNum(0);
			if (j > pend.size())
				j = pend.size();
			n = j;
		}
	}
	return main;
}

void PmergeMe::vectorSort()
{
	if (vec.size() == 1)
	{
		mainVec.push_back(vec.back());
		return ;
	}
	std::vector< std::pair<int, int> > pairs;
	std::pair<int, int> p;
	for (size_t i = 0; i < vec.size() - 1; i += 2)
	{
		if (vec[i] < vec[i + 1])
			p = std::make_pair(vec[i + 1], vec[i]);
		else
			p = std::make_pair(vec[i], vec[i + 1]);
		pairs.push_back(p);
	}
	mergeSort(pairs);
	this->mainVec = insert_sort(pairs, ((vec.size() & 1) != 0) ? vec.back() : -1);
}

//////////////////////////////////////
/////////		DEQUE		/////////
/////////////////////////////////////

void sortNumbersDeq(std::deque< std::pair<int, int> > &l, std::deque< std::pair<int, int> > &r, std::deque< std::pair<int, int> > &pairs)
{
	size_t i = 0, j = 0, k = 0;

	while (i < l.size() && j < r.size())
	{
		if (l[i].first < r[j].first)
			pairs[k++] = l[i++];
		else
			pairs[k++] = r[j++];
	}
	for (; i < l.size(); i++)
		pairs[k++] = l[i];
	for (; j < r.size(); j++)
		pairs[k++] = r[j];
}

void mergeSortDeq(std::deque< std::pair<int, int> > &pairs)
{
	if (pairs.size() == 1)
		return ;
	std::deque< std::pair<int, int> > left;
	std::deque< std::pair<int, int> > right;
	left.insert(left.end(), pairs.begin(), pairs.begin() + pairs.size() / 2);
	right.insert(right.end(), pairs.begin() + pairs.size() / 2, pairs.end());
	mergeSortDeq(left);
	mergeSortDeq(right);
	sortNumbersDeq(left, right, pairs);
}

std::deque<int> insert_sortDeq(std::deque< std::pair<int, int> > const &pairs, int unpaired)
{
	std::deque<int>main;
	std::deque<int>pend;

	for (size_t i = 0; i < pairs.size(); i++)
	{
		main.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	if (unpaired != -1)
		pend.push_back(unpaired);
	main.insert(main.begin(), pend.front());
	size_t l = 1;
	size_t i = 1;
	size_t j = JacobsthalNum(1);
	int n = j;
	std::deque<int>::iterator it;
	if (pend.size() < 3)
	{
		j = 2;
		n = j;
	}
	while (i < pend.size())
	{
		it = std::lower_bound(main.begin(), main.begin() + (n + l - 1), pend[j - 1]);
		main.insert(it, pend[j - 1]);
		i++;
		j--;
		if (j == l)
		{
			l = n;
			j = JacobsthalNum(0);
			if (j > pend.size())
				j = pend.size();
			n = j;
		}
	}
	return main;
}

void PmergeMe::dequeSort()
{
	if (deq.size() == 1)
	{
		mainDeq.push_back(deq.back());
		return ;
	}
	std::deque< std::pair<int, int> > pairs;
	std::pair<int, int> p;
	for (size_t i = 0; i < deq.size() - 1; i += 2)
	{
		if (deq[i] < deq[i + 1])
			p = std::make_pair(deq[i + 1], deq[i]);
		else
			p = std::make_pair(deq[i], deq[i + 1]);
		pairs.push_back(p);
	}
	mergeSortDeq(pairs);
	mainDeq = insert_sortDeq(pairs, ((deq.size() & 1) != 0) ? deq.back() : -1);
}

void PmergeMe::mergeInsertSort()
{
	clock_t vecStart, deqStart, vecEnd, deqEnd;
	vecStart = clock();
	vectorSort();
	vecEnd = clock();
	deqStart = clock();
	dequeSort();
	deqEnd = clock();
	std::cout << "Before:	";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	std::cout << "After:	";
	for (size_t i = 0; i < mainVec.size(); i++)
		std::cout << mainVec[i] << " ";
	std::cout << std::endl;
	double time = ((vecEnd - vecStart) / static_cast<double>(CLOCKS_PER_SEC)) * 1000000;
	std::cout << "Time to process a range of	" << vec.size() <<
	" elements with std::vector : " << time << " us" << std::endl;
	time = ((deqEnd - deqStart) / static_cast<double>(CLOCKS_PER_SEC)) * 1000000;
	std::cout << "Time to process a range of	" << vec.size() <<
	" elements with std::deque : " << time << " us" << std::endl;
}
