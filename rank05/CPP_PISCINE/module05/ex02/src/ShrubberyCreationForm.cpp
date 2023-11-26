#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	:AForm("", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &o)
	:AForm(o) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
	:AForm(target, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &o)
{ (void)o; return (*this); }

//TODO: Should I automate the tree creation?
//I probably will, but no now
void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	AForm::execute(executor);
	std::string	file_name = this->getName() + "_shrubbery";

	std::ofstream	out_file(file_name.c_str());

	out_file << "                       O\n";
	out_file << "                      ***\n";
	out_file << "                     **O**\n";
	out_file << "                    *******\n";
	out_file << "                   *********\n";
	out_file << "                  ***********\n";
	out_file << "                   ******o**\n";
	out_file << "                  ***********\n";
	out_file << "                 ****o********\n";
	out_file << "                ***************\n";
	out_file << "               ****o***o********\n";
	out_file << "              *******************\n";
	out_file << "            ***********************\n";
	out_file << "               *****O***********\n";
	out_file << "              **********o********\n";
	out_file << "             ****************o****\n";
	out_file << "            **O********************\n";
	out_file << "           ***********o********O****\n";
	out_file << "         *****************************\n";
	out_file << "             *********************\n";
	out_file << "            ***o*******************\n";
	out_file << "           ***********o*******o*****\n";
	out_file << "          ***************************\n";
	out_file << "         ***********************O*****\n";
	out_file << "        ***O***************************\n";
	out_file << "      ***********************************\n";
	out_file << "           *************************\n";
	out_file << "          *******o********o**********\n";
	out_file << "         *****************************\n";
	out_file << "        **************o****************\n";
	out_file << "       *************************O*******\n";
	out_file << "      *****O*****************************\n";
	out_file << "    **************o************************\n";
	out_file << "          ***************************\n";
	out_file << "         *************o***************\n";
	out_file << "        ***********o*******************\n";
	out_file << "       **************************O******\n";
	out_file << "      ***o******************O************\n";
	out_file << "    ***o***********o****************o******\n";
	out_file << "                      ###\n";
	out_file << "                      ###\n";
	out_file << "                      ###\n";
	out_file << "                  ###########\n";
	out_file << "                  ###########   \n";
	out_file.close();
	std::cout << file_name << " created.\n";
}
