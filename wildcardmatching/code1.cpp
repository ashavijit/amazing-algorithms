#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        unordered_map<pair<int, char>, int, pair_hash> transfer; // pair_hash is defined below
        int state = 0;

        for (char ch : p)
        {
            if (ch == '*')
            {
                transfer[{state, ch}] = state; // if '*' exists it can match all letters take all steps
            }
            else
            {
                transfer[{state, ch}] = state + 1; // else if a single ch can be matched
                state += 1;
            }
        }

        int accept = state;
        unordered_set<int> states = {0};

        for (char ch : s)
        {
            unordered_set<int> nextStates;
            for (int at : states)
            {
                auto it = transfer.find({at, ch}); // find the next state
                if (it != transfer.end())
                {
                    nextStates.insert(it->second);
                }
                it = transfer.find({at, '*'});
                if (it != transfer.end())
                {
                    nextStates.insert(it->second);
                }
                it = transfer.find({at, '?'});
                if (it != transfer.end())
                {
                    nextStates.insert(it->second);
                }
            }
            states = move(nextStates);
        }

        return states.count(accept) > 0; // if the accept state is in the set of states
    }

private:
    struct pair_hash // hash function for pair
    {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2> &p) const
        {
            auto h1 = hash<T1>{}(p.first);
            auto h2 = hash<T2>{}(p.second); 
            return h1 ^ h2; // or use boost::hash_combine
        }
    };
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


// solution By @AvijitSen  