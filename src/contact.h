/*
 * contact.h
 *
 *  Created on: Nov 27, 2018
 *      Author: lcbattelle
 */

#ifndef CONTACT_H_
#define CONTACT_H_

// Contact Struct will hold all information about one contact
typedef struct contact{
	char* lastName;
	char* firstName;
	char* email;
	char* phoneNumber;
} Contact;

// Creates a contact from text
Contact* createContact(char* text);

// Used by the linked list
void freeContact(void* c);

// Compares two contacts
// Returns 1 if data1 > data2, 0 if data1 == data2 and 2 if data1 < data2
int compareContact(void* data1, void* data2);

// Prints all contacts with proper formatting
void printContact(Contact* c);

#endif /* CONTACT_H_ */
