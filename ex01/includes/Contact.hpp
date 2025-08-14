
#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact(); // default constructor

		Contact(const std::string& fn,
			const std::string& ln,
			const std::string& nn,
			const std::string& pn,
			const std::string& secret);

		// Setters
		void setFirstName     (const std::string& fn);
		void setLastName      (const std::string& ln);
		void setNickname      (const std::string& nn);
		void setPhoneNumber   (const std::string& pn);
		void setDarkestSecret (const std::string& secret);

		// Getters
		const std::string& getFirstName     () const;
		const std::string& getLastName      () const;
		const std::string& getNickname      () const;
		const std::string& getPhoneNumber   () const;
		const std::string& getDarkestSecret () const;
};

#endif
