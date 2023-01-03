// https://leetcode.com/problems/delete-columns-to-make-sorted/description/

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int res = 0;

        for (size_t i = 0; i < strs[0].size(); i++)
        {
            bool sorted = true;
            for (size_t j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] < strs[j - 1][i])
                {
                    sorted = false;
                    break;
                }
            }
            if (!sorted)
                res++;
        }

        return res;
    }
};