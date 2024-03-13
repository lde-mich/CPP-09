/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:53:13 by lde-mich          #+#    #+#             */
/*   Updated: 2024/03/13 18:02:53 by lde-mich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj)
{
	(*this) = obj;
}

BitcoinExchange::~BitcoinExchange()
{

}


BitcoinExchange BitcoinExchange::operator=(BitcoinExchange const &obj)
{
	if (this == &obj)
		return (*this);

	this->database = obj.database;
	this->input = obj.input;

	return (*this);
}















