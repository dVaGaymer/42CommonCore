#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook():
	_index(0)
{}

void	PhoneBook::setIndex(int index)
{
	this->_index = index; 
}
int		PhoneBook::getIndex()
{
	this->_contacts[this->_index].printBasicInfo(); return this->_index;
}

void	PhoneBook::setContact(Contact c)
{
	if (this->_index == 8)
		this->_index = 0;
	c.setId(this->_index + 1);
	this->_contacts[this->_index] = c;
	this->_index++;
}

void	PhoneBook::add()
{
	if (this->_index == 8)
		this->_index = 0;
	this->_contacts[this->_index].askInfo(this->_index + 1);
	this->_index++;
}

void	PhoneBook::list()
{
	std::cout << "     index|first name| last name|  nickname\n";
	for(int i = 0; i < 8; i++)
		if (!this->_contacts[i].isEmpty())
			this->_contacts[i].printBasicInfo();
}

void	PhoneBook::search()
{
	int	opt;
	this->list();
	std::cin >> opt;
	if (1 > opt || 8 < opt)
	{
		std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid.\n";
		return ;
	}
	this->_contacts[opt - 1].printCompleteInfo();
}
