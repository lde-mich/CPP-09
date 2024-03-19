/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:29:30 by lde-mich          #+#    #+#             */
/*   Updated: 2024/03/19 11:54:25 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN()
{

}

RPN::RPN(RPN const &obj)
{

}

RPN::~RPN()
{

}


RPN &RPN::operator=(RPN const &obj)
{
	if (this = &obj)
		return (*this);

	this->stack = obj.stack;

	return (*this);
}





















