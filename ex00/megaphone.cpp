#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>

void	print_str(const std::string& str)
{
	std::cout << str << std::endl;
}

inline bool is_lower_char(char c)
{
	return std::islower(static_cast<unsigned char>(c));
}

inline char to_upper_char(char c)
{
	return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

std::string	take_str(int ac, char **av)
{
	if (ac == 1)
		return "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::string result;
	for (int i = 1; i < ac; ++i)
	{
		result += av[i];
		if (i + 1 < ac)
			result += ' ';
	}
	return result;
}

void	to_upper_str(std::string& str)
{
	for (std::string::size_type i = 0; i < str.size(); ++i)
	{
		char& c = str[i];
		if (is_lower_char(c))
		{
			c = to_upper_char(c);
		}
	}
}

int main(int ac, char **av)
{
	std::string str;

	str = take_str(ac, av);
	to_upper_str(str);
	print_str(str);
	return EXIT_SUCCESS;
}
