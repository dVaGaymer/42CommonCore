#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
  // Mutant Stack
  std::cout << "~MUTANT STACK~\n";
  MutantStack<MyOwnTypes::entero> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  // Same code using vector
  std::cout << "\n~VECTOR~\n";
  std::vector<MyOwnTypes::entero> vec;
  vec.push_back(5);
  vec.push_back(17);
  std::cout << vec.back() << std::endl;
  vec.pop_back();
  std::cout << vec.size() << std::endl;
  vec.push_back(3);
  vec.push_back(5);
  vec.push_back(737);
  //[...]
  vec.push_back(0);
  std::vector<int>::iterator itv = vec.begin();
  std::vector<int>::iterator itve = vec.end();
  ++itv;
  --itv;
  while (itv != itve) {
    std::cout << *itv << std::endl;
    ++itv;
  }

  // Same code using list
  std::cout << "\n~LIST~\n";
  std::list<MyOwnTypes::entero> lst;
  lst.push_back(5);
  lst.push_back(17);
  std::cout << lst.back() << std::endl;
  lst.pop_back();
  std::cout << lst.size() << std::endl;
  lst.push_back(3);
  lst.push_back(5);
  lst.push_back(737);
  //[...]
  lst.push_back(0);
  std::list<int>::iterator itl = lst.begin();
  std::list<int>::iterator itle = lst.end();
  ++itl;
  --itl;
  while (itl != itle) {
    std::cout << *itl << std::endl;
    ++itl;
  }
  return 0;
}
