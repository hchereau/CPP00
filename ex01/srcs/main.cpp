#include "PhoneBook.hpp"

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nEOF detected. Exiting.\n";
			break;
		}
		if (command == "ADD")
		{
			phoneBook.addContact();
		}
		else if (command == "SEARCH")
		{
			phoneBook.searchContact();
		}
		else if (command == "EXIT")
		{
			std::cout << "Goodbye!\n";
			break;
		}
		else if (!command.empty())
		{
			std::cout << "Unknown command.\n";
		}
	}
	return 0;
}
