/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:28:34 by lde-mich          #+#    #+#             */
/*   Updated: 2024/03/20 17:51:37 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <utility>
#include <limits>
#include <stack>

class RPN
{
	private:
		
		std::stack<int> stack;

	public:

		void calculator(char* argv);

		RPN &operator=(RPN const &obj);

		RPN();
		RPN(RPN const &obj);
		~RPN();

};




