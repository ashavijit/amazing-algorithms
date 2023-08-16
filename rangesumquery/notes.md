

Suppose we have the following array of numbers: `[1, 3, 5, 7, 9]`.

**Step 1: Initialization - Creating a NumArray Object**
```cpp
vector<int> nums = {1, 3, 5, 7, 9};
NumArray numArray(nums);
```

This initializes a `NumArray` object with the given array of numbers. The constructor will build the segment tree internally.

**Step 2: Building the Segment Tree**
The segment tree is constructed recursively, starting with the entire array as a segment and splitting it into smaller segments.

```
Segment Tree:
      25
    /     \
   9      16
  / \    /  \
 4   5  7    9
```

**Step 3: Updating a Value**
```cpp
numArray.update(2, 6);  // Update the value at index 2 to 6
```

After updating, the segment tree will be modified accordingly:

```
Segment Tree (Updated):
      25
    /     \
   12      13
  / \      / \
 4   8    7   6
```

**Step 4: Querying Range Sum**
```cpp
int sum = numArray.sumRange(1, 3);  // Query sum of elements from index 1 to 3
```

To compute the sum, we traverse the segment tree:

- We start at the root node with the segment `[0, 4]` which represents the whole array.
- The root's left child `[0, 2]` partially overlaps with the query range `[1, 3]`, so we move to the left child.
- The left child's left child `[0, 1]` is fully contained in the query range, so we move to it.
- Finally, the left child of `[0, 1]` corresponds to the element at index 1 (value 8).

The sum is `8 + 7 + 6 = 21`.

**Segment Tree Basics:**

1. A segment tree is a binary tree used to efficiently query and update ranges of elements in an array.

2. Each leaf node of the segment tree corresponds to a single element of the input array.

3. Each internal node of the segment tree represents a segment (range) of elements from the input array.

4. The root of the segment tree represents the entire input array.

5. The segment tree is usually implemented as an array to save memory.

**Formulas and Operations:**

1. **Building the Segment Tree:**
   
   The segment tree is built through a recursive process:

   ```cpp
   buildSegmentTree(start, end, index):
       if start == end:
           // Leaf node, assign value of element at 'start'
       else:
           mid = (start + end) / 2
           buildSegmentTree(start, mid, leftChild)
           buildSegmentTree(mid + 1, end, rightChild)
           // Update current node's value using left and right child nodes
   ```

2. **Updating a Value:**
   
   Updating a value at a specific index involves traversing the tree:

   ```cpp
   updateSegmentTree(start, end, position, value, index):
       if position is outside the range [start, end]:
           return
       if start == end:
           // Leaf node, update value
       else:
           mid = (start + end) / 2
           updateSegmentTree(start, mid, position, value, leftChild)
           updateSegmentTree(mid + 1, end, position, value, rightChild)
           // Update current node's value using left and right child nodes
   ```

3. **Querying Range Sum:**

   Querying for the sum of elements in a specific range involves traversing the tree while considering the query range:

   ```cpp
   sumQuery(queryStart, queryEnd, segmentStart, segmentEnd, index):
       if query range is completely outside segment range:
           return 0
       if segment range is completely inside query range:
           // Return value of current node
       mid = (segmentStart + segmentEnd) / 2
       leftSum = sumQuery(queryStart, queryEnd, segmentStart, mid, leftChild)
       rightSum = sumQuery(queryStart, queryEnd, mid + 1, segmentEnd, rightChild)
       // Combine left and right sum results
       return leftSum + rightSum
   ```

**Time Complexity:**

- Building the segment tree takes O(n) time, where n is the number of elements in the array.

- Updating a value or querying for a range sum takes O(log n) time, as you traverse the tree's height.

**Space Complexity:**

The space complexity of a segment tree is O(4n), where n is the number of elements in the array.

Segment trees are a powerful data structure for efficient range queries and updates. They're commonly used in competitive programming and various algorithmic applications.