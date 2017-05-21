/*
* Name: Daniel Burkhart
* Assignment: Practice Project, part 3
* Class: Operating Systems
* Date: 1-19-17
*/

#include "simple-solution.h"


/* The following defines and initializes a list_head object named birthday_list */
static LIST_HEAD(birthday_list);

/* Five variables that will be elements of our linked list */
struct birthday* daniel;
struct birthday* john;
struct birthday* joey;
struct birthday* ryan;
struct birthday* brad;

/* Init method that is called when the module is loaded to the kernel. */
int simple_init(void)
{
    printk (KERN_INFO "***Loading Module***");

    createHead(daniel, "Daniel Burkhart", 18, 12, 1993);
    createNewBirthdayAndAddToList(john, "John", 5, 6, 1987);
    createNewBirthdayAndAddToList(joey, "Joey", 11, 12, 1980);
    createNewBirthdayAndAddToList(ryan, "Ryan", 13, 12, 1989);
    createNewBirthdayAndAddToList(brad, "Brad", 15, 8, 1982);

    traverseList();
    return 0;
}

/* Function that creates head of linked list and populates the attributes of the element. */
void createHead(struct birthday* head, char* name, int day, int month, int year){  
    head = kmalloc(sizeof(struct birthday), GFP_KERNEL);
    head->name = name;
    head->day = day;
    head->month = month;
    head->year = year;

    INIT_LIST_HEAD(&head->list);
    list_add_tail(&head->list, &birthday_list);
}

/* Populates attributes of birthday element and adds it to linked list. */
void createNewBirthdayAndAddToList(struct birthday* newBirthday, char* name, int day, int month, int year){
    
    newBirthday = kmalloc(sizeof(struct birthday), GFP_KERNEL);
    newBirthday->name = name;
    newBirthday->day = day;
    newBirthday->month = month;
    newBirthday->year = year;

    list_add_tail(&newBirthday->list, & birthday_list);
}

/* Traverses list. Extension of list_for_each_entry macro provided by list.h */
void traverseList(void){
    struct birthday* ptr;
    
    list_for_each_entry(ptr, &birthday_list, list) {   
        printk(KERN_INFO "Name: %s Birthday: Day: %d, Month: %d, Year: %d", ptr->name, ptr->day, ptr->month, ptr->year);
    }
}

/* Exit method called when module is removed from kernel. */
void simple_exit(void) {
    printk(KERN_INFO "***Removing Module***");
    deleteElementsFromList();
}

/* Deletes elements from list and frees allocated memory. Extension of linux macro. */
void deleteElementsFromList(void){
    struct birthday* currElement;
    struct birthday* next;
    
    list_for_each_entry_safe(currElement, next, &birthday_list, list) { 
        printk(KERN_INFO "Removing: Name: %s Birthday: Day: %d, Month: %d, Year: %d", currElement->name, currElement->day, currElement->month, currElement->year);
        list_del(&currElement->list);
        kfree(currElement);
    }
}

module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Kernel Data Structures");
MODULE_AUTHOR("SGG");