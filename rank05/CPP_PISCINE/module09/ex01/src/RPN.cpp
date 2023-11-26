#include "RPN.hpp"

static bool	isValidNum(int n)
{
	return (n >= 0 && n <= 9);
}

static bool isOp(char c)
{
	return (std::string(RPN_OPERATIONS).find(c) != std::string::npos);
}

static bool isValid(char c)
{
	return (std::string(RPN_NUMBERS_AND_OPERATIONS).find(c) != std::string::npos);
}

static int	poptop(std::stack<int> & st)
{
	int	n = st.top();
	st.pop();
	return (n);
}

static int doOperation(char n1, char n2, char op)
{
	if (!isOp(op))
		throw std::runtime_error("Error.");
	if (op == '*')
		return (n1 * n2);
	if (op == '/')
		return (n1 / n2);
	if (op == '-')
		return (n1 - n2);
	if (op == '+')
		return (n1 + n2);
	return (0);
}

RPN::RPN(std::string operation)
{
	std::string::iterator	itb = operation.begin();
	std::string::iterator	ite = operation.end();
	for (; itb != ite; itb++)
	{
		while (*itb == ' ' && itb != ite) itb++;
		if (itb == ite) break;
		if (!isValid(*itb) || (isValidNum(*itb - 48) && isValidNum(*(itb + 1) - 48)))
			throw std::runtime_error("Error");
		if (!isOp(*itb))
			this->_operation.push(*itb - 48);
		else if (isOp(*itb))
		{
			if (this->_operation.size() < 2)
				throw std::runtime_error("Error");
			this->_operation.push(doOperation(poptop(this->_operation), poptop(this->_operation), *itb));
		}
	}
	if (this->_operation.size() != 1)
		throw std::runtime_error("Error");
	this->_result = this->_operation.top();
}

int RPN::getResult()
{
	return (this->_result);
}
