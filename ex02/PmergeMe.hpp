/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:19:12 by lde-mich          #+#    #+#             */
/*   Updated: 2024/04/15 17:23:36 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <cctype>
#include <stdlib.h> 
#include <algorithm>

class PmergeMe
{
	private:

		std::vector<int> vector;
		std::vector<int> mainVector;
		std::vector<int> pendVector;
		std::vector<int> restVector;
		

		std::deque<int> deque;
		std::deque<int> mainDeque;
		std::deque<int> pendDeque;
		std::deque<int> restDeque;

	public:
		
		void checkArgs(char** argv);
		void loadArgs(char** argv);
		
		//VECTOR
		void firstStepVector(int pairsize);
		void secondStepVector(int pairsize);
		int searchToDoVector(int num, std::vector<int>& arr) const;
		void printVector(std::vector<int> arr);
		int getSizeVector(std::vector<int> arr) const;
		std::vector<int> &getVector();
		void insertRestVector();
		void vectorExecute();

		//DEQUE
		void firstStepDeque(int pairsize);
		void secondStepDeque(int pairsize);
		int searchToDoDeque(int num, std::deque<int>& arr) const;
		void printDeque(std::deque<int> arr);
		int getSizeDeque(std::deque<int> arr) const;
		std::deque<int> &getDeque();
		void insertRestDeque();
		void dequeExecute();


		PmergeMe &operator=(PmergeMe const &obj);
		PmergeMe();
		PmergeMe(PmergeMe const &obj);
		~PmergeMe();


		class InvalidInputException: public std::exception
        {
            public:
                virtual const char	*what() const throw()
				{
					return ("Error → invalid input");
				};
        };
};

