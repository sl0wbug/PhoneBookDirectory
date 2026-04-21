#lets try on python
class PhoneNumber:
    def __init__(self, label, number):
        self.label = label
        self.number = number

class Contact:
    def __init__(self, name):
        self.name = name
        self.phone_numbers = []

    def add_phone_number(self, label, number):
        if len(self.phone_numbers) < 5:
            self.phone_numbers.append(PhoneNumber(label, number))
        else:
            print("Maximum of 5 phone numbers per contact reached.")

class PhoneBook:
    def __init__(self):
        self.contacts = []

    def add_contact(self, name):
        if len(self.contacts) < 100:
            self.contacts.append(Contact(name))
        else:
            print("Maximum of 100 contacts reached.")

    def display_contacts(self):
        if not self.contacts:
            print("No contacts available.")
            return
        
        print("Contacts:")
        for contact in self.contacts:
            print(f'Name: {contact.name}')
            for phone_number in contact.phone_numbers:
                print(f'  {phone_number.label}: {phone_number.number}')

    def menu(self):
        while True:
            print("1. Add Contact")
            print("2. Display Contacts")
            print("3. Exit")
            choice = input("Choose an option: ")

            if choice == '1':
                name = input("Enter the name of the contact: ")
                self.add_contact(name)
                while True:
                    label = input("Enter the label (e.g., Home, Work) for phone number: ")
                    number = input("Enter the phone number: ")
                    self.contacts[-1].add_phone_number(label, number)
                    more = input("Add another phone number? (yes/no): ")
                    if more.lower() != 'yes':
                        break
            elif choice == '2':
                self.display_contacts()
            elif choice == '3':
                break
            else:
                print("Invalid choice. Please try again.")

# Example usage
if __name__ == '__main__':
    phone_book = PhoneBook()
    phone_book.menu()
