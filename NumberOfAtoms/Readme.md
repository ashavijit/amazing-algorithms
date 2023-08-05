Given a string formula representing a chemical formula, return the count of each atom.

- The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

- One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

- For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
Two formulas are concatenated together to produce another formula.

- For example, "H2O2He3Mg4" is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula.

- For example, "(H2O2)" and "(H2O2)3" are formulas.
Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

- The test cases are generated so that all the values in the output fit in a 32-bit integer.


Example 1:

```
Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.
```

Example 2:

```
Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
```

Example 3:

```
Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
```

### Intuition

 Let's use the example formula "K4(ON(SO3)2)2" to build the Abstract Syntax Tree (AST) step by step.

Step 1: Parsing and Building the AST

We start with an empty root node. As we parse the formula, we build the AST by adding nodes for each atom and subgroup encountered.

1. Parse "K4":
```
        Root Node:
           |
           V
      ----------------
      |       |      |
     K       4      | 
                  (Subgroup)
```
The AST now has a node for "K" with count 4 and an empty subgroup node.

2. Parse "(ON(SO3)2)":
```
        Root Node:
           |
           V
      --------------------
      |        |         |
     K        4        ON
                       |
                       V
                -------------
                |      |     |
                O      |     2
                      (Subgroup)
                      |
                      V
                 -----------------
                 |      |       |
                 S      O       3
```
The AST now includes the subgroup "ON(SO3)2". It contains nodes for "O" with count 1 and "N" with count 1. The subgroup "SO3" is nested inside, with nodes for "S" with count 1 and "O" with count 3.

3. Parse "2":
```
        Root Node:
           |
           V
      --------------------
      |        |         |
     K        4        ON
                       |
                       V
                -------------
                |      |     |
                O      |     2
                      (Subgroup)
                      |
                      V
                 -----------------
                 |      |       |
                 S      O       3
```
The AST now updates the count of the subgroup "ON(SO3)2" to 2.

4. Parse "2" (Outermost):
```
        Root Node:
           |
           V
      --------------------
      |        |         |
     K        4        ON
                       |
                       V
                -------------
                |      |     |
                O      |     2
                      (Subgroup)
                      |
                      V
                 -----------------
                 |      |       |
                 S      O       3
```
The AST updates the count of the entire formula "K4(ON(SO3)2)2" to 2.

Step 2: Counting Atoms from the AST

Now that we have the AST, we traverse it to count the occurrences of each atom.

- Count of Atoms:
```
{
    "K": 4 * 2 = 8,
    "N": 1 * 2 = 2,
    "O": (1 * 2) + (3 * 2) = 8,
    "S": 1 * 2 = 2
}
```

Step 3: Constructing the Output String

We construct the output string by iterating through the sorted atom counts and concatenating the atom name and its count (if greater than 1) into the result string.

Output String: "K8N2O8S2"

Explanation:

The AST representation and counting of atoms help us correctly determine the counts of each atom in the formula "K4(ON(SO3)2)2". The output string "K8N2O8S2" represents the correct count of each atom in the formula.




### _Grammar Analysis_

The grammar for the formula representation you provided is as follows:

```
F →  EF | ε
E → (F) | AN
A → <Atom>
N → <Number>
```

Where:
- `F` is a formula that can be either an element `E` followed by another formula `F`, or it can be empty (`ε`).
- `E` represents an element or a subgroup, which can be enclosed in parentheses and followed by a number.
- `A` represents an atom, which is a capital letter followed by zero or more lowercase letters.
- `N` represents a number, which is one or more digits.

Here's an explanation of each non-terminal in the grammar:

- `F`: A formula that can be either an element (or subgroup) followed by another formula, or it can be empty. For example, "C5H6N2" or "(NH3)2" are formulas, and an empty formula is also valid.
- `E`: Represents an element or a subgroup in the formula. For example, "C5" or "(NH3)2".
- `A`: Represents an atom, which is a chemical element name such as "C" or "H".
- `N`: Represents a number that follows an atom or a subgroup. For example, "5" in "C5" or "2" in "(NH3)2".

_The grammar is LL(1) (Left-to-right, Leftmost derivation, with 1 symbol lookahead), which means that you can use predictive parsing techniques to construct a parser for this grammar. It allows you to parse a formula and build an Abstract Syntax Tree (AST) that represents the hierarchical structure of the formula, as demonstrated in the earlier code._

### _Parsing_

The grammar is LL(1), which means that you can use predictive parsing techniques to construct a parser for this grammar. It allows you to parse a formula and build an Abstract Syntax Tree (AST) that represents the hierarchical structure of the formula, as demonstrated in the earlier code.

### _Counting_

Once you have the AST, you can traverse it to count the occurrences of each atom. The count of each atom is the product of the count of its parent and its own count. For example, the count of "O" in the formula "K4(ON(SO3)2)2" is 2 * 2 * 1 = 4, because the count of "O" in the subgroup "ON(SO3)2" is 2, and the count of the subgroup is 2.


### _Time Complexity_

Time Complexity:
The time complexity of the provided solution mainly depends on the size of the input formula. Let's analyze the different steps of the solution:

1. Parsing and Building the AST: In this step, we traverse the input formula to build the Abstract Syntax Tree (AST). The traversal process visits each character of the formula once. Therefore, the time complexity of this step is O(N), where N is the length of the formula.

2. Counting Atoms from the AST: In this step, we traverse the AST to count the occurrences of each atom. The traversal visits each node of the AST once. The total number of nodes in the AST is proportional to the number of atoms in the formula. Therefore, the time complexity of this step is also O(N), where N is the number of atoms in the formula.

3. Constructing the Output String: In this step, we iterate through the sorted atom counts to construct the output string. Constructing the output string requires visiting each atom in the count map once. Therefore, the time complexity of this step is O(M log M), where M is the number of unique atoms in the formula. In the worst case, M can be proportional to N, but in practice, it is usually much smaller.

Overall, the time complexity of the solution is O(N + N + M log M) = O(N + M log M). In most cases, the number of unique atoms (M) is much smaller than the length of the formula (N), so the time complexity can be approximated to O(N).

Space Complexity:
The space complexity of the provided solution comes from the space used by the Abstract Syntax Tree (AST) and the space used for the count map of atoms.

1. AST: The space used by the AST depends on the nesting level of subgroups in the formula. In the worst case, the nesting level can be proportional to the number of atoms (N), resulting in a space complexity of O(N).

2. Count Map: The count map stores the count of each atom encountered in the formula. In the worst case, if all atoms in the formula are unique, the count map can have a size of M (the number of unique atoms). Therefore, the space complexity for the count map is O(M).

Overall, the space complexity of the solution is O(N + M). In most practical scenarios, M is much smaller than N, so the space complexity can be approximated to O(N).

In summary, the provided solution has a time complexity of O(N + M log M) and a space complexity of O(N + M), where N is the length of the formula, and M is the number of unique atoms in the formula. The time complexity is mainly dominated by parsing the formula and constructing the output string, while the space complexity is determined by the size of the AST and the count map of atoms.




