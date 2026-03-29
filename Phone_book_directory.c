# Improved Phone Book Directory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME 50
#define MAX_PHONE_NUMBERS 5
#define MAX_PHONE_LENGTH 15

typedef struct {
    char label[20];
    char number[MAX_PHONE_LENGTH];
} PhoneNumber;

typedef struct {
    char name[MAX_NAME];
    PhoneNumber phoneNumbers[MAX_PHONE_NUMBERS];
    int phoneCount;
} Contact;

Contact contacts[MAX_CONTACTS];
int contactCount = 0;

void displayContacts() {
    printf("\n%20s | %s\n", "Name", "Phone Numbers");
    printf("%s\n", "---------------------");
    for (int i = 0; i < contactCount; i++) {
        printf("%20s | ", contacts[i].name);
        for (int j = 0; j < contacts[i].phoneCount; j++) {
            printf("[%s: %s] ", contacts[i].phoneNumbers[j].label, contacts[i].phoneNumbers[j].number);
        }
        printf("\n");
    }
}

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }
    Contact newContact;
    printf("Enter contact name: ");
    fgets(newContact.name, MAX_NAME, stdin);
    newContact.name[strcspn(newContact.name, "\n")] = 0;  // Remove newline
    newContact.phoneCount = 0;

    while (newContact.phoneCount < MAX_PHONE_NUMBERS) {
        PhoneNumber newPhone;
        printf("Enter phone label (or 'done' to finish): ");
        fgets(newPhone.label, sizeof(newPhone.label), stdin);
        newPhone.label[strcspn(newPhone.label, "\n")] = 0; // Remove newline
        if (strcmp(newPhone.label, "done") == 0) break;
        printf("Enter phone number: ");
        fgets(newPhone.number, MAX_PHONE_LENGTH, stdin);
        newPhone.number[strcspn(newPhone.number, "\n")] = 0; // Remove newline
        newContact.phoneNumbers[newContact.phoneCount++] = newPhone;
    }
    contacts[contactCount++] = newContact;
}

int main() {
    int choice;
    do {
        printf("\n1. Add Contact\n2. Display Contacts\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);
        getchar();  // Clear newline from buffer

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayContacts();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
