#include <iostream>
#include <unordered_map>

void printUmm(std::unordered_multimap<std::string, int>& umm)
{
 
    // Iterator pointing to first element of unordered_map
    auto it1 = umm.begin();
 
    for (; it1 != umm.end(); it1++) {
        std::cout << "<" << it1->first << ", " << it1->second << ">  \n";
    }
}

int main(){
    std::unordered_multimap<std::string, int> umm{
        { "apple", 1 }, { "ball", 2 }, { "apple", 10 },
        { "cat", 7 },   { "dog", 9 },  { "cat", 6 },
        { "apple", 1 }
    };

    auto it = umm.begin();
 
    // Search for an element with value 1
    while (it != umm.end()) {
        if (it->second == 1){
            break;
        }
        it++;
    }
    
    if (it != umm.end()){
        umm.erase(it);
    }
     
      std::cout << "After deletion of value 1 from umm\n";
    printUmm(umm);
    
    return 0;
}