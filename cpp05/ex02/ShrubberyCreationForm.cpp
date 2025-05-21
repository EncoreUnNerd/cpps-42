#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include <string>

const std::string &ShrubberyCreationForm::getTarget()
{
	return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getRExec())
		throw AForm::GradeTooLowException();
	std::ofstream	outputfile(_target + "_shrubbery");
	if (!outputfile.is_open())
		throw std::runtime_error("Could not create shrubbery file");

	outputfile << "            .        +          .      .          ." << std::endl;
	outputfile << "     .            _        .                    ." << std::endl;
	outputfile << "  ,              /;-._,-.____        ,-----.__" << std::endl;
	outputfile << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
	outputfile << "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
	outputfile << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
	outputfile << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
	outputfile << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
	outputfile << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
	outputfile << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
	outputfile << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
	outputfile << "              \\:  `  X` _| _,\\/'   .-'" << std::endl;
	outputfile << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
	outputfile << "                    \\::.  :\\/:'  /              +" << std::endl;
	outputfile << "   .                 `.:.  /:'  }      ." << std::endl;
	outputfile << "           .           ):_(:;   \\           ." << std::endl;
	outputfile << "                      /:. _/ ,  |" << std::endl;
	outputfile << "     .                |::.    {\\      " << std::endl;
	outputfile << "                      |::.\\  \\ `." << std::endl;
	outputfile << "                      |:::(\\    |" << std::endl;
	outputfile << "              O       |:::/{ }  |                  (o" << std::endl;
	outputfile << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
	outputfile << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\/~w|/~" << std::endl;
	outputfile << "dew   ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~" << std::endl;

	outputfile.close();
}



// --- Constructors ---

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("Unknown Target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &to_copy): AForm("ShrubberyCreationForm", 145, 137), _target(to_copy._target) {}

// --- Destructor ---

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// --- Operator ---

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &to_copy)
{
	_target = to_copy._target;
	return (*this);
}
