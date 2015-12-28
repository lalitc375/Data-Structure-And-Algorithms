/ assignment operator with unordered_map
#include <iostream>
#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string,std::string> stringmap;

stringmap merge (stringmap a,stringmap b) {
  stringmap temp(a); temp.insert(b.begin(),b.end()); return temp;
}

int main ()
{
  stringmap first, second, third;
  first = {{"AAPL","Apple"},{"MSFT","Microsoft"}};  // init list
  second = {{"GOOG","Google"},{"ORCL","Oracle"}};   // init list
  third = merge(first,second);                      // move
  first = third;                                    // copy

  std::cout << "first contains:";
  for (auto& elem: first) std::cout << " " << elem.first << ":" << elem.second;
  std::cout << std::endl;

  return 0;
}
