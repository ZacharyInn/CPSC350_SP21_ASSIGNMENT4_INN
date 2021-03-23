#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
  Node();
  Node(T d);
  ~Node();
  Node *next;
  Node *prev;
  T data;
};

template <typename T>
Node<T>::Node()
{
}

template <typename T>
Node<T>::Node(T d)
{
  next = nullptr;
  prev = nullptr;
  data = d;
}

template <typename T>
Node<T>::~Node()
{
  next = nullptr;
  prev = nullptr;
}

template <typename T>
class GenStack
{
public:
  GenStack();
  ~GenStack();
  void push(T c); //add to top
  T pop(); //remove from top
  T peek(); //return top without removing
  bool isEmpty();
  int getSize();
private:
  Node<T> *front;
  Node<T> *back;
  int size;
  T top; //item at top of stack
};

template <typename T>
GenStack<T>::GenStack()
{
  front = nullptr;
  back = nullptr;
  size = 0;
}

template <typename T>
GenStack<T>::~GenStack()
{
  while (front != nullptr)
  {
    Node<T> *temp = new Node<T>();
    temp = front;
    front = front->next;
    delete temp;
  }
}

template <typename T>
bool GenStack<T>::isEmpty()
{
  return (size == 0);
}

template <typename T>
int GenStack<T>::getSize()
{
  return size;
}

template <typename T>
void GenStack<T>::push(T c)
{
  Node<T> *node = new Node<T>(c);
  if (size == 0)
  {
    back = node;
  }
  else
  {
    //not an empty list
    node->next = front;
    front->prev = node;
  }
  front = node;
  size++;
}

template <typename T>
T GenStack<T>::pop()
{
  try
  {
    if (size <= 0)
    {
      throw runtime_error("Stack is empty.");
    }
    Node<T> *tp = front;

    if (front->next == nullptr)
    {
      back = nullptr;
    }
    else
    {
      //size > 1
      front->next->prev = nullptr;
    }
    front = front->next;
    tp->next = 0;
    int temp = tp->data;
    size--;
    delete tp;

    return temp;
  }
  catch (runtime_error& excpt)
  {
    cout << excpt.what() << endl;
  }
}

template <typename T>
T GenStack<T>::peek()
{
  Node<T> *tp = front;
  return tp->data;
}

#endif
