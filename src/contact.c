/*
 * contact.c
 *
 *  Created on: Nov 27, 2018
 *      Author: lcbattelle
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "contact.h"




// Creates a contact struct from one line of text
Contact* createContact(char* text){

	// comma1 points to first comma in string
	char* comma1 = strstr(text, ",");

	// lName is allocated to hold the Last Name
	char* lName = malloc((sizeof(char) * (comma1-text)) +1);

	// copy the last name from text into lName
	strncpy(lName, text, comma1-text);

	// Null terminator
	lName[comma1-text] = '\0';
	//printf("lName: %s   length: %d\n", lName, strlen(lName));


	//--------------------------------------------------------------------
	// Increment comma1 so that it now points to the first letter in fName
	char* comma2 = strstr(++comma1, ",");

	// fName is allocated to hold first name
	char * fName = malloc((sizeof(char) * (comma2-comma1)) +1);

	// copy the first name into fName
	strncpy(fName, comma1, comma2-comma1);

	// Null terminator
	fName[comma2-comma1] = '\0';
	//printf("fName: %s   length: %d\n", fName, strlen(fName));


	//-------------------------------------------------------------------
	// Increment comma2 so that it now points to the first letter in email
	char* comma3 = strstr(++comma2, ",");

	// fName is allocated to hold first name
	char * email = malloc((sizeof(char) * (comma3-comma2)) +1);

	// copy the first name into fName
	strncpy(email, comma2, comma3-comma2);

	// Null terminator
	email[comma3-comma2] = '\0';
	//printf("email: %s   length: %d\n", email, strlen(email));


	//--------------------------------------------------------------------
	// Increment comma3 so that it now points to the first letter in phoneNumber
	char* newLine = strstr(++comma3, "\n");

	// fName is allocated to hold first name
	char * phoneNumber = malloc((sizeof(char) * (newLine-comma3)) +1);

	// copy the first name into fName
	strncpy(phoneNumber, comma3, newLine-comma3);

	// Null terminator
	phoneNumber[newLine-comma3] = '\0';
	//printf("phoneNumber: %s   length: %d\n", phoneNumber, strlen(phoneNumber));


	//------------------------------------------------------------------------
	//Creates a new contact Object and returns it
	Contact* tempContact = malloc(sizeof(Contact));
	tempContact->lastName = lName;
	tempContact->firstName = fName;
	tempContact->email = email;
	tempContact->phoneNumber = phoneNumber;

	return tempContact;
}

void freeContact(void* c){
	// Frees all contact values and then frees the contact itself
	Contact* deleted = (Contact*)c;
	free(deleted->firstName);
	free(deleted->lastName);
	free(deleted->email);
	free(deleted->phoneNumber);
	free(deleted);
}

// prints contact information
void printContact(Contact* c){
	printf("%s,%s,%s,%s\n", c->lastName, c->firstName, c->email, c->phoneNumber);
}
