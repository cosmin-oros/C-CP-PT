#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *5. The SubRip file format is one of the most basic of all subtitle
 *formats. A text file with ".srt" extension consists of several entries
 *of the form:
 *(a) A numeric counter
 *(b) The time that the subtitle should appear on the screen, followed by "–>" and the time it should disappear
 *(c) Subtitle text itself on one or more lines
 *(d) A blank line containing no text, indicating the end of this
 *subtitle
 */

/* assignment */

/*
 *Write a program to parse the ".srt" text file, remove the text formatting tags and shift the timings with a number of seconds given as
 *command line arguments. Use fscanf () in order to parse the time.
 */

/* --- function for removing text formatting tags --- */
void removeTags(FILE* f){
    char* remove1 = "<i>";
    char* remove2 = "</i>"; 
    char * text = (char*)malloc(sizeof(char) * 400);

    fread(text, sizeof(char), 400, f);
    // printf("%s",text);

    int sizeText = strlen(text);
    int sizeWord1 = strlen(remove1);
    int sizeWord2 = strlen(remove2);
    
    char* p = text;
    while (p)
    {    
    p = strstr(text,remove1);
    if(p)
    {
        //The position of the original text
        int pos = (p - text);

        // Increment the pointer to go in the end of the word to remove
        p = p + sizeWord1;                
        
        // Search in the phrase and copy char per char
        int i;
        for(i = 0; i < strlen(p); i++)
        {
            text[pos + i] = p[i]; 
        }
        // Set the "new end" of the text               
        text[pos + i] = 0x00;      
    } 
    p = strstr(text,remove2);
    if(p)
    {
        //The position of the original text
        int pos = (p - text);

        // Increment the pointer to go in the end of the word to remove
        p = p + sizeWord2;                
        
        // Search in the phrase and copy char per char
        int i;
        for(i = 0; i < strlen(p); i++)
        {
            text[pos + i] = p[i]; 
        }
        // Set the "new end" of the text               
        text[pos + i] = 0x00;      
    } 
    }
    fwrite(&text,sizeof(text),1,f);
}

/* --- function for shifting the time with s seconds --- */
void shiftTiming(FILE* f,int s){
    //TODO
}

int main(int argc,char** argv){
    /*open the srt file*/
    FILE* fptr = fopen("SubRipFile.srt","r+");
    /*we don't continue if we can't open the file*/
    if (!fptr)
    {
        printf("Couldn't open the file\n");
        return -1;
    }

    /*don't continue if the nr of seconds wasn't provided in the command line*/
    if (argc<2)
    {
        printf("Didn't provide the nr of seconds to shift\n");
        return -1;
    }
    
    /*we take the nr of seconds as the second argument of the command line*/
    int sec = atoi(argv[1]);
    removeTags(fptr);
    shiftTiming(fptr,sec);

    /*close the file*/
    fclose(fptr);
    return 0;
}