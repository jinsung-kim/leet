// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        int s, e, currEnd = points[0][1], arrows = 1;

        for (auto p : points)
        {
            s = p[0], e = p[1];
            if (s > currEnd)
                arrows++, currEnd = e;
        }

        return arrows;
    }
};