/** @file LList.cpp
 * @brief Concrete array based implementation of List ADT.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Linked Lists
 * @date   June 1, 2021
 *
 * Implement the List abstraction using a fixed sized array.
 * This array based implementation will dynamically allocate
 * a new block of memory once the current allocation becomes
 * full.  The new block is double in size of the old.  Thus
 * insertion at the end of the list can be O(1) in most cases,
 * but will take O(n) copies as well as a memory allocation
 * if it needs to grow.  Insertion in the middle or front
 * still requires shifting of items, so it is O(n).
 */
#include "LList.hpp"
#include "LListIterator.hpp"
#include "ListException.hpp"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/**
 * @brief Default constructor
 *
 * Construct an empty list.  The empty list will have no allocated memory
 * nor any values.
 */
template<class T>
LList<T>::LList()
{
  // Empty list has size 0 and both front and back are null
  this->size = 0;
  front = nullptr;
  back = nullptr;
}

/**
 * @brief Standard constructor
 *
 * Construct a list of integer values from a (statically) defined and
 * provided array of integers.  We need to dynamically construct
 * a node for each value in the array and create a linked list of these
 * nodes.
 *
 * @param size The size of the input values were are given as well as the
 *   size of the new list we are to construct.
 * @param values The (static) array of string values to use to construct
 *   this List values with.
 */
template<class T>
LList<T>::LList(int size, T values[])
{
  // Make sure list is empty before copying values from array.
  // Empty list has size 0 and both front and back are null
  this->size = 0;
  front = nullptr;
  back = nullptr;

  // iterate through the array reusing member functions to
  // simply insert new values one-by-one on the back
  for (int index = 0; index < size; index++)
  {
    // uncomment this after implementing insertBack() to enable its
    // reuse to correctly implement the array based constructor
    // insertBack(values[index]);
  }
}

/**
 * @brief Copy constructor
 *
 * Provide a copy constructor for the List class.  A copy constructor
 * will be invoked whenver you assign one instance of a List to another.
 * For example
 *   List newList = existingList;
 * Where of course existingList was a previously created List.  This copy
 * constructor, as the name suggests, should make a copy of the values from
 * the given input list into a new List instance.
 *
 * @param list The other List type we are to make a copy of in this
 *   constructor.
 */
template<class T>
LList<T>::LList(const LList<T>& list)
{
  // Make sure list is empty before copying values from other list.
  // Empty list has size 0 and both front and back are null
  this->size = 0;
  front = nullptr;
  back = nullptr;

  // if the other list is not empty, then we need to iterate through
  // its values and insert them into the back of this list
  if (not list.isEmpty())
  {
    Node<T>* current = list.front;
    while (current != nullptr)
    {
      // uncomment this after implementing insertBack() to enable its
      // reuse to correctly implement the copy constructor
      // insertBack(current->value);
      current = current->next;
    }
  }
}

/**
 * @brief Class destructor
 *
 * Destructor for the List class.  A concrete List implementation must
 * provide a clear() method to clear all items and safely deallocate any
 * memory that the concrete instance is using.  Invoke the clear
 * of the concrete subclass to perform the destruction.
 */
template<class T>
LList<T>::~LList()
{
  // call clear to do actual work to deallocate any allocation
  // before we destruct
  this->clear();
}

/**
 * @brief List to string
 *
 * Accessor method to construct and return a string representation
 * of the current values and status of this List instance.
 *
 * @returns string Returns the string constructed with the information
 *   about this List.
 */
template<class T>
string LList<T>::str() const
{
  ostringstream out;

  // stream list information into the output stream
  out << "<list> size: " << this->size << " [ ";

  // stream the current values of the list to the output stream
  Node<T>* current = front;
  while (current != nullptr)
  {
    // put value out to the stream
    out << current->value;

    // advance to the next value
    current = current->next;

    // separate for next value, or just space if no more values
    if (current == nullptr)
    {
      out << " ";
    }
    else
    {
      out << ", ";
    }
  }

  out << "]";

  // convert the string stream into a concrete string to return
  return out.str();
}

/**
 * @brief Boolean equals operator
 *
 * Check if this List is equal to the right hand side (rhs)
 * list.  The lists are equal if their sizes are equal, and if
 * all elements in both lists are equal.
 *
 * @param rhs The other list on the right hand side of the
 *   boolean comparison that we are comparing this List to.
 *
 * @returns bool true if the lists are equal, false if the are not.
 */
template<class T>
bool LList<T>::operator==(const List<T>& rhs) const
{
  // first the lists have to be of the same size, or else they
  // cannot be equal
  if (this->size != rhs.getSize())
  {
    return false;
  }

  // otherwise, lists are equal if all elements are equal.
  // compare each element, and if we find a pair that is not
  // equal then the answer is false
  for (int index = 0; index < this->size; index++)
  {
    if (this->operator[](index) != rhs[index])
    {
      return false;
    }
  }

  // if we get to this point, all values were the same in both
  // lists, so the answer is true, the lists are equal
  return true;
}

/**
 * @brief Indexing operator
 *
 * Provide a way to index individual values in our private
 * linked list of values.  This allows code to, for the
 * most part, treated an instance of our List as if it were
 * an array, though we also provide bounds checking to ensure
 * no illegal access beyond the list bounds is attempted.
 *
 * @param index The index of the value it is desired to access from
 *   this List.
 *
 * @returns int& Returns a reference to the requested List item at
 *   the requested index.
 *
 * @throws ListMemoryBoundsException if a request for an index beyond
 *   the end of the array (or less than 0) is made.
 */
template<class T>
T& LList<T>::operator[](int index) const
{
  // first check that the requsted index is legally
  // within the bounds of the current size of our list
  if ((index < 0) or (index >= this->size))
  {
    ostringstream out;
    out << "Error: <LList::operator[]> illegal bounds access, list size: " << this->size << " tried to access index address: " << index;

    throw ListMemoryBoundsException(out.str());
  }

  // otherwise it is safe to return the reference to the value, but
  // we have to do some work to find it first
  Node<T>* current = front;
  for (int currentIdx = 0; currentIdx < index; currentIdx++)
  {
    // advance to next node until we reach the index'th node of
    // this list
    current = current->next;
  }

  // return the reference to the value in the index'th node of the
  // list
  return current->value;
}

/**
 * @brief Clear out list
 *
 * Clear or empty out the list.  Return the list back to an empty
 * list.
 */
template<class T>
void LList<T>::clear()
{
  // if the list is not empty, we need to deallocate and return the nodes
  // back to the heap
  if (not this->isEmpty())
  {
    Node<T>* current = front;

    // iterate through the nodes of the list to delete them
    while (current != nullptr)
    {
      // remember this node to delete while advancing
      // to next node for next iteration
      Node<T>* nodeToDelete = current;
      current = current->next;

      // now safe to free up the memory of this node
      delete nodeToDelete;
    }
  }

  // make sure size is now 0 and front and back both point to null
  this->size = 0;
  front = nullptr;
  back = nullptr;
}

/**
 * @brief Delete back item
 *
 * Delete the item from the back of the list.  This is an expensive
 * O(n) operation for a singly linked list.
 */
template<class T>
void LList<T>::deleteBack()
{
  // make sure list is not empty before we try and access
  // the front item
  if (this->isEmpty())
  {
    ostringstream out;
    out << "Error: <Alist>::deleteBack() attempt to delete back item"
        << " from empty list, size:  " << this->size;

    throw ListEmptyException(out.str());
  }

  // if current list only has 1 item, then the list will now become
  // empty
  if (this->size == 1)
  {
    delete front;
    front = nullptr;
    back = nullptr;
    this->size = 0;
  }
  // otherwise there are at least 2 items in the list and we can
  // remove the current back item.  problem is, this is not a double
  // linked list, so we have to search till the item before the back
  else
  {
    // need to search through list and position prev to the node before
    // the back node
    Node<T>* prev = front;
    while (prev->next != back)
    {
      prev = prev->next;
    }

    // now remove the back node, and make prev the new back.
    delete back;
    prev->next = nullptr;
    back = prev;
    this->size -= 1;
  }
}

/**
 * @brief Delete front item
 *
 * Delete the item from the front of the list.  For a singly
 * linked list this operation is much cheaper than deleting
 * from the back, it is constant time O(1) to remove a front item.
 */
template<class T>
void LList<T>::deleteFront()
{
  // make sure list is not empty before we try and access
  // the front item
  if (this->isEmpty())
  {
    ostringstream out;
    out << "Error: <Alist>::deleteBack() attempt to delete back item"
        << " from empty list, size:  " << this->size;

    throw ListEmptyException(out.str());
  }

  // remember current front
  Node<T>* nodeToDelete = front;

  // move to new front
  front = front->next;

  // delete the node we removed
  delete nodeToDelete;

  // update list size since we just removed a node
  this->size -= 1;

  // list might now be empty, so make sure to repoint back as well
  // to nullptr if that is the case
  if (this->isEmpty())
  {
    back = nullptr;
  }
}

/**
 * @brief Begin iterator
 *
 * Create and return a ListIterator pointing to the beginning of
 * this list of items, ready to be iterated over.
 *
 * @returns ListIterator<T> returns a new instance of type
 *   ListIterator<T> that keeps track of iterating over the list items.
 */
template<class T>
ListIterator<T> LList<T>::begin()
{
  LListIterator<T> beginItr(front);
  return beginItr;
}

/**
 * @begin End iterator
 *
 * Return a ListIterator pointing to an index which is
 * at the end of this list, which is used to detect we are
 * at the end of the list when iteration.
 *
 * @returns ListIterator<T> returns a new instance of type
 *   ListIterator<T> that points to the end index indicator
 *   of the list.
 */
template<class T>
ListIterator<T> LList<T>::end()
{
  LListIterator<T> endItr(back);
  return endItr;
}

/**
 * @brief Constant begin iterator
 *
 * Create and return a ListIterator pointing to the beginning of
 * this list of items, ready to be iterated over.
 *
 * @returns ListIterator<T> returns a new instance of type
 *   ListIterator<T> that keeps track of iterating over the list items.
 */
template<class T>
ListIterator<T> LList<T>::cbegin() const
{
  LListIterator<T> beginItr(front);
  return beginItr;
}

/**
 * @brief Constant end iterator
 *
 * Return a ListIterator pointing to an index which is
 * at the end of this list, which is used to detect we are
 * at the end of the list when iteration.
 *
 * @returns ListIterator<T> returns a new instance of type
 *   ListIterator<T> that points to the end index indicator
 *   of the list.
 */
template<class T>
ListIterator<T> LList<T>::cend() const
{
  LListIterator<T> endItr(back);
  return endItr;
}

/**
 * @brief Cause specific instance compilations
 *
 * This is a bit of a kludge, but we can use normal make dependencies
 * and separate compilation by declaring template class List<needed_type>
 * here of any types we are going to be instantianting with the
 * template.
 *
 * https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
 * https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
 */
template class LList<int>;
template class LList<string>;
