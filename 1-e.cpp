// https://leetcode.com/problems/two-sum/

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> indMap;

        for (int i = 0; i < nums.size(); i++)
        {
            if (indMap.find(target - nums[i]) != indMap.end())
                return {indMap[target - nums[i]], i};
            else
                indMap[nums[i]] = i;
        }

        return {};
    }
};