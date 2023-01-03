// https://leetcode.com/problems/reward-top-k-students/description/

class Solution
{
public:
    vector<int> topStudents(vector<string> &positive_feedback, vector<string> &negative_feedback, vector<string> &report, vector<int> &student_id, int k)
    {
        vector<int> res;

        // fill sets
        for (string word : positive_feedback)
            pos.insert(word);

        for (string word : negative_feedback)
            neg.insert(word);

        map<int, vector<int>> scores;
        // generate scores from report
        for (size_t i = 0; i < report.size(); i++)
        {
            int curr = scoreReport(report[i]) * -1;
            if (scores.find(curr) == scores.end())
                scores[curr] = {student_id[i]};
            else
                scores[curr].push_back(student_id[i]);
        }

        for (auto iter = scores.begin(); iter != scores.end(); iter++)
        {
            // sort ids if the score is the same
            sort(iter->second.begin(), iter->second.end());
            size_t i = 0;
            while (k > 0 && i < iter->second.size())
            {
                res.push_back(iter->second[i]);
                i++, k--;
            }
        }

        return res;
    }

private:
    int scoreReport(string report)
    {
        string word = "";
        int res = 0;

        for (char c : report)
        {
            if (c != ' ')
                word += c;
            else
            {
                if (pos.find(word) != pos.end())
                    res += 3;
                else if (neg.find(word) != neg.end())
                    res -= 1;
                word = "";
            }
        }

        if (!word.empty())
        {
            if (pos.find(word) != pos.end())
                res += 3;
            else if (neg.find(word) != neg.end())
                res -= 1;
        }

        return res;
    }

    unordered_set<string> pos, neg;
};