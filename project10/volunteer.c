#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_line.h"
#include "volunteer.h"

//Prompt the user and add new volunteer to the end of the list
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

//Delete volunteer from the list
struct volunteer *delete_from_list(struct volunteer *list) {
    int grade;
    char last_name[NAME_LEN + 1];
    char first_name[NAME_LEN + 1];
    char email[EMAIL_LEN + 1];

    //Take input from the user
    printf("Enter last name: ");
    read_line(last_name, NAME_LEN);

    printf("Enter first name: ");
    read_line(first_name, NAME_LEN);

    printf("Enter email address: ");
    read_line(email, EMAIL_LEN);

    printf("Enter grade level: ");
    scanf("%d", &grade);
    while (getchar() != '\n');

    struct volunteer *c, *p;

    //Use loop to compare input with the database
    for (c = list, p = NULL; c != NULL; p = c, c = c->next) {
        if (strcmp(c->last, last_name) == 0 && strcmp(c->first, first_name) == 0 &&
            strcmp(c->email, email) == 0 && c->grade_level == grade) {
                if (p == NULL) {
                    list = c->next; //Update the beginning of the list
                }
                else {
                    p->next = c->next; //Update the previous node
                }
                free(c); //Free memory
                return list;
        }
    }

    printf("volunteer does not exist\n");
    return list;

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