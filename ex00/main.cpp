/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:53:33 by lde-mich          #+#    #+#             */
/*   Updated: 2024/03/18 10:35:48 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main (int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (0);
	}
	
	BitcoinExchange btc;

	try
	{

		btc.loadFileDatabase("data1.csv");
		btc.loadFileInput(argv[1]);

		btc.checkValue();

		btc.calculateBtc();

	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	return (0);
}


