class Solution
{
public:
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

    int kmp(string s, string part, vector<int> &lps, int n, int m)
    {
        int i = 0, j = 0;
        while (i < n)
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
            if (j == m)
            {
                return i - m;
            }
        }
        return -1;
    }

    string removeOccurrences(string s, string part)
    {
        int n = part.size();
        int m = s.size();
        vector<int> lps(n, 0);
        CalculateLPS(lps, part, n);
        int startindex = kmp(s, part, lps, m, n);
        while (startindex != -1)
        {
            s.erase(startindex, n);
            m = s.size();
            startindex = kmp(s, part, lps, m, n);
        }
        return s;
    }
};