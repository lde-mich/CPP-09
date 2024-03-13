/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:52:55 by lde-mich          #+#    #+#             */
/*   Updated: 2024/03/13 17:17:53 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class BitcoinExchange
{
	private:

		std::map<std::string, float> database;
		std::multimap<std::string, float> input;

	public:

		BitcoinExchange &operator=(BitcoinExchange const &obj);

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &obj);
		~BitcoinExchange();


		class BadInputException: public std::exception
        {
            public:
                virtual const char	*what() const throw()
				{
					return ("Error, bad input");
				};
        };

};





