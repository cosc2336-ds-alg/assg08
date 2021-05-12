---
name: 'Task 5: Implement `deleteValue()` API mutator'
about: Task 4 for Students
title: 'Task 5: Implement `deleteValue()` API mutator'
labels: enhancement
assignees: ''

---

**Description**

The fifth task is to implement the `deleteValue()` container mutator of the `LList` linked list concrete class.  The purpose of this method is to delete all nodes with the indicated value.  Thus more than one node may be removed as a result of calling this function since duplicate values are allowed in the list of values.

**Suggested Solution**

We cannot reuse the `deletIndex()` member method in a simple way for this method unfortunately,
because if we removed values while iterating through the list, it is too easy to end up referencing a removed or lost portion of the list.  If we could iterate through the list in reverse (e.g a doubly linked list), then this approach might be worth trying.

However, we can use a similar general approach to the `deleteIndex()` method, by first handling removal of any `front` nodes then `back` nodes with the value we are searching for, before proceeding to remove internal nodes.

1. First remove all nodes from the front of the list that contain the value to be removed.  Do this as a simple loop that will call `deleteFront()` repeatedly as long as the value at the `front` is the value to be removed.
2. Next do the same for any back nodes that are the value to be removed.  Use a loop that repeats as long as the `back` value is the value to be removed and call `deleteBack()` to remove it.
3. At this point we know that the `front` and `back` nodes do not contain the value to be removed.  The list might be empty, or have 1 or 2 values. In all cases, if there are any values that still need to be removed, they will not be the first or last node, so in that case the node will be of size 3 or larger.
  - Iterate through the list keeping track of the previous node of the node being tested.
  - If the node being tested contains the value, it needs to be removed.
  - Make a temporary pointer to the node to be deleted.
  - Repoint the previous nodes `next` pointer to the node after the one being removed.
  - It is now safe to `delete` / deallocate the node now that is being removed.
  - The previous pointer now has a different node after it, continue iterating
    checking the new next node to see if it should be removed or not.

**Additional Requirements**

- You must reuse the member functions appropriately instead of repeating code /
  functionality.
- You are required to throw the indicated exception if an illegal request for an index 
  that is not in the bounds of the list is made.


