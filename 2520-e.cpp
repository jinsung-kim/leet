// https://leetcode.com/problems/count-the-digits-that-divide-a-number/description/

class Solution
{
public:
    int countDigits(int num)
    {
        int res = 0, orig = num;
        while (num)
        {
            if (orig % (num % 10) == 0)
                res++;
            num /= 10;
        }

        return res;
    }
};