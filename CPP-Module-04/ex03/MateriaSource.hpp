/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:18:41 by oroy              #+#    #+#             */
/*   Updated: 2024/02/16 16:45:34 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:

	AMateria	*_materia[4];

public:

	MateriaSource(void);
	MateriaSource(MateriaSource const &src);
	MateriaSource &operator=(MateriaSource const &rhs);
	~MateriaSource(void);

	void		learnMateria(AMateria*);
	AMateria	*createMateria(std::string const &type);

	void		printMateriaList(void) const;
};

#endif