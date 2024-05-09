/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:15:27 by olivierroy        #+#    #+#             */
/*   Updated: 2024/02/16 16:15:31 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	int		total = 3;
	AAnimal	**animals = new AAnimal*[total];

	std::cout << std::endl;
	std::cout << "--- Array Construction ---" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < (total / 2); i++)
		animals[i] = new Dog();
	for (int i = (total / 2); i < total; i++)
		animals[i] = new Cat();

	std::cout << std::endl;
	std::cout << "--- Array Printing ---" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < total; i++)
		animals[i]->makeSound();

	std::cout << std::endl;
	std::cout << "--- Array Destruction ---" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < total; i++)
		delete animals[i];
	delete [] animals;

	std::cout << std::endl;
	std::cout << "--- Deep Copy Test - Dog ---" << std::endl;
	std::cout << std::endl;

	Dog *doggy1 = new Dog();
	Dog *doggy2 = new Dog(*doggy1);
	Dog *doggy3 = new Dog();
	
	std::cout << std::endl;
	std::cout << "doggy1 idea = " << doggy1->getBrainIdea() << std::endl;
	std::cout << "doggy2 idea = " << doggy2->getBrainIdea() << std::endl;

	doggy2->setBrainIdeas("Hello");

	std::cout << "doggy1 idea = " << doggy1->getBrainIdea() << std::endl;
	std::cout << "doggy2 idea = " << doggy2->getBrainIdea() << std::endl;
	std::cout << "doggy3 idea = " << doggy3->getBrainIdea() << std::endl;
	std::cout << std::endl;

	*doggy3 = *doggy2;

	std::cout << std::endl;
	std::cout << "doggy2 idea = " << doggy2->getBrainIdea() << std::endl;
	std::cout << "doggy3 idea = " << doggy3->getBrainIdea() << std::endl;
	std::cout << std::endl;

	delete doggy1;
	delete doggy2;
	delete doggy3;

	std::cout << std::endl;
	std::cout << "--- Deep Copy Test - Cat ---" << std::endl;
	std::cout << std::endl;

	Cat *kitty1 = new Cat();
	Cat *kitty2 = new Cat(*kitty1);
	Cat *kitty3 = new Cat();
	
	std::cout << std::endl;
	std::cout << "kitty1 idea = " << kitty1->getBrainIdea() << std::endl;
	std::cout << "kitty2 idea = " << kitty2->getBrainIdea() << std::endl;

	kitty2->setBrainIdeas("What's up");

	std::cout << "kitty1 idea = " << kitty1->getBrainIdea() << std::endl;
	std::cout << "kitty2 idea = " << kitty2->getBrainIdea() << std::endl;
	std::cout << "kitty3 idea = " << kitty3->getBrainIdea() << std::endl;
	std::cout << std::endl;

	*kitty3 = *kitty2;

	std::cout << std::endl;
	std::cout << "kitty2 idea = " << kitty2->getBrainIdea() << std::endl;
	std::cout << "kitty3 idea = " << kitty3->getBrainIdea() << std::endl;
	std::cout << std::endl;

	delete kitty1;
	delete kitty2;
	delete kitty3;

	return 0;
}
