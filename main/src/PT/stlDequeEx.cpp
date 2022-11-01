
#include <iostream>
#include <deque>
  
void showdq(std::deque<int> g)
{
    std::deque<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it){
        std::cout << '\t' << *it;
    }
    std::cout << '\n';
}
  
int main()
{
    std::deque<int> gquiz;
    gquiz.push_back(10);
    gquiz.push_front(20);
    gquiz.push_back(30);
    gquiz.push_front(15);
    std::cout << "The deque gquiz is : ";
    showdq(gquiz);
  
    std::cout << "\ngquiz.size() : " << gquiz.size();
    std::cout << "\ngquiz.max_size() : " << gquiz.max_size();
  
    std::cout << "\ngquiz.at(2) : " << gquiz.at(2);
    std::cout << "\ngquiz.front() : " << gquiz.front();
    std::cout << "\ngquiz.back() : " << gquiz.back();
  
    std::cout << "\ngquiz.pop_front() : ";
    gquiz.pop_front();
    showdq(gquiz);
  
    std::cout << "\ngquiz.pop_back() : ";
    gquiz.pop_back();
    showdq(gquiz);
  
    return 0;
}