#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
5. URL encoding (Percent-encoding). In URLs, several characters including &, =, $, ?, etc. have special meaning. 
If a URL contains these as normal characters, they must be represented (encoded) differently. The percent encoding does this with three characters: 
a percent % and the two hexadecimal digits of the character's ASCII code. For example, the dot '.' character has code 0x2E,
 thus is encoded as %2E (or %2e, case is ignored). The percent character itself (ASCII code 0x25) is encoded as %25.
  For simplicity, we will assume that all non-alphanumeric characters must be percent-encoded.
a) Encode. Write a function that takes a null-terminated string, an array of bytes (characters) and its length and percent-encodes as much of the string as fits,
 ending it with '\0'. Use bitwise operators to extract the hexadecimal digits of a character that must be encoded.
b) Decode. Write a function that takes a null-terminated string, an array of characters and its length and percent-decodes as much of the text as fits. 
If a percent character is not followed by two hexadecimal digits, stop decoding. Always end the decoded string with '\0'. 
Use bitwise operators to assemble a character that was encoded.
*/

void encode(char* s){
    int size=sizeof(s);
    for (int i = 0; s[i]!='\0'; i++)
    {
      if (!isalnum(s[i]))
      {
        for (int j = i+4; j<size+3-i; j++)
        {
          s[j]=s[i+1];
        }
        s[i+1];//
        s[i]='%';
        
      }
      
    }
    
}

void decode(char* s){

}

int main(){
    char* string = "www.google.com/&?idk/";
    encode(string);
    decode(string);
    return 0;
}