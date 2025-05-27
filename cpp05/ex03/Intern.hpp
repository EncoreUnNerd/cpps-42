#include "AForm.hpp"

class Intern
{
	public:
		AForm *makeForm(std::string name, std::string target);

		Intern &operator=(Intern &to_copy);

		Intern();
		Intern(Intern &to_copy);
		~Intern();
};
