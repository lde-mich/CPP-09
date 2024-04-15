/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:18:27 by lde-mich          #+#    #+#             */
/*   Updated: 2024/04/15 18:01:26 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	
	if (argc < 3)
	{
		std::cerr << "Error → bad input" << std::endl;
		return (0);
	}

	PmergeMe srt;

	try
	{
		
		srt.checkArgs(argv);
		srt.loadArgs(argv);
		
		srt.vectorExecute();
		std::cout << std::endl;
		srt.dequeExecute();

	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);

}
