class Solution:
    def myAtoi(self, s: str) -> int:
        val = 0
        pos = 0
        sign = 1  # Default sign is positive
        state = 0

        # Check if empty
        if len(s) == 0:
            return 0

        while pos < len(s):
            current_char = s[pos]

            # DFA STATES
            if state == 0:
                if current_char == ' ':
                    state = 0
                elif current_char == '+' or current_char == '-':
                    state = 1
                    sign = 1 if current_char == '+' else -1
                elif current_char.isdigit():
                    state = 2
                    val = val * 10 + int(current_char)
                else:
                    return 0
            elif state == 1:
                if current_char.isdigit():
                    state = 2
                    val = val * 10 + int(current_char)
                else:
                    break
            else:
                break
            pos += 1

        val = sign * val
        val = max(-2 ** 31, val)
        val = min(2 ** 31 - 1, val)

        return val

solution = Solution()
input_str = "42"
result = solution.myAtoi(input_str)
print("Result:", result)
