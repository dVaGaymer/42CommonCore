#pragma once
#ifndef __PHONE_BOOK_H__
#define __PHONE_BOOK_H__

#include <string>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_index;

	public:
		PhoneBook();

		void	add();
		void	search();
		void	list();

		void	setContact(Contact c);
		void	setIndex(int index);
		int		getIndex();
};
#endif
