import java.util.ArrayList;
import java.util.Scanner;

public class PhoneBookDirectory {
    static final int MAX_CONTACTS = 100;
    static final int MAX_NAME = 50;
    static final int MAX_PHONE_NUMBERS = 5;
    static final int MAX_PHONE_LENGTH = 15;

    static class PhoneNumber {
        String label;
        String number;

        PhoneNumber(String label, String number) {
            this.label = label;
            this.number = number;
        }
    }

    static class Contact {
        String name;
        ArrayList<PhoneNumber> phoneNumbers;

        Contact(String name) {
            this.name = name;
            this.phoneNumbers = new ArrayList<>();
        }
    }

    static ArrayList<Contact> contacts = new ArrayList<>();
    static Scanner scanner = new Scanner(System.in);

    static void displayContacts() {
        System.out.printf("\n%20s | %s\n", "Name", "Phone Numbers");
        System.out.println("---------------------");
        for (Contact contact : contacts) {
            System.out.printf("%20s | ", contact.name);
            for (PhoneNumber phone : contact.phoneNumbers) {
                System.out.printf("[%s: %s] ", phone.label, phone.number);
            }
            System.out.println();
        }
    }

    static void addContact() {
        if (contacts.size() >= MAX_CONTACTS) {
            System.out.println("Contact list is full!");
            return;
        }

        System.out.print("Enter contact name: ");
        String name = scanner.nextLine();
        Contact newContact = new Contact(name);

        while (newContact.phoneNumbers.size() < MAX_PHONE_NUMBERS) {
            System.out.print("Enter phone label (or 'done' to finish): ");
            String label = scanner.nextLine();
            if (label.equalsIgnoreCase("done")) break;

            System.out.print("Enter phone number: ");
            String number = scanner.nextLine();
            newContact.phoneNumbers.add(new PhoneNumber(label, number));
        }

        contacts.add(newContact);
    }

    public static void main(String[] args) {
        int choice;
        do {
            System.out.println("\n1. Add Contact\n2. Display Contacts\n3. Exit\nChoose an option: ");
            choice = scanner.nextInt();
            scanner.nextLine(); // Clear newline from buffer

            switch (choice) {
                case 1:
                    addContact();
                    break;
                case 2:
                    displayContacts();
                    break;
                case 3:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        } while (choice != 3);

        scanner.close();
    }
}