/*Adeliya Tislova
The program uses dinamically allocated linked list to keep records of all volunteers.
Information can be inserted, searched, printed, and cleared by the user.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define EMAIL_LEN 100
#define NAME_LEN 30

struct volunteer{
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];
	int grade_level;
	struct volunteer *next;
};


struct volunteer *add_to_list(struct volunteer *list);
void search_list(struct volunteer *list);
void print_list(struct volunteer *list);
void clear_list(struct volunteer *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct volunteer *volunteer_list = NULL;  
  printf("Operation Code: a for adding to the list, s for searching"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': volunteer_list = add_to_list(volunteer_list);
                break;
      case 's': search_list(volunteer_list);
                break;
      case 'p': print_list(volunteer_list);
                break;
      case 'q': clear_list(volunteer_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

//Prompt the user and add new volunteer to the ned of the list
struct volunteer *add_to_list(struct volunteer *list) {
  int grade;
  char last_name[NAME_LEN + 1];
  char first_name[NAME_LEN + 1];
  char email[EMAIL_LEN + 1];

  printf("Enter last name: ");
  read_line(last_name, NAME_LEN);

  printf("Enter first name: ");
  read_line(first_name, NAME_LEN);

  printf("Enter email address: ");
  read_line(email, EMAIL_LEN);

  printf("Enter grade level: ");
  scanf("%d", &grade);
  while (getchar() != '\n');

  struct volunteer *new_node;
  struct volunteer *p;
  struct volunteer *last;

  //Allocate memory for the new_node that will be inserted in the end
  new_node = malloc(sizeof(struct volunteer));
  if (new_node == NULL) {
    printf("Memory allocation error.\n");
    return list;
  }

  //Traverse the linked list and find existing volunteer
  for (p = list; p != NULL; p = p->next) {
    if (strcmp(p->last, last_name) == 0 && strcmp(p->email, email) == 0) { //Compare last names and emails
      printf("volunteer already exists.\n");
      free(new_node);
      return list;
    }
  }

  //Insert inputted data into the new_node
  strcpy(new_node->first, first_name);
  strcpy(new_node->last, last_name);
  strcpy(new_node->email, email);
  new_node->grade_level = grade;
  new_node->next = NULL;

  //If the list is empty return new_node
  if (list == NULL) {
    return new_node;
  }

  //Append a new_node to the end
  last = list;
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = new_node;

  return list;

}

//Find volunteers by grade level
void search_list(struct volunteer *list) {
  int grade;
  int flag = 0;
  struct volunteer *p;

  //Propmt the user
  printf("Enter grade level: ");
  scanf("%d", &grade);
  while (getchar() != '\n');

  //Traverse the linked list
  for (p = list; p != NULL; p = p->next) {
    if (p->grade_level == grade) { //Compare grade levels
      printf("%-12s%-12s%-30s\n", p->last, p->first, p->email);
      flag = 1;
    }
  }

  //Case if there are no such volunteers
  if (!flag) {
        printf("not found\n");
    }

} 

//Print all existing volunteers
void print_list(struct volunteer *list) {
  struct volunteer *p;
  for (p = list; p != NULL; p = p->next) {
    printf("%-12s%-12s%-30s%5d\n", p->last, p->first, p->email, p->grade_level);
  }
}

//Deallocate all allocated memory for the list
void clear_list(struct volunteer *list)
{
  struct volunteer *p; //Declare another pointer to safely free memory
  while (list != NULL) {
    p = list;
    list = list->next;
    if (p != NULL) {
      free(p);
    }
  }

}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}
