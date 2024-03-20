/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:29:30 by lde-mich          #+#    #+#             */
/*   Updated: 2024/03/20 18:20:03 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN()
{

}

RPN::RPN(RPN const &obj)
{
	(*this) = obj;
}

RPN::~RPN()
{

}


RPN &RPN::operator=(RPN const &obj)
{
	if (this == &obj)
		return (*this);

	this->stack = obj.stack;

	return (*this);
}


void RPN::calculator(char* argv)
{
	int i = 0;

	int n = 0;

	while (argv[i])
	{
		while (argv[i] != '+' && argv[i] != '-' && argv[i] != '*' && argv[i] != '/')
		{
			if (argv[i] == 32)
			{
				i++;
				continue;
			}
			this->stack.push(argv[i] - '0');
			i++;
		}
		int j = 0;
		int k = 0;
		n = 0;
		for (int m = 0; m < 2; m++)
		{
			switch (argv[i])
			{
				case '+':
					n += this->stack.top();
					this->stack.pop();
					break;
				case '-':
					n = this->stack.top();
					this->stack.pop();
					k = this->stack.top();
					n = k - n;
					this->stack.pop();
					m = 2;
					break;
				case '*':
					if (j == 0)
					{
						n = 1;
						j++;
					}
					n *= this->stack.top();
					this->stack.pop();
					break;
				case '/':
					n = this->stack.top();
					this->stack.pop();
					k = this->stack.top();
					n = k / n;
					this->stack.pop();
					m = 2;
					break;
			}
		}
		this->stack.push(n);
		i++;
	}

	std::cout << n << std::endl;
}
















