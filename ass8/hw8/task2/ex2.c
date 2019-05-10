/* Example: analysis of text */

#include <stdio.h>
#include <string.h>

#define MAX 1000 /* The maximum number of characters in a line of input */

int main()
{
  char text[MAX], c;
  int i, j;
  int lowercase, uppercase, digits, other, palindrome;
  #define realfgetslen(str) strlen(str)/sizeof(char)-2
  
  //Get string from user
  puts("Enter a string:");
  fgets(text, MAX, stdin);
  
  //Calculate length, print reverse, calculate palindrome 
  puts("Reverse of the string is :-");
  for (palindrome = 1, i = 0, j = realfgetslen(text); j >= 0; i++, j--) {
    printf("%c", text[j]);
    if(i < j)
      if(text[i] != text[j])
        palindrome = 0;
  }

  /* Analyse contents of text[]: */
  for (i = lowercase = uppercase = digits = other = 0; i < strlen(text)/sizeof(char); i++)
  {
    c = text[i];
    if (c >= 'a' && c <= 'z')
      lowercase++;
    else if (c >= 'A' && c <= 'Z')
      uppercase++;
    else if (c >= '0' && c <= '9')
      digits++;
    else
    {
      if (c == '\n')
        break;
      other++;
    }
  }

  puts("\n\nYou typed:");
  printf("A string with %lu characters\n", realfgetslen(text)+1);
  printf("\t%d lower case letters\n", lowercase);
  printf("\t%d upper case letters\n", uppercase);
  printf("\t%d digits\n", digits);
  printf("\t%d others\n", other);
  printf("\t%s palindrome\n", palindrome ? "Yes" : "No");
}
