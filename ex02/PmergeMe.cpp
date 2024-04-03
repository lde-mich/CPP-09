/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:18:57 by lde-mich          #+#    #+#             */
/*   Updated: 2024/04/03 17:33:09 by lde-mich         ###   ########.fr       */
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



//UTILS

void PmergeMe::printVector(std::vector<int> arr)
{
	int i = 0;
	std::cout << "| ";
	while (i < getSize(arr))
	{
		std::cout << arr[i] << " | ";
		i++;
	}
	std::cout << std::endl;

	return ;
}

int PmergeMe::getSize(std::vector<int> arr)
{
	return (arr.size());
}


std::vector<int> PmergeMe::getVector()
{
	return (this->vector);
}



//CHECK

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



//SORT

void PmergeMe::firstStepVector(int pairsize)
{
	if (pairsize > getSize(this->vector))
		return;

	int i = 0;
	while (this->vector[i])
	{
		if (this->vector[i] < this->vector[i + pairsize / 2])
		{
			std::swap(this->vector[i], this->vector[i + pairsize / 2]);
			
			int j = 1;
			while (j < pairsize / 2)
			{
				std::swap(this->vector[j + i], this->vector[j + i + (pairsize / 2)]);
				j++;
			}
		}
		i += pairsize;
	}
	std::cout << "Step →        ";
	printVector(getVector());
	
	firstStepVector(pairsize * 2);
}

void PmergeMe::secondStepVector(int pairsize)
{
	std::vector<int> mainVector;
	std::vector<int> pendVector;

	if (pairsize < 2)
		return;
		
	int i = pairsize;
	if (i == getSize(this->vector))
	{
		std::cout << "main → " << i << std::endl;
		mainVector.push_back(i);
	}
	while (this->vector[i])
	{		
		int j = 1;
		while (j < pairsize / 2)
		{
			std::cout << "pend → " << (j + i + (pairsize / 2)) << std::endl;
			pendVector.push_back(j + i + (pairsize / 2));
			j++;
		}
		
		i -= pairsize;
	}
	secondStepVector(pairsize / 2);
}



//EXECUTE

void PmergeMe::vectorExecute()
{
	
	std::cout << "Start →       "; 
	printVector(getVector());
	
	firstStepVector(2);
	std::cout << "First step →  ";
	printVector(getVector());
	
	secondStepVector(getSize(this->vector));
	std::cout << "Second step → ";
	printVector(getVector());
	
}












