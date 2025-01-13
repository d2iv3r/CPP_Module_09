/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:47:49 by efarhat           #+#    #+#             */
/*   Updated: 2024/01/08 13:35:27 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn()
{
}

Rpn::Rpn(const Rpn &cpy)
{
	*this = cpy;
}

Rpn& Rpn::operator=(const Rpn &cpy)
{
	(void)cpy;
	return *this;
}

Rpn::~Rpn()
{
}

bool isOperator(char const &c)
{
	switch (c)
	{
		case '+': case '-': case '*': case '/':
			return true;
		default:
			return false;
	}
}

bool isSign(char const &c) { return (c == '+' || c == '-') ? true : false; }

int Rpn::popAndReturn()
{
	if (st.empty())
		throw std::logic_error("Error");
	int nb = st.top();
	st.pop();
	return nb;
}

void Rpn::makeOperation(char const &c)
{
	int a, b;
	b = popAndReturn();
	a = popAndReturn();
	switch (c)
	{
		case '+':
			st.push(a + b);
			break;
		case '-':
			st.push(a - b);
			break;
		case '*':
			st.push(a * b);
			break;
		case '/':
			if (b == 0)
				throw std::logic_error("Error: division by zero");
			st.push(a / b);
			break;
		default:
			break;
	}
}

Rpn::Rpn(std::string const &args)
{
	if (args.empty())
		return ;
	for (size_t i = 0; i < args.size(); i++)
	{
		if (std::isdigit(args.at(i)))
			st.push(args.at(i++) - 48);
		else if (isSign(args.at(i)) && i + 1 < args.size()
			&& std::isdigit(args.at(i + 1)))
		{
			if (args.at(i) == '-')
				st.push(-(args.at(i + 1) - 48));
			else if (args.at(i) == '+')
				st.push(args.at(i + 1) - 48);
			i += 2;
		}
		else if (isOperator(args.at(i)))
			makeOperation(args.at(i++));
		if (i < args.size() && args.at(i) != ' ')
			throw std::logic_error("Error");
	}
	if (st.size() > 1)
		throw std::logic_error("Error");
	std::cout << st.top() << std::endl;
}
