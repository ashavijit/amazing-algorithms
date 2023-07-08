### PROBLEM STATEMENT

Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.

 

Example 1:
```
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
```
Example 2:
```
Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".
```

### Intuition

The problem is asking us to remove all occurrences of a substring from a string. We can do this by repeatedly finding the leftmost occurrence of the substring and removing it. We can use the KMP algorithm to find the leftmost occurrence of the substring in linear time.

### Algorithm

We can use the KMP algorithm to find the leftmost occurrence of the substring in linear time. The KMP algorithm uses a prefix table to find the longest prefix of the substring that is also a suffix of the substring. This allows us to skip over characters that we know will not match. We can use this to find the leftmost occurrence of the substring in linear time.

### Method 1: KMP

- calculating the prefix table
``` c++
void CalculateLPS(vector<int> &lps, string part, int n)
    {
        int i = 1, j = 0;
        while (i < n)
        {
            if (part[i] == part[j])
            {
                lps[i] = j + 1;
                i++;
                j++;
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
```

- finding the leftmost occurrence of the substring
``` c++
int KMP(string s, string part, int n, int m)
    {
        vector<int> lps(m, 0);
        CalculateLPS(lps, part, m);
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (s[i] == part[j])
            {
                i++;
                j++;
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        if (j == m)
        {
            return i - j;
        }
        return -1;
    }
```

- removing all occurrences of the substring
``` c++
string removeOccurrences(string s, string part)
    {
        int n = s.length(), m = part.length();
        int index = KMP(s, part, n, m);
        while (index != -1)
        {
            s.erase(index, m);
            n = s.length();
            index = KMP(s, part, n, m);
        }
        return s;
    }
```

### Method 2: Brute Force

- finding the leftmost occurrence of the substring
``` c++
int findIndex(string s, string part, int n, int m)
    {
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (s[i] == part[j])
            {
                i++;
                j++;
            }
            else
            {
                i = i - j + 1;
                j = 0;
            }
        }
        if (j == m)
        {
            return i - j;
        }
        return -1;
    }
```

- removing all occurrences of the substring
``` c++
string removeOccurrences(string s, string part)
    {
        int n = s.length(), m = part.length();
        int index = findIndex(s, part, n, m);
        while (index != -1)
        {
            s.erase(index, m);
            n = s.length();
            index = findIndex(s, part, n, m);
        }
        return s;
    }
```

### Complexity Analysis

- Time Complexity: O(n^2)
- Space Complexity: O(1)

### References

- [KMP Algorithm](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)
- [KMP Algorithm](https://www.youtube.com/watch?v=GTJr8OvyEVQ)
