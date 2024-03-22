/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:18:57 by lde-mich          #+#    #+#             */
/*   Updated: 2024/03/22 15:01:13 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(PmergeMe const &obj)
{
	(*this) = obj;
}

PmergeMe::~PmergeMe()
{

}


PmergeMe &PmergeMe::operator=(PmergeMe const &obj)
{
	if (this == &obj)
		return (*this);

	this->vector = obj.vector;
	this->deque = obj.deque;

	return (*this);
}


void PmergeMe::printVector(std::vector<int> arr)
{
	int i = -1;
	while (arr[++i])
		std::cout << "-" << arr[i];
	std::cout << "" << std::endl;

	return ;
}

int PmergeMe::getSize(std::vector<int> arr)
{
	return (arr.size());
}


void PmergeMe::checkArgs(char** argv)
{
	int j = 1;
	int i = 0;

	while(argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (!isdigit(argv[j][i]))
				throw PmergeMe::InvalidInputException();
			i++;
		}
		j++;
	}
}


void PmergeMe::loadArgs(char** argv)
{
	int j = 1;

	while (argv[j])
	{
		this->vector.push_back(atoi(argv[j]));
		this->deque.push_back(atoi(argv[j]));
		j++;
	}
}


void PmergeMe::firstStepVector(std::vector<int> arr, int pairsize)
{	
	if (arr.size() % 2 == 0)
	{
		if (pairsize >= getSize(arr))
			return;

		int i = 0;
		while (arr[i])
		{
			if (arr[i] < arr[i + 1])
				std::swap(arr[i], arr[i + 1]);
			i += pairsize;
		}
		firstStepVector(arr, pairsize * 2);
	}
}













