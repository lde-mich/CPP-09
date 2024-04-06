/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:18:57 by lde-mich          #+#    #+#             */
/*   Updated: 2024/04/06 16:16:08 by lde-mich         ###   ########.fr       */
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

size_t jacobsthal[] =
{
    3u, 5u, 11u, 21u, 43u, 85u, 171u, 341u, 683u, 1365u,
    2731u, 5461u, 10923u, 21845u, 43691u, 87381u, 174763u, 349525u, 699051u,
    1398101u, 2796203u, 5592405u, 11184811u, 22369621u, 44739243u, 89478485u,
    178956971u, 357913941u, 715827883u, 1431655765u,
    2863311531u, 5726623061u, 11453246123u
};

void PmergeMe::binaryInsert(std::vector<int> arr, int num)
{
	(void) arr;
	(void) num;
}

void PmergeMe::printVector(std::vector<int> arr)
{
	int i = 0;
	std::cout << "| ";
	while (i < getSize(arr))
	{
		std::cout << arr[i] << " | ";
		i++;
	}
	std::cout << "\n" << std::endl;

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
	static int rr;
	
	if (pairsize > getSize(this->vector))
		return;

	int i = 0;
	while (i < getSize(this->vector))
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

	std::cout << "Step " << ++rr << " →      ";
	printVector(getVector());
	firstStepVector(pairsize * 2);

}

void PmergeMe::secondStepVector(int pairsize)
{
	static int rr;
	if (pairsize <= 2)
		return;

	this->pendVector.push_back(this->vector[pairsize / 2]);

	int i = pairsize / 2 + 1;
	while (i < pairsize)
	{
		this->pendVector.push_back(this->vector[i]);
		i++;
	}

	i = 0;
	while (i < pairsize / 2)
	{
		this->pendVector.push_back(this->vector[i]);
		i++;	
	}

	this->vector = this->pendVector;

	std::cout << "Step " << ++rr << " →      ";
	printVector(getVector());
	std::cout << "Pend →        "; 
	printVector(this->pendVector);
	exit(1);
	
	secondStepVector(pairsize / 2);
}


//EXECUTE

void PmergeMe::vectorExecute()
{
	
	std::cout << "Start →       "; 
	printVector(getVector());
	
	std::cout << "-----------------------------------------------\n" << std::endl;
	std::cout << "First step:"<< std::endl;
	firstStepVector(2);
	std::cout << "-----------------------------------------------\n" << std::endl;
	
	std::cout << "Second step:"<< std::endl;
	secondStepVector(getSize(this->vector));
	std::cout << "-----------------------------------------------" << std::endl;
	
}


