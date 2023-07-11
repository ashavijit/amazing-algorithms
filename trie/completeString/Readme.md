### Question Link : [Complete Strings](https://www.codingninjas.com/studio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos)

The code provided implements a Trie data structure and a function called `completeString`. The `completeString` function takes an integer `n` and a vector of strings `a` as input. It inserts all the strings from `a` into a Trie using the `insert` method of the Trie class. Then, it searches for the longest lexicographically smallest string that is present in the Trie using the `search` method. The result is returned as a string.

Let's understand the code with an example:

Suppose we have the following input:
```cpp
int n = 5;
vector<string> a = {"apple", "banana", "app", "orange", "apricot"};
```

The code creates an instance of the Trie class and inserts all the strings from the vector `a` into the Trie. The Trie is built as follows:

```
            root
           /   |   \
          a    b    o
         / \    \     
        p   r    r    
       / \  |     \
      p   r i     a
     / \   |        
    l  r   c      
   /      /        
  e      o
```

Next, the code iterates over each string in `a` and checks if it exists in the Trie by calling the `search` method. For each string found in the Trie, it updates the `ans` string to store the longest lexicographically smallest string found so far. If multiple strings have the same length, the lexicographically smallest string is chosen. In the end, the function returns the `ans` string.

In our example, the `ans` string is initially empty. The code iterates over each string in `a`:

- For "apple", the string is found in the Trie, and since it is longer than the current `ans` string (empty), it becomes the new `ans`.
- For "banana", the string is not found in the Trie, so it is skipped.
- For "app", the string is found in the Trie, but it is shorter than the current `ans` string ("apple"), so it is skipped.
- For "orange", the string is not found in the Trie, so it is skipped.
- For "apricot", the string is found in the Trie, but it is shorter than the current `ans` string ("apple"), so it is skipped.

After iterating over all the strings, the `ans` string is "apple", which is the longest lexicographically smallest string present in the Trie. Thus, "apple" is returned as the result.

In summary, the `completeString` function finds the longest lexicographically smallest string present in a vector of strings using a Trie data structure.


### Code Explained

Certainly! The provided code implements a Trie data structure and includes a function called `completeString` that utilizes the Trie to find the longest lexicographically smallest string among a given set of strings.

Here's a breakdown of the code:

1. Trie Node Class (`Node`):
   - The `Node` class represents a node in the Trie. It contains a boolean `flag` to mark the end of a word, an array `links` to store child nodes for each character (a-z), and various member functions to manipulate the node.

2. Trie Class (`Trie`):
   - The `Trie` class represents the Trie data structure. It has a `root` node and includes methods for inserting strings into the Trie (`insert`) and searching for a string in the Trie (`search`).

3. Inserting Strings into the Trie (`insert`):
   - The `insert` function takes a string `s` as input and inserts it into the Trie by traversing the Trie from the root. It iterates over each character in the string, checks if the current character's link exists in the current node, and creates a new node if it doesn't. It then moves to the next node and repeats the process. Finally, it marks the last node as the end of a word by setting the `flag` to `true`.

4. Searching for a String in the Trie (`search`):
   - The `search` function takes a string `s` as input and searches for it in the Trie. It starts from the root and traverses the Trie, checking if each character's link exists in the current node. If any character's link is not found, it means the string does not exist in the Trie, and it returns `false`. If the entire string is found in the Trie, it returns `true`.

5. `completeString` Function:
   - The `completeString` function takes an integer `n` and a vector of strings `a` as input.
   - It creates an instance of the `Trie` class and inserts all the strings from the vector `a` into the Trie using the `insert` method.
   - It initializes an empty string `ans` to store the longest lexicographically smallest string found in the Trie.
   - It iterates over each string in `a` and checks if it exists in the Trie using the `search` method. If the string is found, it compares its length and lexicographic order with the current `ans` string and updates `ans` if necessary.
   - Finally, it returns the `ans` string, which represents the longest lexicographically smallest string found in the Trie. If no such string exists, it returns the string "None".

In summary, the code uses a Trie data structure to efficiently store and search for strings. The `completeString` function utilizes this Trie to find the longest lexicographically smallest string among a given set of strings.

### Complexity Analysis

The time and space complexity of the provided code are as follows:

Time Complexity:
1. Trie Insertion: The `insert` method iterates over each character of a string and performs operations on the Trie nodes. The time complexity of inserting a string of length `m` into the Trie is O(m).
2. Trie Search: The `search` method also iterates over each character of a string and performs operations on the Trie nodes. The time complexity of searching for a string of length `m` in the Trie is O(m).
3. Complete String Function: The `completeString` function inserts each string from the input vector into the Trie using the `insert` method, which has a time complexity of O(m) per string. Then, it iterates over each string and performs a search using the `search` method, which also has a time complexity of O(m) per string. Therefore, the overall time complexity of the `completeString` function is O(n * m), where `n` is the number of strings in the input vector and `m` is the maximum length of a string.

Space Complexity:
1. Trie Nodes: The space required for storing the Trie nodes depends on the total number of characters in the inserted strings. If there are `N` characters in total, the space complexity of the Trie nodes is O(N).
2. Complete String Function: The additional space used by the `completeString` function is primarily for the `ans` string, which can store at most `m` characters, where `m` is the length of the longest lexicographically smallest string found. Therefore, the space complexity of the `completeString` function is O(m).

In summary, the time complexity of the provided code is O(n * m), and the space complexity is O(N + m), where `n` is the number of strings, `m` is the length of the longest lexicographically smallest string, and `N` is the total number of characters in the inserted strings.

### Related Links

* [LeetCode | Problem 720 | Longest Word in Dictionary](https://leetcode.com/problems/longest-word-in-dictionary/)
* [GeeksForGeeks | Trie Data Structure](https://www.geeksforgeeks.org/trie-insert-and-search/)
* [Wikipedia | Trie](https://en.wikipedia.org/wiki/Trie)





