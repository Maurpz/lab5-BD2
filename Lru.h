
#include <iostream>
using namespace std;
#ifndef LRU_H
#define LRU_H

class Lru {
  private:
    int *queue;
    int size;
    int count;
  public:
  Lru(int size) {
    this->queue = new int[size];
    this->count = 0;
    this->size = size; 
  }
  ~Lru(){
    delete [] queue;
  }

  void swap(int element){
    int i = 0;
    for (i; i<count; i++) {
      if (queue[i] == element) break;
    }
    
    for (i;i<(count-1);i++){
      queue[i]= queue[i+1];
    }
    queue[count-1] = element;
  }

  void useElement(int element) {
    if (isExists(element)) {
      swap(element);
    }
    else{
      addElement(element);
    }
  }

  void addElement (int element) {
    if (isFull()) {
      for (int i = 0;i<(count-1);i++){
      queue[i]= queue[i+1];
      }
      queue[size-1] = element;
    } 
    else {
      queue[count] = element;
      count++;
    }
  }
  bool isFull () const {
    return count >= size;
  }
  bool isExists(int element) {
    for (int i = 0; i<count; i++) {
      if (queue[i] == element) return true;
    }
    return false;
  }

  void printQueue () const {
    for (int i = 0; i<size; i++) {
      cout<<queue[i]<<" ";
    }
    cout<<endl;
  }
};
#endif