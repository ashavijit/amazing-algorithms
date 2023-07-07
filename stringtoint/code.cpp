#include <iostream>
#include <cmath>
#include <string>

class Solution
{
public:
    int myAtoi(std::string s)
    {
        int val = 0;
        int pos = 0;
        int sign = 1; // Default sign is positive
        int state = 0;

        // Check if empty
        if (s.empty())
        {
            return 0;
        }

        while (pos < s.length())
        {
            char current_char = s[pos];

            // DFA STATES
            if (state == 0)
            {
                if (current_char == ' ')
                {
                    state = 0;
                }
                else if (current_char == '+' || current_char == '-')
                {
                    state = 1;
                    sign = (current_char == '+') ? 1 : -1;
                }
                else if (isdigit(current_char))
                {
                    state = 2;
                    val = val * 10 + (current_char - '0');
                }
                else
                {
                    return 0;
                }
            }
            else if (state == 1)
            {
                if (isdigit(current_char))
                {
                    state = 2;
                    val = val * 10 + (current_char - '0');
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
            pos++;
        }

        val = sign * val;
        val = std::max(-static_cast<int>(pow(2, 31)), val);
        val = std::min(static_cast<int>(pow(2, 31) - 1), val);

        return val;
    }
};

int main()
{
    Solution solution;
    std::string input = "42";
    int result = solution.myAtoi(input);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
