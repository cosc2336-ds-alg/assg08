---
name: 'Task 3: Implement `insertFront()` and Overload `operator<<()`'
about: Task 3 for Students
title: 'Task 3: Implement `insertFront()` and Overload `operator<<()`'
labels: enhancement
assignees: ''

---

**Description**

Implement the insert to front of list operation for the `LList` linked list concrete class.  Perform this task in 2 steps.  Implement a member function named `insertFront()` as described which does the actual work of prepending a Node with the new value to the beginning of the list.  Then overload the `operator>>()` and simply call the `insertBack()` function to implement this overloaded operator.
**Suggested Solution**

Prepending to the front of a linked list is pretty similar to the task 1 of appending to the end.

1. Dynamically allocate a new `Node`
   - Initialize the nodes value to the input value given for the `insertBack()` function.
   - Also initialize the nodes `next` pointer to point to `nullptr`, since this node will become the new `back` node of the linked list.
2. Test if the list is empty or not,  you should reuse the `isEmpty()` member function to test this.
   - If the list is not empty, then sprepend the new node by linking the new nodes `next` pointer to the current `front` node, and then update `front` to point to this new node.
   - If the list is empty, then both `front` and `back` should be pointed to this new node, since the node is both the front and the back now of the list of 1 item.

**Additional Requirements**

- Make sure you are reusing `isEmpty()` to test for the list being empty or not.
- Make sure that you uncomment the calls to `insertFront()` in the `LList` constructors so that they are reusing your function and properly constructing lists now.
- You are required to be correctly allocating a new node and managing the linked list as suggested.  When the list is of size 1, both `front` and `back` pointers of the linked list should be pointing to the new `Node` item just created.
- Your overloaded `operator<<()` should be reusing the `insertFront()` method.  It should have the same signature as this method.
