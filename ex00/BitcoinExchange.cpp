/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:53:13 by lde-mich          #+#    #+#             */
/*   Updated: 2024/03/14 15:02:05 by lde-mich         ###   ########.fr       */
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


BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &obj)
{
	if (this == &obj)
		return (*this);

	this->database = obj.database;
	this->input = obj.input;

	return (*this);
}



void BitcoinExchange::loadFileDatabase(std::string const &filename)
{
	std::ifstream fileCsv(filename.c_str());

	if (!fileCsv.is_open())
		throw BitcoinExchange::ErrorFileException();

	float value;
	std::string line;
	while (std::getline(fileCsv, line))
	{
        std::stringstream ss(line);
        std::string key;
		std::string valueStr;

		std::getline(ss, key, ',');
        std::getline(ss, valueStr, ',');

		value = std::atof(valueStr.c_str());
		this->database[key] = value;
	}

	fileCsv.close();
	std::cout << "load .csv success"<< std::endl;

	return ;
}

void BitcoinExchange::loadFileInput(std::string const &filename)
{
	std::ifstream fileInput(filename.c_str());

	if (!fileInput.is_open())
		throw BitcoinExchange::ErrorFileException();

	float value;
	std::string line;
	while (std::getline(fileInput, line))
	{
        std::stringstream ss(line);
        std::string key;
		std::string valueStr;

		std::getline(ss, key, ',');
        std::getline(ss, valueStr, ',');

		value = std::atof(valueStr.c_str());
		this->database[key] = value;
	}

	fileInput.close();
	std::cout << "load .txt success"<< std::endl;

	return ;
}







