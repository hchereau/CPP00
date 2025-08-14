#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	: totalContacts(0), nextIndex(0)
{}

std::string PhoneBook::promptNonEmpty(const std::string& message) const
{
	std::string	s;
	do
	{
		std::cout << message;
		if (!std::getline(std::cin, s))
		{
			return std::string();
		}
	} while (s.empty());
	return s;
}

Contact	PhoneBook::getContact() const
{
	const std::string	fn		= promptNonEmpty("First Name     :");
	const std::string	ln		= promptNonEmpty("Last Name      :");
	const std::string	nn		= promptNonEmpty("Nickname       :");
	const std::string	pn		= promptNonEmpty("Phone Number   :");
	const std::string	secret	= promptNonEmpty("Darkest secret :");

	return Contact	(fn, ln, nn, pn, secret);
}

void	PhoneBook::insertContact(const Contact& c)
{
	contacts[nextIndex] = c;
	nextIndex = (nextIndex + 1) % MAX_CONTACTS;
	if (totalContacts < MAX_CONTACTS)
		++totalContacts;
}

void	PhoneBook::addContact()
{
	Contact c = getContact();
	if (std::cin.eof())
	{
		std::cout << "\nEOF detected. Returning to menu. \n";
		std::cin.clear();
		return ;
	}
	if (c.getFirstName().empty() && c.getLastName().empty() && c.getNickname().empty()
		&& c.getPhoneNumber().empty()
		&& c.getDarkestSecret().empty())
		return ;
	insertContact(c);
}


// searchContact

namespace {
	static std::string fit10(const std::string& s) {
		if (s.size() <= 10) return s;
		return s.substr(0, 9) + ".";
	}
	static bool parseIndex(const std::string& s, std::size_t& out) {
		std::istringstream iss(s);
		long v; char extra;
		if (!(iss >> v) || (iss >> extra) || v < 0) return false;
		out = static_cast<std::size_t>(v);
		return true;
	}
	static void printRow(std::size_t idx, const Contact& c) {
		std::cout << std::setw(10) << idx << '|'
				  << std::setw(10) << fit10(c.getFirstName()) << '|'
				  << std::setw(10) << fit10(c.getLastName())  << '|'
				  << std::setw(10) << fit10(c.getNickname())  << '\n';
	}
}

void PhoneBook::searchContact() const
{
	if (totalContacts == 0) {
		std::cout << "PhoneBook is empty.\n";
		return;
	}
	std::cout << std::setw(10) << "Index"      << '|'
			  << std::setw(10) << "First Name" << '|'
			  << std::setw(10) << "Last Name"  << '|'
			  << std::setw(10) << "Nickname"   << '\n';
	for (std::size_t i = 0; i < totalContacts; ++i)
		printRow(i, contacts[i]);
	std::cout << "Enter the index of the contact to display: ";
	std::string line;
	if (!std::getline(std::cin, line))
		return;
	std::size_t idx = 0;
	if (!parseIndex(line, idx) || idx >= totalContacts) {
		std::cout << "Invalid index.\n";
		return;
	}
	const Contact& c = contacts[idx];
	std::cout << "First Name     : " << c.getFirstName()    << '\n'
			  << "Last Name      : " << c.getLastName()     << '\n'
			  << "Nickname       : " << c.getNickname()     << '\n'
			  << "Phone Number   : " << c.getPhoneNumber()  << '\n'
			  << "Darkest secret : " << c.getDarkestSecret()<< '\n';
}
