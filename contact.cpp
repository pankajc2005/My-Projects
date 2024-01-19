#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Contact
{
  std::string name;
  std::string phone;
  std::string email;
};

// New Contact Adding
void addContact(std::vector<Contact> &contacts)
{
  Contact newContact;
  std::cout << "Enter name for the Contact: ";
  std::cin >> newContact.name;
  std::cout << "Enter phone number: ";
  std::cin >> newContact.phone;
  std::cout << "Enter email address: ";
  std::cin >> newContact.email;
  contacts.push_back(newContact);
  std::cout << "Contact added to the Database." << std::endl;
}

// Contact no Display
void displayContacts(const std::vector<Contact> &contacts)
{
  for (const auto &contact : contacts)
  {
      std::cout << "Name: " << contact.name << ", Phone no: "
                << contact.phone << ", Email id: " << contact.email << std::endl;
  }
}

// Contact no Search
void searchContact(const std::vector<Contact> &contacts)
{
  std::string searchTerm;
  std::cout << "Enter Contact name to search: ";
  std::cin >> searchTerm;

  bool found = false;
  for (const auto &contact : contacts)
  {
      if (contact.name == searchTerm)
      {
          std::cout << "Name: " << contact.name << ", Phone no: "
                    << contact.phone << ", Email id: " << contact.email << std::endl;
          found = true;
          break;
      }
  }

// Contact Error
  if (!found)
  {
      std::cout << "Contact not found." << std::endl;
  }
}

// Contact Delete
void deleteContact(std::vector<Contact> &contacts)
{
  std::string nameToDelete;
  std::cout << "Enter name of contact to delete: ";
  std::cin >> nameToDelete;

  auto it = std::remove_if(contacts.begin(), contacts.end(), [&](const Contact &contact)
                            { return contact.name == nameToDelete; });

  if (it != contacts.end())
  {
      contacts.erase(it, contacts.end());
      std::cout << "Contact deleted." << std::endl;
  }
  else
  {
      std::cout << "Contact not found." << std::endl;
  }
}

// Main Display
int main()
{
  std::vector<Contact> contacts;
  int choice;

  do
  {
      std::cout << "\n1. Add New Contact" << std::endl;
      std::cout << "2. Display All Contacts" << std::endl;
      std::cout << "3. Search a Contact" << std::endl;
      std::cout << "4. Delete a Contact" << std::endl;
      std::cout << "5. Exit the session" << std::endl;
      std::cout << "Enter your choice from the above option: ";
      std::cin >> choice;

      switch (choice)
      {
      case 1:
          addContact(contacts);
          break;
      case 2:
          displayContacts(contacts);
          break;
      case 3:
          searchContact(contacts);
          break;
      case 4:
          deleteContact(contacts);
          break;
      case 5:
          break;
      default:
          std::cout << "Invalid choice." << std::endl;
      }
  } while (choice != 5);

  return 0;
}
