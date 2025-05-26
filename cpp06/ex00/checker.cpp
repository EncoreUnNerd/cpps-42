#include <string>
#include <cerrno>
#include <climits>
#include <cstdlib>

bool check_int(std::string literal)
{
	char	*endptr;
	long	result;

	errno = 0;
	result = strtol(literal.c_str(), &endptr, 10);
	if (*endptr != '\0' || result < INT_MIN || result > INT_MAX)
		return (false);

	if (errno == ERANGE)
		return (false);

	return (true);
}

bool check_float(std::string literal)
{
	char	*endptr;
	float	result;

	errno = 0;
	result = strtof(literal.substr(0, literal.length()-1).c_str(), &endptr);
	(void)result;
	if (*endptr != '\0')
		return (false);

	if (errno == ERANGE)
		return (false);

	return (true);
}

bool check_double(std::string literal)
{
	char	*endptr;
	double	result;

	errno = 0;
	result = strtod(literal.c_str(), &endptr);
	(void)result;
	if (*endptr != '\0')
		return (false);

	if (errno == ERANGE)
		return (false);

	return (true);
}
