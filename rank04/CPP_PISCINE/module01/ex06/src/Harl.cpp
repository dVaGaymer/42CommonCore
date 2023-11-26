#include "Harl.hpp"

Harl::Harl()
	:_lvl_n(LVL_AMMOUNT)
{
	this->_lvl_type[0] = "DEBUG"; this->_lvl_func[0] = &Harl::_debug;
	this->_lvl_type[1] = "INFO"; this->_lvl_func[1] = &Harl::_info;
	this->_lvl_type[2] = "WARNING"; this->_lvl_func[2] = &Harl::_warning;
	this->_lvl_type[3] = "ERROR"; this->_lvl_func[3] = &Harl::_error;
}

int	Harl::_getLvlFunc(std::string level)
{
	for (int i = 0; i < this->_lvl_n; i++)
		if (!level.compare(this->_lvl_type[i]))
			return (i);
	return (-1);
}

void	Harl::complain(std::string level)
{
	int opt = this->_getLvlFunc(level);
	switch(opt)
	{
		case 0:
			(this->*_lvl_func[0])();
		case 1:
			(this->*_lvl_func[1])();
		case 2:
			(this->*_lvl_func[2])();
		case 3:
			(this->*_lvl_func[3])();
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}

void	Harl::_debug()
{
	std::cout << "[DEBUG]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << "\n";
}
void	Harl::_info()
{
	std::cout << "[INFO]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << "\n";
}
void	Harl::_warning()
{
	std::cout << "[WARNING]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << "\n";
}
void	Harl::_error()
{
	std::cout << "[ERROR]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now." << "\n";
}
