// https://leetcode.com/problems/detect-capital/description/

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int capUse = 0;
        bool first = isupper(word[0]);

        for (char c : word)
            if (isupper(c))
                capUse++;

        if (capUse == word.size())
            return true;
        if (capUse == 1 && first)
            return true;
        if (capUse == 0)
            return true;
        return false;
    }
};