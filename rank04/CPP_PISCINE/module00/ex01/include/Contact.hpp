#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>
#include <iostream>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;	
		std::string	_secret;
		int	 		_id;

		static std::string	_format(std::string str);

	public:
		Contact();
		Contact(std::string firstName,
			std::string lastName,
			std::string nickname,
			std::string phoneNumber,
			std::string secret);
		bool	isEmpty();
		void	printCompleteInfo();
		void	printBasicInfo();
		void	askInfo(int id);
		void	setId(int id);
};

#endif
