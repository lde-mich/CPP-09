/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mich <lde-mich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:53:13 by lde-mich          #+#    #+#             */
/*   Updated: 2024/03/15 18:01:23 by lde-mich         ###   ########.fr       */
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

	std::getline(fileCsv, line);
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

	return ;
}

void BitcoinExchange::loadFileInput(std::string const &filename)
{
	std::ifstream fileInput(filename.c_str());

	if (!fileInput.is_open())
		throw BitcoinExchange::ErrorFileException();

	std::string line;
	
	std::getline(fileInput, line);
	if (line != "date | value")
		throw BitcoinExchange::UnsuitableFileException();

	struct tm tm;

	while (std::getline(fileInput, line))
	{
        std::stringstream ss(line);
        std::string key;
		std::string valueStr;

		std::getline(ss, key, '|');
		std::string date(key, 0, 10);
        std::getline(ss, valueStr, '|');

		if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		this->input.insert(std::make_pair(key, atof(valueStr.c_str())));
	}

	fileInput.close();

	return ;
}


void BitcoinExchange::calculateBtc()
{
	std::multimap<std::string, float>::iterator it;
	std::map<std::string, float>::iterator jt;

	for(it = this->input.begin(); it != this->input.end(); ++it)
	{
		for (jt = this->database.begin(); jt != this->database.end(); ++jt)
		{
			//std::cout << "input->"<< it->first << "-- " << "databse-->"<< jt->first << std::endl;
			if (jt->first == it->first)
				std::cout << it->first << "=>" << it->second << jt->second << std::endl;
		}
    }

	return ;
}


















