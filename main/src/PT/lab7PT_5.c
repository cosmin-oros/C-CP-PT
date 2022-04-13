#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
    /* ---- continue from here ---- */

    /*close the file*/
    fclose(fptr);
    return 0;
}