/*
 ============================================================================
 Name        : LBattelleAdressBook.c
 Author      : Lucas Battelle
 Description : Hello World in C, Ansi-style
 ============================================================================

    Add a new contact:
        Code:  a
        First parameter:  0-based index where the new contact should be inserted.  0 would mean in front of the first contact in the list, 1 would mean in front of the second contact in the list, and so on.  This value will not be greater than the current number of contacts in the address book.
        Second parameter: String containing a comma delimited list of contact property values.  The order is last_name, first_name, email, phone_number
        Example:
        a
        1
        SMITH,AUNDREA,asmith@ign.com,8001110001

    Delete a contact:
        Code:  d
        First parameter:  0-based index of the contact to delete.  NOTE:  if the index is higher than the number of contacts - 1, do nothing.
        Example:
        d
        1

    Get a contact:
        Code: g
        First parameter:  0-based index of the contact.
        Example:
        g
        1
        Output to stdout: The value of the requested field, terminated with a \n.  E.g. "WILSON,HORACE,hwilson@mayoclinic.com,8001110008\n"

    Get a field:
        Code: f
        First parameter:  0-based index of the contact.
        Second parameter: Name of the field to get.  Valid values are firstName, lastName, email, phoneNumber.
        Example:
        f
        1
        lastName
        Output to stdout: The value of the requested field, terminated with a \n.  E.g. "SMITH\n"

    Get the number of contacts in the list:
        Code: n
        Example:
        n
        Output to stdout:  The number of contacts in the list, terminated with a \n.  E.g. "10\n".

    Load a file:
        Code: l
        First parameter:  path of the file to load.
        Notes: The file format is CSV.  There is one header line that describes the fields, then one contact per line thereafter.  The order of the contact information is the same as that of the second parameter of the add command.  If the address book is not empty, this command adds the loaded contacts at the end of the current list.  Here is an example file  (note: if you want to see what's in this file, open it in a buffer editor rather than a spreadsheet program).
        Example:
        l
        mycontacts.csv

    Save the contacts to a file:
        Code: s
        First parameter:  path of the file to save to.
        Notes:  The file format is CSV, one contact per line.  If the file already exists, it is overwritten.
        Example:
        s
        mycontacts.csv

    Quit program:
        Code: q
        Example:
        q
        Output to stdout:  "Complete\n"

    (EXTRA CREDIT)  Edit a contact:
        Code:  e
        First parameter:  0-based index of the contact that is to be changed.
        Second parameter: Name of the field to edit.  Valid values are firstName, lastName, email, phoneNumber.
        Third parameter: new value of the field.
        Example:
        e
        3
        phoneNumber
        8002220001

    (EXTRA CREDIT)  Sort the contacts:
        Code: o
        Notes:  Sort order is ascending based on last name, then first name, then email, then phone number.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "contact.h"
#include "linkedlist.h"

int main(void) {
	// Battelle,Lucas,lucasbatelle@gmail.com,8054038952
	char buffer[1000];

	LinkedList* contactList = createList(&freeContact);
	if(!contactList){
		printf("Invalid freeFunc input to createList\n");
	}

	puts("ready\n");
	char userCommand[100];

	while(userCommand[0] != 'q'){
		fgets(userCommand, 100, stdin);

		// Add new contact to list
		if(userCommand[0] == 'a'){
			int index = atoi(fgets(buffer, 999, stdin));
			fgets(buffer, 999, stdin);
			Contact* temp = createContact(buffer);
			if(temp){
				int result = add(contactList, temp, index);
				printf("Add result: %d\n", result);
			}
		}

		// Gets item from list
		else if(userCommand[0] == 'g'){
			int index = atoi(fgets(buffer, 999, stdin));
			Contact* found = get(contactList, index);
			if(found){
				printContact(found);
			}

		}

		// Deletes item from list
		else if(userCommand[0] == 'd'){
			int index = atoi(fgets(buffer, 999, stdin));
			int result = delete(contactList, index);
			printf("Delete result: %d\n", result);

		}

		// Gets specific field from item in list at index n
		else if(userCommand[0] == 'f'){
			int index = atoi(fgets(buffer, 999, stdin));
			fgets(buffer, 999, stdin);
			Contact* found = get(contactList, index);
			if(found){
				if(strstr(buffer, "firstName")){
					printf("%s\n", found->firstName);

				} else if(strstr(buffer, "lastName")){
					printf("%s\n", found->lastName);

				} else if(strstr(buffer, "email")){
					printf("%s\n", found->email);

				} else if(strstr(buffer, "phoneNumber")){
					printf("%s\n", found->phoneNumber);
				}
			}
		}

		else if(userCommand[0] == 's'){

		}
	}

	return EXIT_SUCCESS;
}


