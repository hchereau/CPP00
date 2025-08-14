#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <cstddef>
# include <iostream>
# include <iomanip>
# include <sstream>

#include "Contact.hpp"

class PhoneBook
{
	private:
		static const int	MAX_CONTACTS = 8;
		std::size_t			totalContacts;
		std::size_t 		nextIndex;
		Contact				contacts[MAX_CONTACTS];
		std::string			promptNonEmpty(const std::string& message) const;
		void				insertContact(const Contact& c);
		Contact				getContact() const;

	public:
		PhoneBook();
		void		addContact();
		void		searchContact() const;
};

#endif
