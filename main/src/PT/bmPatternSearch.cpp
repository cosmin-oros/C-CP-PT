#include <iostream>

# define NO_OF_CHARS 256
 
void badCharHeuristic(std::string str, int size, int badchar[NO_OF_CHARS]) {
    int i;
 
    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++) {
        badchar[i] = -1;
    }
 
    // Fill the actual value of last occurrence
    // of a character
    for (i = 0; i < size; i++) {
        badchar[(int) str[i]] = i;
    }
}
 
/* A pattern searching function that uses Bad
Character Heuristic of Boyer Moore Algorithm */
void search(std::string txt, std::string pat)
{
    int m = pat.size();
    int n = txt.size();
 
    int badchar[NO_OF_CHARS];
 
    badCharHeuristic(pat, m, badchar);
 
    int s = 0; // s is shift of the pattern with
                // respect to text
    while(s <= (n - m))
    {
        int j = m - 1;
 
        /* Keep reducing index j of pattern while
        characters of pattern and text are
        matching at this shift s */
        while(j >= 0 && pat[j] == txt[s + j])
            j--;
 
        /* If the pattern is present at current
        shift, then index j will become -1 after
        the above loop */
        if (j < 0)
        {
            std::cout << "pattern occurs at shift = " << s << "\n";
 
            /* Shift the pattern so that the next
            character in text aligns with the last
            occurrence of it in pattern.
            The condition s+m < n is necessary for
            the case when pattern occurs at the end
            of text */
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;
 
        }
 
        else {
            s += std::max(1, j - badchar[txt[s + j]]);
        }
    }
}

int main() {
    std::string txt= "ABAAABCD";
    std::string pat = "ABC";
    search(txt, pat);
    return 0;
}