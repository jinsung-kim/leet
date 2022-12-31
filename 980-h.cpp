// https://leetcode.com/problems/unique-paths-iii/

class Solution
{
public:
    int uniquePathsIII(vector<vector<int>> &g)
    {
        int si = 0, sj = 0;

        for (int i = 0; i < g.size(); i++)
        {
            for (int j = 0; j < g[0].size(); j++)
            {
                if (g[i][j] != -1)
                    t++;
                if (g[i][j] == 1)
                    si = i, sj = j;
            }
        }

        return dfs(g, si, sj, 1);
    }

private:
    int t = 0; // total steps
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int dfs(vector<vector<int>> &g, int i, int j, int s)
    {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == -1)
            return 0;
        if (g[i][j] == 2)
            return s == t ? 1 : 0;

        int res = 0;
        g[i][j] = -1;

        for (auto d : dir)
            res += dfs(g, i + d[0], j + d[1], s + 1);

        g[i][j] = 0;
        return res;
    }
};