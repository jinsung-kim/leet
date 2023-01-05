// https://leetcode.com/problems/meeting-rooms/description/

class Solution
{
public:
    bool canAttendMeetings(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        for (size_t i = 1; i < intervals.size(); i++)
            if (intervals[i][0] < intervals[i - 1][1])
                return false;
        return true;
    }
};