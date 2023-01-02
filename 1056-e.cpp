// https://leetcode.com/problems/confusing-number/description/

class Solution
{
public:
    bool confusingNumber(int n)
    {
        string num = to_string(n);
        string res = num;

        reverse(num.begin(), num.end());

        for (size_t i = 0; i < num.size(); i++)
        {
            char v = num[i];
            if (v == '6')
                num[i] = '9';
            else if (v == '9')
                num[i] = '6';
            else if (v != '1' && v != '8' && v != '0')
                return false;
        }
        return res != num;
    }
};