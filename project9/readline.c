//
// COP 3514 – Fall Semester, 2020
//
// Project 9 - readline
//
// Dong Jun Kim
//

#include <stdio.h>
#include <ctype.h>
#include "readline.h"

// gets string and an integer as parameter then reads the string until the nth character
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