#pragma once
#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <iostream>
#include <map>

# define LVL_AMMOUNT 4

class Harl
{
	private:
		void	_debug();
		void	_info();
		void	_warning();
		void	_error();

		int		_lvl_n;
		int	_getLvlFunc(std::string level);
		std::string	_lvl_type[LVL_AMMOUNT];
		void (Harl::*_lvl_func[LVL_AMMOUNT])(void);

	public:
		Harl();
		void			complain(std::string level);
};
#endif

