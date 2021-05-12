---
name: 'Task 4: Implement `deleteIndex()` API mutator'
about: Task 4 for Students
title: 'Task 4: Implement `deleteIndex()` API mutator'
labels: enhancement
assignees: ''

---

**Description**

The fourth task is to implement the `deleteIndex()` defined mutator for the `LList` linked list API.  Any method that adds or removes values to the list can be considered a mutator method, they are changing the contents of the container.  `deleteIndex()` is a bit more tricky to implement than the previous tasks, and you will have to really understand iterating through and manipulating linked list nodes for this and the next task.

**Suggested Solution**

1. First check that the requested index to delete is a valid index.  You do this by
   testing if the index is less than 0, or if it is greater than or equal to the current `size`
   of the list.  If the requested index is out of bounds, `throw` a
   `ListMemoryBoundsException`.
2. If the index is 0, you are deleting the front node.  This is a relatively simple case.
   Reuse the `deleteFront()` mutator method to remove this value from the list.
3. If the index is the `back` / last node of the linked list, reuse the `deleteBack()`
   mutator method to remove this value from the list.
4. Otherwise it is a bit more complicated, though you know that a) neither the front
   nor back node will be removed and b) the list must have 3 or more nodes, and it will not
   become empty as a result of deleting the asked for node.
   - You need to iterate through the linked list nodes until you are positioned
     at the node to be removed.
   - The simplest implementation of this is to keep track of the node previous to the
     one you need to remove, because you need to point the previous nodes `next` pointer
	 to the node after the one you will remove to get it out of the linked list.
   - Make a temporary pointer to the node you will be deleting.
   - Repoint the previous nodes `next` pointer to the node after the one being removed.
   - It is now safe to `delete` / deallocate the node now that is being removed.


**Additional Requirements**

- You must reuse the member functions appropriately instead of repeating code /
  functionality.
- You are required to throw the indicated exception if an illegal request for an index 
  that is not in the bounds of the list is made.

