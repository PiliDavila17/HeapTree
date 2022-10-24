// =================================================================
//
// File: PriorityQueue.h
// Author: Maria del Pilar Davila Verduzco
// Date: 23/10/2022
//
// =================================================================

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <sstream>
#include <string>
#include "header.h"

// =================================================================
// Definition of the PriorityQueue class
// =================================================================
template <class T>
class PriorityQueue
{
private:
  T *queue;
  int size;

public:
  PriorityQueue();

  int parentIndex(int) const;
  int leftIndex(int) const;
  int rightIndex(int) const;

  void push(int);
  void pop();
  int top() const;
  bool empty() const;
  int getSize() const;

  void print() const;
  std::string toString() const;
};

template <class T>
PriorityQueue<T>::PriorityQueue()
{
  queue = new int[100];
  size = 0;
}
// =================================================================
// Return index of parent node
// @param int index of current node
// =================================================================
template <class T>
int PriorityQueue<T>::parentIndex(int i) const
{
  return (i - 1) / 2;
}
// =================================================================
// Return index of left node
// @param int index of current node
// =================================================================
template <class T>
int PriorityQueue<T>::leftIndex(int i) const
{
  return ((i * 2) + 1);
}
// =================================================================
// Return index of right node
// @param int index of current node
// =================================================================
template <class T>
int PriorityQueue<T>::rightIndex(int i) const
{
  return ((i * 2) + 2);
}

// =================================================================
// Pushes value to queue. Adds new value and positions it at the right place (Max Heap Tree)
// @param int value to add
// Return void
// =================================================================
template <class T>
void PriorityQueue<T>::push(int value)
{
  if (empty())
  {
    queue[0] = value;
    this->size += 1;
  }
  else
  {
    queue[this->size] = value;
    int i = this->size;
    while (i > 0 && this->queue[parentIndex(i)] <= this->queue[i])
    {
      swap(queue[parentIndex(i)], queue[i]);
      i = parentIndex(i);
    }
    this->size += 1;
  }
}
// =================================================================
// Pops value from queue. Delete value with highest priority and positions new Top at the 
// right place (Max Heap Tree)
// @param none
// Return void
// =================================================================
template <class T>
void PriorityQueue<T>::pop()
{
  int aux;
  for (int i = 0; i < this->size; i++)
  {
    this->queue[i] = this->queue[i + 1];
  }
  this->queue[size - 1].~T();
  this->size--;

  int i = 0;
  while (i < this->size && this->queue[parentIndex(i)] < this->queue[leftIndex(i)] || 
  this->queue[parentIndex(i)] < this->queue[rightIndex(i)])
  {
    if (this->queue[parentIndex(i)] < this->queue[leftIndex(i)])
    {
      swap(this->queue[parentIndex(i)], this->queue[leftIndex(i)]);
      i = leftIndex(i);
    }
    else
    {
      swap(this->queue[parentIndex(i)], this->queue[rightIndex(i)]);
      i = rightIndex(i);
    }
  }
}
// =================================================================
// Gets top. Value with highest priority (Max Heap Tree)
// @param none
// Return int value with highest priority
// =================================================================
template <class T>
int PriorityQueue<T>::top() const
{
  if (empty())
  {
    return -1;
  }
  return this->queue[0];
}

// =================================================================
// Cheks if priority queue is empty or not.
// @param none
// Returns bool True if size < 0;
// =================================================================
template <class T>
bool PriorityQueue<T>::empty() const
{
  return (size < 1);
}

// =================================================================
// Gets size of priority queue
// @param none
// Returns int queue size
// =================================================================
template <class T>
int PriorityQueue<T>::getSize() const
{
  return this->size;
}
// =================================================================
// Prints all values
// @param none
// Returns void
// =================================================================
template <class T>
void PriorityQueue<T>::print() const
{
  for (int i = 0; i < this->size; i++)
  {
    std::cout << this->queue[i] << " ";
  }
}

// =================================================================
// String representation of the elements in the list.
//
// @returns a string containing all the elements of the list.
// =================================================================
template <class T>
std::string PriorityQueue<T>::toString() const
{
  std::stringstream aux;
  aux << "[";
  for (int i = 0; i < this->size; i++)
  {
    aux << this->queue[i];
    if (i < size - 1)
    {
      aux << ", ";
    }
  }
  aux << "]";
  return aux.str();
}
#endif
