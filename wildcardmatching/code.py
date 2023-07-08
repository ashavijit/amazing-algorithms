class Solution:
    def isMatch(self,s,p):
        states = {0}
        for ch in p:
            next_states = set()
            for state in states:
                if ch == '*':
                    for i in range(state, len(s) + 1):
                        next_states.add(i)
                if state >= len(s):
                    continue
                if s[state] == ch or ch == '?':
                    next_states.add(state + 1)
            states = next_states
        return len(s) in states

solution = Solution()
s = "acdcb"
p = "a*c?b"
result = solution.isMatch(s, p)
print(result)
