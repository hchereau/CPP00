#include "Contact.hpp"

//default constructor
Contact::Contact() {}

Contact::Contact(const std::string& fn,
					const std::string& ln,
					const std::string& nn,
					const std::string& pn,
					const std::string& secret)
  : firstName(fn),
	lastName(ln),
	nickname(nn),
	phoneNumber(pn),
	darkestSecret(secret)
{}

//Setters
void Contact::setFirstName(const std::string& fn)    { firstName     = fn; }
void Contact::setLastName(const std::string& ln)     { lastName      = ln; }
void Contact::setNickname(const std::string& nn)     { nickname      = nn; }
void Contact::setPhoneNumber(const std::string& pn)  { phoneNumber   = pn; }
void Contact::setDarkestSecret(const std::string& s) { darkestSecret = s; }

// Getters
const std::string& Contact::getFirstName()    const { return firstName; }
const std::string& Contact::getLastName()     const { return lastName; }
const std::string& Contact::getNickname()     const { return nickname; }
const std::string& Contact::getPhoneNumber()  const { return phoneNumber; }
const std::string& Contact::getDarkestSecret()const { return darkestSecret; }
