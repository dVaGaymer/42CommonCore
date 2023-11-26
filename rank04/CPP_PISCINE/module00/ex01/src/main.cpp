#include "PhoneBook.hpp"
#include "Contact.hpp"

void	testInit(PhoneBook &p);

int	main(void)
{
	PhoneBook	p;
	bool		run = true;
	std::string	opt;

	testInit(p);
	while (run)
	{
		std::cout << "ADD SEARCH EXIT \n";
		std::cin >> opt;
		if (opt.compare("ADD")
				&& opt.compare("SEARCH")
				&& opt.compare("EXIT"))
			continue ;
		else if (!opt.compare("EXIT"))
			run = false;
		else if (!opt.compare("SEARCH"))
			p.search();
		else if (!opt.compare("ADD"))
			p.add();
	}
	return (0);
}

void	testInit(PhoneBook &p)
{
	//1
	p.setContact(Contact("Alvaro",
			"Lopez",
			"dVaGaymer",
			"+34684367012",
			"IT IS TO DARK TO REVEAL"));
	//2
	p.setContact(Contact("Pedro",
			"Miras",
			"P3dro",
			"+34636",
			"Likes cats"));
	//3
	p.setContact(Contact("Algarpe",
			"Garcia",
			"Alfonso",
			"+34644",
			"Likes ***"));
	//4
	p.setContact(Contact("Paco",
			"Gomez",
			"Pagolo200000",
			"+34***",
			"Likes POKEMON"));
	//5
	p.setContact(Contact("Jesus",
			"Gallego",
			"dside",
			"+34789",
			"Likes you"));
	//6
	p.setContact(Contact("Adela",
			"Lario",
			"Alfonso",
			"+34321654",
			"Hates overwatch"));
	//7
	p.setContact(Contact("Kat",
			"Per",
			"Alfonso",
			"+347171224",
			"Likes Teresa"));
	//8
	p.setContact(Contact("Cristina",
			"Molina",
			"WOOOOOOOOOMAAAAAAAAAAAAANNNNNNNN",
			"+34684367012",
			"LIKES BIRDS"));
	//9 -> 1
	p.setContact(Contact("Fri",
			"Mora",
			"Juanfra",
			"+34648",
			"Hates Serrano"));
}
