#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        unordered_set<int> states;
        states.insert(0);

        for (char ch : p)
        {
            unordered_set<int> nextStates;
            for (int state : states)
            {
                if (ch == '*')
                {
                    for (int i = state; i <= s.size(); ++i)
                    {
                        nextStates.insert(i);
                    }
                }
                if (state >= s.size())
                    continue;
                if (s[state] == ch || ch == '?')
                {
                    nextStates.insert(state + 1);
                }
            }
            states = nextStates;
        }
        for (int state : states)
        {
            if (state == s.size())
                return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    string s = "acdcb";
    string p = "a*c?b";
    bool result = solution.isMatch(s, p);
    cout << boolalpha << result << endl;
    return 0;
}
