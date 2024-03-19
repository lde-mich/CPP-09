/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:16:17 by lde-mich          #+#    #+#             */
/*   Updated: 2024/03/19 14:31:05 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error, invalid input" << std::endl;
		return (0);
	}

	int i = -1;
	while (argv[1][++i])
	{
		if (!std::isdigit(argv[1][i]) && (argv[1][i] != '+' && argv[1][i] != '-'
					&& argv[1][i] != '*' && argv[1][i] != '/' && argv[1][i] != 32))
		{
			std::cout << "Error" << std::endl;
			return (0);
		}
	}

	try
	{
		
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
