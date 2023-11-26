#include "Contact.hpp"

Contact::Contact(): _id(0){}

Contact::Contact(std::string firstName,
	std::string lastName,
	std::string nickname,
	std::string phoneNumber,
	std::string secret):
_firstName(firstName),
_lastName(lastName),
_nickname(nickname),
_phoneNumber(phoneNumber),
_secret(secret)
{}

bool	Contact::isEmpty()
{
	return (this->_id == 0);
}

void	Contact::askInfo(int id)
{
	this->_id = id;
	std::string	firstName, lastName, nickname, phoneNumber, secret;
	std::cout << "First Name: (cannot be empty)\n";
	while (firstName.empty())
		std::getline(std::cin, firstName);
	this->_firstName = firstName;
	std::cout << "Last Name: (cannot be empty)\n";
	while (lastName.empty())
		std::getline(std::cin, lastName);
	this->_lastName = lastName;
	std::cout << "Nickname: (cannot be empty)\n";
	while (nickname.empty())
		std::getline(std::cin, nickname);
	std::cout << "Phone Number: (cannot be empty)\n";
	this->_nickname = nickname;
	while (phoneNumber.empty())
		std::getline(std::cin, phoneNumber);
	this->_phoneNumber = phoneNumber;
	std::cout << "Darkest Secret: (cannot be empty)\n";
	while (secret.empty())
		std::getline(std::cin, secret);
	this->_secret = secret;
}

void	Contact::setId(int id) {this->_id = id;}

std::string	Contact::_format(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9).append("."));
	else
		return (std::string(10 - str.length(), ' ').append(str));
}

void	Contact::printBasicInfo()
{
	std::cout << _format(std::to_string(this->_id)) << "|";
	std::cout << _format(this->_firstName) << "|";
	std::cout << _format(this->_lastName) << "|";
	std::cout << _format(this->_nickname) << "\n";
}

void	Contact::printCompleteInfo()
{
	std::cout << "-------------------------------------------------\n";
	std::cout << "First Name: " << this->_firstName << "\n";
	std::cout << "Last Name: " << this->_lastName << "\n";
	std::cout << "nickname: " << this->_nickname << "\n";
	std::cout << "Phone Number: " << this->_phoneNumber << "\n";
	std::cout << "Darkest Secret: " << this->_secret << "\n";
	std::cout << "-------------------------------------------------\n";
}
