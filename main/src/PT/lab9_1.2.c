#include <stdio.h>
#include <stdint.h>

/*
 * Write a function which, given a string (char array terminated by '\0'),
 * returns the set of lowercase letters that appear in the string. The set is represented as a 32-bit
 * integer value (enough for the 26 lower-case letters of the alphabet). In main, use the returned value
 * to print in alphabetical order all lowercase letters appearing in the string.
 */

void printSet(int32_t set)
{
  for (int i = 0; i < 26; i++)
  {
    if (set & 1 << i)
      putchar(i + 'a');
  }
  putchar('\n');
}

int32_t lowercaseSet(char arr[])
{
  int32_t set = 0u;

  for (int i = 0; arr[i] != '\0'; i++)
  {
    unsigned letter = arr[i] - 'a';
    if (0 <= letter && letter < 26)
    {
      set = set | 1 << letter;
    }
  }

  return set;
}

int main(){
    printSet(lowercaseSet("ana has apples and doesn't want to eat them"));
    printf("%d\n", lowercaseSet("aeiou"));

    return 0;
}
