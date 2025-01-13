/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:43:47 by efarhat           #+#    #+#             */
/*   Updated: 2024/01/06 11:33:59 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>

class Rpn
{
	private:
		std::stack<int> st;
		void makeOperation(char const &c);
		int popAndReturn();
		Rpn();
	public:
		Rpn(std::string const &args);
		Rpn(const Rpn &cpy);
		Rpn& operator=(const Rpn &cpy);
		~Rpn();
};

#endif
