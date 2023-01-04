// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        int res = 0, occ;
        map<int, int> m; // no of tasks

        for (int t : tasks)
            m[t]++;

        for (auto iter = m.begin(); iter != m.end(); iter++)
        {
            occ = iter->second;

            if (occ == 1)
                return -1;
            else if (occ == 2)
                res++;
            else
                res += ceil(double(occ) / 3.0);
        }

        return res;
    }
};