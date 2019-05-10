#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  /* Zero out the array */
  int letter_frequency[26] = {0};
  int len, i;
  char buf[MAX_BUF], t[MAX_BUF]; 
  /*t for extra temporary array, t is used to overcome fgets() 
  overwriting the array with each call*/

  printf("Enter statement for letters to be counted\nPress Enter to Exit...\n");
  do {
    //Keyboard_IN into t, t concatted to buf
    fgets( t, MAX_BUF, stdin );
    strcat(buf, t);

    //printf("t[0]: %c, len: %u \n", t[0], strlen(t) / sizeof(char));
  } while(strlen(t)/sizeof(char) > 1);
  
  //strlen() returns #-of-bits...
  for( len = strlen(buf)/sizeof(char); len > 0; len-- ) {
    for(i = 0; i < 26; i++) {

      if(buf[len] == 'A'+i)
        letter_frequency[ i ] += 1;
      else if(buf[len] == 'a'+i)
        letter_frequency[ i ] += 1;
    }
  }
  
  printf("Distribution of letters in corpus:\n");
  for (i = 0; i < 26; i++) {
    // 'A' is ASCII code 65
    printf("%c/%c: %d\n", 65+i, 65+i+32, letter_frequency[i]);
  }
}
