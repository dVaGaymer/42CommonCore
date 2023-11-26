#pragma once
#ifndef __RPN_HPP__
#define __RPN_HPP__

# define RPN_NUMBERS "0123456789"
# define RPN_OPERATIONS "+-*/"
# define RPN_NUMBERS_AND_OPERATIONS "0123456789 +-*/"

# include <stack>
# include <string>
# include <iostream>

class RPN
{
	private:
		std::stack<int>	_operation;
		int				_result;
		RPN();
		RPN(RPN const &o);
		RPN & operator=(RPN const &o);
	public:
		~RPN(){}
		RPN(std::string operation);
		int	getResult(void);
		int	operate(void);
};
#endif

