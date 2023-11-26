#pragma once
#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
public:
  typedef typename std::deque<T>::iterator iterator;

  // Mutant stack
  MutantStack() {}
  MutantStack(MutantStack const &o) { (void)o; }
  ~MutantStack() {}
  MutantStack &operator=(MutantStack const &o) {
    (void)o;
    return *this;
  }
  
  typename std::deque<T>::iterator begin() { return this->c.begin(); }
  typename std::deque<T>::iterator end() { return this->c.end(); }
};
#endif

// Test of typedef inside class
class MyOwnTypes {
public:
  typedef int entero;
  typedef float flotante;
  typedef char caracter;
};
