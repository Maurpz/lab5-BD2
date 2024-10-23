#include <iostream>
#include "Lru.h"
using namespace std;
int main () {
  Lru p1 = Lru(3);

  p1.useElement(4); 
  p1.printQueue();
  p1.useElement(5); 
  p1.printQueue();
  p1.useElement(4); 
  p1.printQueue();
  p1.useElement(11);
  p1.printQueue();
  p1.useElement(55);
  p1.printQueue();
  p1.useElement(4);
  p1.printQueue();
  return 0;
}