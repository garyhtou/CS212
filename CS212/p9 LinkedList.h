// Original code from Daniel Liang (2003)
// now animated at yongdanielliang.github.io/animation/web/LinkedList.html
// 
// Extensively modified by W.P. Iverson
// Bellevue College, May 2020
// for CS212
// 
// Assignment completed by Gary Tou
// 6/9/2021
// Program 9: Linked List <T>

#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
    Node() // No-arg constructor
    {
        next = NULL;
    }

    Node(T element) // Constructor
    {
        this->element = element;
        next = NULL;
    }

    // just for console testing:
    void printNodes()
    {
        Node<T>* current = this;
        while (current->next != NULL)
        {
            cout << current->element << " ";
            current = current->next;
        }
        cout << current->element << endl;
    }

    // so we can keep nodes private
    void setNext(Node<T>* change)
    {
        next = change;
    }

    T getData()
    {
        return element;
    }

    Node<T>* getNext()
    {
        return next;
    }

    friend ostream& operator<<(ostream& os, Node<T>& node)
    {
        os << node.getData();
        return os;
    }

    void operator=(T element) {
        this->element = element;
    }

private:
    T element;  // Element contained in the node
    Node<T>* next; // Pointer to the next node
};

// template linked list class
template<typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList<T>&);
    void addLast(T element);
    void add(T element);
    void printList();

    Node<T>* getHead();
    
    bool addAll(const LinkedList<T>& otherList);
    bool removeAll(const LinkedList<T>& otherList);
    bool retainAll(const LinkedList<T>& otherList);

    bool remove(const T element);
    int lastIndexOf(const T element) const;
    bool contains(const T element) const;

    Node<T>& operator[](const int index) const;
    LinkedList<T> operator+(const LinkedList<T>& otherList) const;
    LinkedList<T> operator-(const LinkedList<T>& otherList) const;
    LinkedList<T> operator^(const LinkedList<T>& otherList) const;
    LinkedList<T>& operator=(const LinkedList<T>& otherList);

private:
    Node<T>* head;
    Node<T>* tail;
    int size;

};

template<typename T>
LinkedList<T>::LinkedList()
{
    head = tail = NULL;
    size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &otherList)
{
    head = tail = NULL;
    size = 0;

    this->addAll(otherList);
}

template<typename T>
void LinkedList<T>::printList()
{
    head->printNodes();
}

template<typename T>
void LinkedList<T>::addLast(T element)
{
    if (tail == NULL)
    {
        head = tail = new Node<T>(element);
    }
    else
    {
        Node<T>* temp = new Node<T>(element);
        tail->setNext(temp);
        tail = temp;
    }
    size++;
}

// Standard List adds data at end of list
template<typename T>
void LinkedList<T>::add(T element)
{
    addLast(element);
}

template<typename T>
Node<T>* LinkedList<T>::getHead() {
    return this->head;
}


template<typename T>
bool LinkedList<T>::addAll(const LinkedList<T>& otherList) {
    Node<T>* current = otherList.head;
    while (current->getNext() != NULL)
    {
        // add the element to this list
        this->add(current->getData());
        current = current->getNext();
    }
    this->add(current->getData());

    return true;
}

template<typename T>
bool LinkedList<T>::removeAll(const LinkedList<T>& otherList) {
    Node<T>* current = otherList.head;
    while (current->getNext() != NULL)
    {
        // find and remove the current Node from this list
        this->remove(current->getData());
        current = current->getNext();
    }
    this;
    this->remove(current->getData());

    return true;
}

template<typename T>
bool LinkedList<T>::retainAll(const LinkedList<T>& otherList) {

    Node<T>* current = otherList.head;
    while (current->getNext() != NULL)
    {
        if (!(this->contains(current->getData()))) {
            this->remove(current->getData());
        }
        current = current->getNext();
    }
    if (!(this->contains(current->getData()))) {
		this->remove(current->getData());
    }

    current = this->head;
    while (current->getNext() != NULL)
    {
        if (!(otherList.contains(current->getData()))) {
            T temp = current->getData();
            current = current->getNext();
            this->remove(temp);
        }
        else {
            current = current->getNext();
        }
    }
    if (!(otherList.contains(current->getData()))) {
        T temp = current->getData();
        current = current->getNext();
        this->remove(temp);
    }
    else {
        current = current->getNext();
    }
    return true;

    

    //LinkedList<T> list;

    //// retain otherList
    //Node<T>* current = otherList->head;
    //while (current->next != NULL)
    //{
    //    if (this->contains(current)) {
    //        list.add(current);
    //    }
    //    current = current->next;
    //}
    //if (this->contains(current)) {
    //    list.add(current);
    //}

    //// retain this list
    //current = this->head;
    //while (current->next != NULL)
    //{
    //    if (otherList->contains(current)) {
    //        list->add(current);
    //    }
    //    current = current->next;
    //}
    //if (otherList->contains(current)) {
    //    list->add(current);
    //}

    //return true;
}

template<typename T>
bool LinkedList<T>::remove(const T element) {
  //  // find and remove the element
  //  Node<T>* current = this->head;
  //  Node<T>* prev = NULL;
  //  bool found = false;

  //  int index = this->lastIndexOf(element);
  //  // element was not found. can't remove it
  //  if (index == -1) {
  //      return false;
  //  }

  //  int beforeIndex = index - 1;
  //  if (beforeIndex >= 0) {
  //      Node<T>* before = (*this)[beforeIndex];

  //      // remove it
  //      delete before->getNext();
  //      before->setNext(before->getNext()->getNext());

  //      // update tail if necessary
  //      if (before->getNext() == NULL) {
  //          this->tail = before;
		//}
  //  }
  //  else {
  //      Node<T>* newHead = this->head->getNext();
  //      delete this->head;
  //      this->head = newHead;
  //  }
  //  this->size -= 1;

  //  return true;



    Node<T>* current = this->head;
    Node<T>* prev = NULL;
    int index = 0;

    while (current->getNext() != NULL)
    {
		if (current->getData() == element) {
            if (current->getNext() == NULL) {
                this->tail = current->getNext();
            }

            if (index == 0) {
                this->head = current->getNext();
                delete current;
            }
            else {
                prev->setNext(current->getNext());
                delete current;
            }

            size -= 1;
            break;
        }
		else {
            prev = current;
            current = current->getNext();
            index += 1;
        }
    }
    return true;









 //   while (current->next != NULL)
 //   {
 //       if (current->element == element) {
 //           found = true;

 //           // remove it
 //           delete current->next;
	//		current->next = current->next->next;
 //           this->size -= 1;

 //           // update tail if necessary
 //           if (current->next == NULL) {
 //               this->tail = current;
 //           }
 //       }
 //       prev = current;
 //       current = current->next;
	//}

 //   if (current->element == element) {
 //       found = true;

 //       // remove it
 //       delete current->next;
 //       current->next = current->next->next;
 //       this->size -= 1;

 //       // update tail if necessary
 //       if (current->next == NULL) {
 //           this->tail = current;
 //       }
 //   }

    // if the element was not found and removed, it will return false
 //   return found;
}

template<typename T>
int LinkedList<T>::lastIndexOf(const T element) const {
    Node<T>* current = this->head;
    int counterIndex = 0;
    int foundIndex = -1;

    while (current->getNext() != NULL)
    {
        // if the element was found, update the foundIndex
        if (current->getData() == element) {
            foundIndex = counterIndex;
        }

        counterIndex += 1;
        current = current->getNext();
    }
    // if the element was found, update the foundIndex
    if (current->getData() == element) {
        foundIndex = counterIndex;
    }

    return foundIndex;
}


template<typename T>
bool LinkedList<T>::contains(const T element) const {
    Node<T>* current = this->head;

    while (current->getNext() != NULL)
    {
        // if the element was found, return true
        if (current->getData() == element) {
            return true;
        }

        current = current->getNext();
    }
    // if the element was found, return true
    if (current->getData() == element) {
        return true;
    }

    return false; // element was not found
}

template<typename T>
Node<T>& LinkedList<T>::operator[](const int index) const {
    if (index < 0 || index >= this->size) {
        throw std::out_of_range("index: " + index);
    }

    Node<T>* current = this->head;
    for (int i = 0; i < index; i++) {
        current = current->getNext();
    }

    return *current;
}

template<typename T>
LinkedList<T> LinkedList<T>::operator+(const LinkedList<T>& otherList) const { 
    LinkedList<T> list;
    list.addAll(*this);
    list.addAll(otherList);
    return list;
}

template<typename T>
LinkedList<T> LinkedList<T>::operator-(const LinkedList<T>& otherList) const {
    LinkedList<T> list;
    list.addAll(*this);
    list.removeAll(otherList);
    return list;
}

template<typename T>
LinkedList<T> LinkedList<T>::operator^(const LinkedList<T>& otherList) const {
    LinkedList<T> list;
    list.addAll(*this);
    list.retainAll(otherList);
    return list;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& otherList) {
    // reset LinkedList
    Node<T>* current = this->head;
    while (current->getNext() != NULL)
    {
        Node<T>* next = current->getNext();
        delete current;
        current = next;
    }
    delete current;

    this->head = NULL;
    this->tail = NULL;
    this->size = 0;

    this->addAll(otherList); // deep copy
    return *this;
}