// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0, l = 0, r = 0;
        unordered_map<char, int> ls; // last seen

        for (; r < s.size(); r++)
        {
            if (ls[s[r]] > 0)
                l = max(l, ls[s[r]]);
            res = max(res, r - l + 1);
            ls[s[r]] = r + 1;
        }

        return res;
    }
};