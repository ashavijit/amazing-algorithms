class Solution
{
public:
    bool isNumber(string s)
    {
        if (s.empty())
        {
            return false;
        }

        int state = 0;
        int n = s.length();
        int i = 0;

        while (i < n && s[i] == ' ')
        {
            i++;
        }
        while (i < n && s[n - 1] == ' ')
        {
            n--;
        }

        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            i++;
        }

        bool hasDigitsBeforeDot = false;
        while (i < n && isdigit(s[i]))
        {
            i++;
            hasDigitsBeforeDot = true;
            state = 1;
        }

        if (i < n && s[i] == '.')
        {
            i++;
            while (i < n && isdigit(s[i]))
            {
                i++;
                state = 2;
            }
        }

        if (!hasDigitsBeforeDot && state != 2)
        {
            return false; // Must have digits before dot or dot itself
        }

        if (i < n && (s[i] == 'e' || s[i] == 'E'))
        {
            i++;

            if (i < n && (s[i] == '+' || s[i] == '-'))
            {
                i++;
            }

            bool hasDigitsAfterE = false;
            while (i < n && isdigit(s[i]))
            {
                i++;
                hasDigitsAfterE = true;
                state = 3;
            }

            if (!hasDigitsAfterE)
            {
                return false; // Must have at least one digit after 'e' or 'E'
            }
        }

        while (i < n && s[i] == ' ')
        {
            i++;
        }

        return i == n && (state == 1 || state == 2 || state == 3);
    }
};