#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "disemvowel.h"

bool isVowel(char a) {

  char vowels[11] = {'a','e','i','o','u','A','E','I','O','U','X'};
  
  int i=0;

  while(i<11 && a != vowels[i]){
    ++i;
  }

  printf("i is %d\n", i);
  return (i!=11);
}

char* disemvowel(char* str) {
  unsigned int len;
  len = strlen(str);
  char* result;
  unsigned int i = 0;

  
  for (i=0; i<strlen(str);++i) {
    if (isVowel(str[i])) {len=len-1;};
    
  }

  printf("lengthis %d\n", len);

  result = (char*) calloc(len+1, sizeof(char));

  int j=0;
  for (i=0; i<strlen(str); ++i) {
    if (!isVowel(str[i])) {
      result[j] = str[i];
      ++j;
    }
  }
      
  return result;
}


