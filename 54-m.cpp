// https://leetcode.com/problems/spiral-matrix/description/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int top = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1, d = 0, i;
        while (top <= down && left <= right)
        {
            if (d == 0)
            {
                for (i = left; i <= right; i++)
                    res.push_back(matrix[top][i]);
                top++;
            }
            else if (d == 1)
            {
                for (i = top; i <= down; i++)
                    res.push_back(matrix[i][right]);
                right--;
            }
            else if (d == 2)
            {
                for (i = right; i >= left; i--)
                    res.push_back(matrix[down][i]);
                down--;
            }
            else if (d == 3)
            {
                for (i = down; i >= top; i--)
                    res.push_back(matrix[i][left]);
                left++;
            }

            d = (d + 1) % 4;
        }

        return res;
    }
};