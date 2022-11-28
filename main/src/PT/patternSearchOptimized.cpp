#include <iostream>

void search(std::string pat, std::string txt)
{
    int M = pat.size();
    int N = txt.size();
    int i = 0;
  
    while (i <= N - M) {
        int j;
  
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) {
            if (txt[i + j] != pat[j]) {
                break;
            }
        }
  
        if (j == M) { // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            std::cout << "Pattern found at index " << i << "\n";
            i = i + M;
        } else if (j == 0) {
            i = i + 1;
        } else {
            i = i + j; // slide the pattern by j
        }
    }
}
  

int main() {
    std::string txt = "ABCEABCDABCEABCD";
    std::string pat = "ABCD";
    search(pat, txt);
    return 0;
}