#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 11

// Define the Contact structure
typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

// Function declarations
void addContact(Contact contacts[], int *contactCount);
void viewContacts(Contact contacts[], int contactCount);
void searchContact(Contact contacts[], int contactCount);
void deleteContact(Contact contacts[], int *contactCount);

int main() {
    Contact contacts[MAX_CONTACTS];
    int contactCount = 0;
    int choice;

    while (1) {
        // Display menu
        printf("\nContact List Manager\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &contactCount);
                break;
            case 2:
                viewContacts(contacts, contactCount);
                break;
            case 3:
                searchContact(contacts, contactCount);
                break;
            case 4:
                deleteContact(contacts, &contactCount);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a contact
void addContact(Contact contacts[], int *contactCount) {
    if (*contactCount >= MAX_CONTACTS) {
        printf("Contact list is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", contacts[*contactCount].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[*contactCount].phone);

    (*contactCount)++;
    printf("Contact added successfully.\n");
}

// Function to view all contacts
void viewContacts(Contact contacts[], int contactCount) {
    if (contactCount == 0) {
        printf("No contacts to display.\n");
        return;
    }

    for (int i = 0; i < contactCount; i++) {
        printf("Contact %d\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
    }
}

// Function to search for a contact by name
void searchContact(Contact contacts[], int contactCount) {
    char name[NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

// Function to delete a contact by name
void deleteContact(Contact contacts[], int *contactCount) {
    char name[NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < *contactCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*contactCount)--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}