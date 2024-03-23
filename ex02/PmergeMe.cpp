/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:18:57 by lde-mich          #+#    #+#             */
/*   Updated: 2024/03/23 14:55:25 by lde-mich         ###   ########.fr       */
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
	if (getSize(this->vector) % 2 == 0)
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
		firstStepVector(pairsize * 2);
	}
}













