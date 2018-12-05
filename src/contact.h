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


Contact* createContact(char* text);

void freeContact(void* c);

void printContact(Contact* c);

#endif /* CONTACT_H_ */
