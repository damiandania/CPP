/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:58:25 by ddania-c          #+#    #+#             */
/*   Updated: 2024/03/21 12:53:10 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "Colors.h"

#define NB_IDEAS 100

class	Brain {
	private:
		std::string	_ideas[NB_IDEAS];

		void	addIdeas(std::string const type);

	public:
		Brain(std::string const type);
		Brain(Brain const & source);
		~Brain(void);

		std::string	getIdea(int i) const;

		Brain &	operator=(Brain const & source);

};

#endif
