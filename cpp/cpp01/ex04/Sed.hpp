/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:12:51 by tvasilev          #+#    #+#             */
/*   Updated: 2023/05/03 12:35:05 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP
# include <string>
# include <iostream>
# include <fstream>

int	sed_func(std::string filename,
					std::string s1,
						std::string s2);
#endif