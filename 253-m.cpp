// https://leetcode.com/problems/meeting-rooms-ii/

class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        map<int, int> meetings;
        for (auto m : intervals)
            meetings[m[0]]++, meetings[m[1]]--;

        int res = 0, curr = 0;
        for (auto iter = meetings.begin(); iter != meetings.end(); iter++)
            curr += (iter->second), res = max(curr, res);

        return res;
    }
};