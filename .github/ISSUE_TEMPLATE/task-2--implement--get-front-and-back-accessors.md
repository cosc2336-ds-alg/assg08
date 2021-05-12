---
name: 'Task 2: Implement `getFront()` `getBack()` accessor methods'
about: Task 2 for Students
title: 'Task 2: Implement `getFront()` `getBack()` accessor methods'
labels: enhancement
assignees: ''

---

**Description**

Implement the `getFront()` and `getBack()` accessor methods.  These methods should return the value of the node at the `front` and `back` of the current list respectively.

**Suggested Solution**

These methods should be relatively simple, but there is a small wrinkle.  You should first check if the list is empty before trying to access and return the front/back item of the list.  If the list is empty, `throw()` a `ListEmptyException`.  This exception has already been defined for you in the `ListException.hpp` header file.  Users of lists should check that the list is not empty before attempting to get values from the list.  Throwing the exception allows for a user to catch and handle this case for situations where they might want to try this without knowing if the list is empty or not before hand.

**Additional Requirements**

- Make sure you reuse `isEmpty()` method to check if the list is empty or not.
- You are required to `throw` the correct exception if an attempt is made to access a value from an empty list. The tests for these methods are checking and expect such an exception to be thrown on attempted access of an empty list.

