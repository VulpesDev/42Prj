/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:12:43 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/03 13:14:30 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"


void	replace_copy(std::ifstream *input_file, std::ofstream *output_file,
						std::string s1, std::string s2)
{
	std::string line;
	while (std::getline(*input_file, line))
	{
		size_t	pos;
		pos = line.find(s1);
		if (pos != std::string::npos)
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
		*output_file << line << std::endl;
	}
}

int	sed_func(std::string filename,
					std::string s1,
						std::string s2)
{
		std::ifstream	input_file(filename);
		std::ofstream	output_file(filename+".replace", std::ios::app);
		
		if (!input_file)
		{
			std::cerr << "Error input file." << std::endl;
			return (1);
		}
		if (!output_file)
		{
			std::cerr << "Error output file." << std::endl;
			return (1);
		}
		
		replace_copy(&input_file, &output_file, s1, s2);
		input_file.close();
		output_file.close();

		return (0);
}
