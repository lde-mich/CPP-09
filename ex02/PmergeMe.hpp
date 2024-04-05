/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:19:12 by lde-mich          #+#    #+#             */
/*   Updated: 2024/04/04 12:04:24 by lde-mich         ###   ########.fr       */
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
		std::vector<int> restVector;
		
		std::deque<int> deque;
		std::deque<int> restDeque;

	public:
		
		void checkArgs(char** argv);
		void loadArgs(char** argv);
		
		void firstStepVector(int pairsize);
		void secondStepVector(std::vector<int> vec, int pairsize);
		
		void printVector(std::vector<int> arr);
		int getSize(std::vector<int> arr);
		std::vector<int> getVector();

		void vectorExecute();

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

