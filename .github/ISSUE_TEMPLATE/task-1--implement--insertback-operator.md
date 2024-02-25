---
name: 'Task 1: Implement `insertBack()` and Overload `operator>>()`'
about: Task 1 for Students
title: 'Task 1: Implement `insertBack()` and Overload `operator>>()`'
labels: enhancement, good first issue
assignees: ''

---

**Description**

Implement the insert back operation for the `LList` linked list concrete class.  Perform this task in 2 steps.  Implement a member function named `insertBack()` as described which does the actual work of appending a Node with the new value to the end of the list.  Then overload the `operator>>()` and simply call the `insertBack()` function to implement this overloaded operator.

**NOTE**: Also the array based constructor and the copy constructor both need to reuse your `insertBack()` method to do their work.  Once you have the initial tests working for your implementation, uncomment the calls to `insertBack()` in these two constructors, so that you can test this method and all of the others more thoroughly.

**Suggested Solution**

Appending on a linked list is hopefully relatively easy.  You do have to check for the special case of the list being empty and handle it.  The general steps insert onto the back of the linked list are

1. Dynamically allocate a new `Node`
   - Initialize the nodes value to the input value given for the `insertBack()` function.
   - Also initialize the nodes `next` pointer to point to `nullptr`, since this node will become the new `back` node of the linked list.
2. Test if the list is empty or not,  you should reuse the `isEmpty()` member function to test this.
   - If the list is not empty, then simply append the new node by linking `next` of the current `back` node to the new node, and update `back` pointer to be pointing to this new back node.
   - If the list is empty, then both `front` and `back` should be pointed to this new node, since the node is both the front and the back now of the list of 1 item.
3. Don't forget to update the `size` of the list.


**Additional Requirements**

- You should make it a habit to always reuse code instead of repeating code.  Here you need to test if the list is empty or not.  Reuse the `isEmpty()` function instead of testing size or the status of `front` and `back` pointers.  This makes your intention clearer (`isEmpty()` is generally more readable).  And it means if we want to change how we test if the list is empty or not, we can do it in one function if all parts of the class use this function when checking if the list is empty or not. 
- Make sure that you uncomment the calls to `insertBack()` in the `LList` constructors so that they are reusing your function and properly constructing lists now.
- You are required to be correctly allocating a new node and managing the linked list as suggested.  When the list is of size 1, both `front` and `back` pointers of the linked list should be pointing to the new `Node` item just created.
- Your overloaded `operator>>()` should be reusing the `insertBack()` method.  It should have the same signature as this method.
