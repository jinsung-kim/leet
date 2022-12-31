// https://leetcode.com/problems/two-sum-less-than-k/description/

class Solution
{
public:
    int twoSumLessThanK(vector<int> &nums, int k)
    {
        int res = INT_MIN;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1, curr;

        while (i < j)
        {
            curr = nums[i] + nums[j];
            if (curr < k)
            {
                res = max(curr, res);
                i++;
            }
            else
                j--;
        }

        return res == INT_MIN ? -1 : res;
    }
};