class Solution
{
public:
    bool isNumber(string str)
    {
        int state = 0, flag = 0; 

        for (int i = 0; i < str.length(); i++)
        {
            if ('0' <= str[i] && str[i] <= '9')
            {
                flag = 1;
                if (state <= 2)
                    state = 2;
                else
                    state = (state <= 5) ? 5 : 7;
            }
            else if ('+' == str[i] || '-' == str[i])
            {
                if (state == 0 || state == 3)
                    state++;
                else
                    return false;
            }
            else if ('.' == str[i])
            {
                if (state <= 2)
                    state = 6;
                else
                    return false;
            }
            else if ('e' == str[i] || 'E' == str[i])
            {
                if (flag && (state == 2 || state == 6 || state == 7))
                {
                    state = 3;
                    flag = 0;
                }
                else
                    return false;
            }
            else
                return false;
        }

        return (state == 2 || state == 5 || (flag && state == 6) || state == 7);
    }
};