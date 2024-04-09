/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:18:57 by lde-mich          #+#    #+#             */
/*   Updated: 2024/04/09 22:41:19 by lde-mich         ###   ########.fr       */
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

void PmergeMe::insertionSortUsingJacobsthal(std::vector<int>& arr)
{
		int i = 1;
        while (i < getSize(arr))
		{
            int key = arr[i];
            int j = i - 1;

            // Trova la posizione corretta per inserire l'elemento attuale
            while (j >= 0 && jacobsthal[arr[j]] > jacobsthal[key])
			{
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;

			i++;
        }
}

void PmergeMe::binaryInsert(std::vector<int>& arr, int num, int left, int right)
{
	int mid = (left + right) / 2;

	if (num < arr[mid])
        binaryInsert(arr, num, left, right / 2);
    else if (num > arr[mid])
	{
		left = mid + 1;
        binaryInsert(arr, num, left, right);
	}
    else
        arr.insert(arr.begin() + mid, num);
	
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

	std::cout << "Vector " << ++rr << " →    ";
    printVector(getVector());
	
    this->pendVector.push_back(this->vector[pairsize / 2]);
	this->mainVector.push_back(this->vector[pairsize / 2]);

    int i = pairsize / 2 + 1;
	this->mainVector.push_back(this->vector[i]);
	
    while (i < pairsize)
	{
        this->pendVector.push_back(this->vector[i]);
        i++;
    }

    i = 0;
	this->mainVector.push_back(this->vector[i]);
	
    while (i < pairsize / 2)
	{
        this->pendVector.push_back(this->vector[i]);
        i++;    
    }

	if (pairsize != getSize(this->vector))
	{
		i = pairsize;
		this->mainVector.push_back(this->vector[i]);
		
		while (i < pairsize + pairsize / 2)
		{
			this->pendVector.push_back(this->vector[i]);
			i++;    
		}

		int last = 3;
		for (int i = 0; i < 33; i++)
		{
			if (jacobsthal[i] == last)
				continue;
			
			int jacob = jacobsthal[i];
			while (jacob > getSize(this->vector) / (pairsize / 2))
				jacob--;
			
			// indice del main della futura coppia
			int index = (jacob - 1) * pairsize / 2;
			
			// TODO: funzione che accetta un numero:(this->vector[index]), un array e restituisce l'indice di dove andare ad inserire il numero nell'array
			// array da passare alla funzione: mainVector
			// l'indice ritornato dalla funzione, sarà moltiplicato per pairsize / 2
			
			//int tmp = indice ritornato dalla funzione moltiplicato per pairsize / 2
			
			this->mainVector.insert(this->vector.begin() + indice ritornato dalla funzione, this->vector[index]);
			while (index < jacob * pairsize / 2)
			{
				this->pendVector.insert(this->vector.begin() + tmp, this->vector[index]);
				index++;
			}
			
		}
	}
	this->vector = this->pendVector;

	std::cout << "Pend →        "; 
    printVector(this->pendVector);
	std::cout << "--------------" << std::endl;

    this->pendVector.clear();
	
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

	std::cout << "second →      "; 
    printVector(this->vector);
	std::cout << "-----------------------------------------------" << std::endl;

	// // Ordina pendVector utilizzando la serie di Jacobsthal come chiave
	// insertionSortUsingJacobsthal(this->vector);
	
}
