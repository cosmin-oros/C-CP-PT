#include <iostream>

int main() {
    char* str1 = "SDA";
    char* str2 = str1;
    *++str1;
    *++str1;
    
    std::cout << str1-str2;

    return 0;
}