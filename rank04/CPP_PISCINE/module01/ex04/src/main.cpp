#include <string>
#include <fstream>
#include <iostream>

namespace	alg
{
	std::string	repalce(const std::string old_str, const std::string s1, const std::string s2)
	{
		size_t	i;
		std::string	new_str = old_str + "\n";
		i = new_str.find(s1);
		if (i == std::string::npos)
			return (new_str);
		new_str.erase(i, s1.length());
		new_str.insert(i, s2);
		return (new_str);
	}
}

void	l(void){system("leaks replace");}

int main(int argc, char **argv)
{
	atexit(l);
	if (argc != 4)
		return (-1);
	std::string		filename = *(argv + 1);
	std::string		s1 = *(argv + 2);
	std::string		s2 = *(argv + 3);
/*-----------------------------------------*/
	std::string		line;
	std::ifstream	src_file(filename.c_str());
	if (!src_file.good())
		return (-1);
	std::ofstream	dst_file(std::string(*(argv + 1)) + ".replace");
	while (std::getline(src_file, line))
		dst_file << alg::repalce(line, *(argv + 2), *(argv + 3));
	src_file.close();
	dst_file.close();
	return (0);
}
