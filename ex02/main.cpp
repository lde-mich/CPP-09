/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:18:27 by lde-mich          #+#    #+#             */
/*   Updated: 2024/03/22 14:40:03 by lde-mich         ###   ########.fr       */
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
	
	(void ) argv;
	std::vector<int> arr;

	arr.push_back(4);
	arr.push_back(8);
	arr.push_back(5);
	arr.push_back(7);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(9);
	
	try
	{
		//srt.checkArgs(argv);
		//srt.loadArgs(argv);
		srt.firstStepVector(arr ,2);
		srt.printVector(arr);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}


	return (0);
}


