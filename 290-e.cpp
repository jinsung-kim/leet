// https://leetcode.com/problems/word-pattern/description/

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> m;
        unordered_set<string> vs;
        vector<string> words;

        string curr = "";
        for (char c : s)
        {
            if (c == ' ')
                words.push_back(curr), curr = "";
            else
                curr += c;
        }

        if (!curr.empty())
            words.push_back(curr);
        if (words.size() != pattern.size())
            return false;

        for (size_t i = 0; i < pattern.size(); i++)
        {
            if (m.find(pattern[i]) == m.end())
            {
                if (vs.find(words[i]) != vs.end())
                    return false;
                vs.insert(words[i]);
                m[pattern[i]] = words[i];
            }
            else if (m[pattern[i]] != words[i])
                return false;
        }

        return true;
    }
};