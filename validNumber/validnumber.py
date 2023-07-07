class Solution:
    def isNumber(self, s: str) -> bool:
        state = 0
        
        # Remove leading and trailing whitespace
        s = s.strip()
        
        for i in range(len(s)):
            if '0' <= s[i] <= '9':
                flag = 1
                if state <= 2:
                    state = 2
                else:
                    state = 5 if state <= 5 else 7
            elif s[i] == '+' or s[i] == '-':
                if state == 0 or state == 3:
                    state += 1
                else:
                    return False
            elif s[i] == '.':
                if state <= 2:
                    state = 6
                else:
                    return False
            elif s[i] == 'e':
                if flag and (state == 2 or state == 6 or state == 7):
                    state = 3
                else:
                    return False
            else:
                return False
        
        return state == 2 or state == 5 or (flag and state == 6) or state == 7
