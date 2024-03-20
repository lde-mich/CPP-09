/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:29:30 by lde-mich          #+#    #+#             */
/*   Updated: 2024/03/20 13:08:52 by lde-mich         ###   ########.fr       */
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

	//char c;
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
			this->stack.push(argv[i]);
			i++;
		}
		int j = 0;
		while (!this->stack.empty())
		{
			std::cout << "top→ "<< this->stack.top() << std::endl;
			std::cout << "operator→ " << argv[i] << std::endl;
			switch (argv[i])
			{
				case '+':
					n += this->stack.top() - '0';
					break;
				case '-':
					n -= this->stack.top() - '0';
					break;
				case '*':
					if (j == 0)
					{
						n = this->stack.top() - '0';
						this->stack.pop();
						j++;
					}
					n *= this->stack.top() - '0';
					break;
				case '/':
					n /= this->stack.top() - '0';
					break;
			}

			this->stack.pop();
			std::cout << "→ " << n << std::endl;
		}
		i++;
	}
}
















