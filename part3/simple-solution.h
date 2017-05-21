#ifndef SIMPLE_SOLUTION_H
#define SIMPLE_SOLUTION_H

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>

/* Structure that holds the name and birthday information of a person. */
struct birthday {
	int month;
	int day;
	int year;
  char *name;
  struct list_head list;
};

/**
* Function that initializes the linked list and makes the parameter element the head of the list.
*
* @param headBirthday
*	  The passed in element that is the head of the linked list.
* @param name
*   The name of the person
* @param day
*   The day of the birthday
* @param month
*   The month of the birthday.
* @param year
*   The year of the birthday
**/
void createHead(struct birthday* head, char* name, int day, int month, int year);

/**
* Fills in the details of the birthday element and adds it to the linked list.
* @param newBirthday
*	  The element that is being added to the list
* @param name
*   The name of the person
* @param int day
*	  The day of the birthday.
* @param int month
*	  The month of the birthday.
* @param int year
*	  The year of the birthday.
**/
void createNewBirthdayAndAddToList(struct birthday* newBirthday, char* name, int day, int month, int year);

/**
* Function that calls on the for_each_entry macro 
* for traversal and extends it for output. **/
void traverseList(void);

/**
* Utilizes the for_each_entry_safe macro to delete the elements from the list as well as signal its deletion to the user.
**/
void deleteElementsFromList(void);

#endif
