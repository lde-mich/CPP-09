/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:53:33 by lde-mich          #+#    #+#             */
/*   Updated: 2024/03/14 15:28:00 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main (int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error, bad input" << std::endl;
		return (0);
	}
	
	BitcoinExchange btc;

	try
	{
		btc.loadFileDatabase("data.csv");
		btc.loadFileInput(argv[1]);
		std::cout << "__________________\n" <<std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	return (0);
}


