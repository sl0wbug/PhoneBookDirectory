#include <stdio.h>
#include <string.h>
#include <conio.h>

#define TABLE_SIZE 10
#define EMPTY ""


typedef struct {
    char name[50];
    char phone[15];
    int is_deleted;
} Contact;

Contact hashTable[TABLE_SIZE];


int hashFunction(char *key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return hash % TABLE_SIZE;
}


void insertContact(char *name, char *phone) {
    int index = hashFunction(name);
    int originalIndex = index;

    while (strlen(hashTable[index].name) > 0 && !hashTable[index].is_deleted) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("\033[1;31mHash table is full!\033[0m\n");
            return;
        }
    }
    strcpy(hashTable[index].name, name);
    strcpy(hashTable[index].phone, phone);
    hashTable[index].is_deleted = 0;
    printf("\033[1;32mContact inserted at index %d\033[0m\n", index);
}


void searchContact(char *name) {
    int index = hashFunction(name);
    int originalIndex = index;

    while (strlen(hashTable[index].name) > 0) {
        if (strcmp(hashTable[index].name, name) == 0 && !hashTable[index].is_deleted) {
            printf("\033[1;34mFound: %s -> %s\033[0m\n", hashTable[index].name, hashTable[index].phone);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) break;
    }
    printf("\033[1;31mContact not found!\033[0m\n");
}


void deleteContact(char *name) {
    int index = hashFunction(name);
    int originalIndex = index;

    while (strlen(hashTable[index].name) > 0) {
        if (strcmp(hashTable[index].name, name) == 0 && !hashTable[index].is_deleted) {
            hashTable[index].is_deleted = 1;
            printf("\033[1;33mContact deleted!\033[0m\n");
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) break;
    }
    printf("\033[1;31mContact not found!\033[0m\n");
}


void displayContacts() {
    printf("\n\033[1;36mPhonebook Directory:\033[0m\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (strlen(hashTable[i].name) > 0 && !hashTable[i].is_deleted) {
            printf("\033[1;35mIndex %d: %s -> %s\033[0m\n", i, hashTable[i].name, hashTable[i].phone);
        }
    }
}

int main() {
    int choice;
    char name[50], phone[15];

    while (1) {
        printf("\n\033[1;36m==============================\033[0m\n");
        printf("\033[1;33m       PHONEBOOK MENU        \033[0m\n");
        printf("\033[1;36m==============================\033[0m\n");
        printf("\033[1;32m1. Insert Contact\033[0m\n");
        printf("\033[1;34m2. Search Contact\033[0m\n");
        printf("\033[1;33m3. Delete Contact\033[0m\n");
        printf("\033[1;35m4. Display Contacts\033[0m\n");
        printf("\033[1;31m5. Exit\033[0m\n");
        printf("\033[1;36m==============================\033[0m\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter name: ");
                gets(name);
                printf("Enter phone: ");
                gets(phone);
                insertContact(name, phone);
                break;
            case 2:
                printf("Enter name to search: ");
                gets(name);
                searchContact(name);
                break;
            case 3:
                printf("Enter name to delete: ");
                gets(name);
                deleteContact(name);
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                printf("\033[1;31mExiting program...\033[0m\n");
                return 0;
            default:
                printf("\033[1;31mInvalid choice!\033[0m\n");
        }
    }
}
