## Problem Statement

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

```
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
```

The matching should cover the entire input string (not partial).

Example 1:

```
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

Example 2:

```
Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
```

Example 3:

```
Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
```

Example 4:

```
Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
```

Example 5:

```
Input:
s = "acdcb"
p = "a*c?b"
Output: false
```

## Solution Explanation

The algorithm implemented using the NFA (Nondeterministic Finite Automaton) approach utilizes the concept of simulating the pattern matching process using a state machine. Here's an intuition behind the algorithm in the NFA approach:

1. Initialization:
   - Create an initial state (0) and add it to the set of current states.
   - Iterate through the pattern string and determine the transitions for each character.

2. Pattern Matching:
   - Iterate through the input string character by character.
   - For each character in the input string, update the set of current states based on the transitions from the previous set of states:
     - If the character matches the transition symbol, add the destination state of the transition to the set of current states.
     - If the transition symbol is a wildcard or matches any character, add all possible destination states to the set of current states.

3. Repeat Step 2 until all characters in the input string are processed.

4. Final Check:
   - After processing all characters in the input string, check if any of the current states are accepting states (representing a complete match).
   - If there is at least one accepting state, return true; otherwise, return false.

__The NFA approach allows for non-deterministic transitions, meaning that multiple transitions can be taken simultaneously based on different conditions. This enables the algorithm to handle wildcard characters like '*' and '?' effectively. By updating the set of current states at each step, the algorithm explores all possible paths and determines if a valid match exists.__

_Overall, the NFA approach provides a flexible and efficient way to simulate the pattern matching process, considering all possible transitions and allowing for wildcard matching. It avoids the need to construct an explicit DFA (Deterministic Finite Automaton) and instead works with a set of possible states during the pattern matching process._

## Complexity Analysis

The time and space complexity of the pattern matching algorithm using the NFA approach with wildcard characters '*' and '?' can be analyzed as follows:

Time Complexity:
- Construction of NFA: O(m), where m is the length of the pattern string `p`. It involves iterating through the pattern string and creating states and transitions.
- Matching Process: O(n), where n is the length of the input string `s`. It involves iterating through the input string and updating the set of current states based on the transitions.
- Final Check: O(k), where k is the number of states. It involves checking if any state is an accepting state.

Overall, the time complexity of the algorithm is O(max(m, n, k)). In the worst case, it depends on the length of the longer string between the pattern string and the input string, as well as the number of states in the NFA.

Space Complexity:
- NFA Representation: O(m), where m is the length of the pattern string `p`. It involves storing states and transitions based on the pattern.
- Set of Current States: O(k), where k is the number of states. It represents the set of states that can be reached during the matching process.

Overall, the space complexity of the algorithm is O(max(m, k)). It depends on the length of the pattern string and the number of states in the NFA.


## Link to OJ

https://leetcode.com/problems/wildcard-matching/
Leetcode: 44. Wildcard Matching

### Example Analysis

:)

Example:
```
string s = "acd";
string p = "a*d";

```

The input string `s` is "acd" and the pattern `p` is "a*d". We'll go step by step through the code:

1. Initialize `states` set and insert the start state (0).
   ```
   states = {0}
   ```

2. Iterate through each character `ch` in the pattern string `p`.

   - For `ch = 'a'`:
     - Check each state in `states`.
     - Since `'a'` matches the first character in `s`, we move to the next state by inserting `state + 1` into `nextStates`.
     - `states = {1}`

   - For `ch = '*'`:
     - Iterate through each state in `states`.
     - Since `'*'` is a wildcard, we can match from 0 characters up to the entire remaining string `s`. Therefore, we insert all states from the current state to the end of `s` into `nextStates`.
     - `states = {1, 2, 3}`

   - For `ch = 'd'`:
     - Check each state in `states`.
     - Since `'d'` matches the third character in `s`, we move to the next state by inserting `state + 1` into `nextStates`.
     - `states = {2, 3, 4}`

3. After processing all characters in `p`, we check if any state in `states` has reached the end state (length of `s`).

   - In this case, the state `4` is equal to the length of `s`, which means the entire string `s` has been matched.
   - We return `true`, indicating that there is a match.

Therefore, for the given example, the output of the function `isMatch(s, p)` would be `true`. The pattern "a*d" matches the string "acd" by treating '*' as a wildcard that can match any number of characters.


