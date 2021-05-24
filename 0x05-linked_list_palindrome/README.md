# 0x05. Linked list palindrome
Given a singly linked list of characters, write a function that returns 1 if the given list is a palindrome, else 0.

### Time complexity: O(n).

## Steps:
- Get to the middle of the list, while creates a reversed link of the first half.
- Check if every node from the second half and the new reversed linked list are identical.
- If every value of both linked list are identical, is palindrome, else it is not.