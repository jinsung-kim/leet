#include <bits/stdc++.h>
// https://leetcode.com/problems/find-players-with-zero-or-one-losses/

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<vector<int>> res(2, vector<int>());
        map<int, int> losers;
        set<int> allPlayers;

        for (auto match : matches)
        {
            losers[match[1]]++;
            allPlayers.insert(match[0]);
            allPlayers.insert(match[1]);
        }

        for (auto iter = allPlayers.begin(); iter != allPlayers.end(); iter++)
        {
            if (losers.find(*iter) == losers.end())
                res[0].push_back(*iter);
            else if (losers[*iter] == 1)
                res[1].push_back(*iter);
        }

        return res;
    }
};