// https://leetcode.com/problems/diameter-of-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        find(root);
        return res;
    }

private:
    int res = 0;
    int find(TreeNode *node)
    {
        if (!node)
            return 0;
        int l = find(node->left), r = find(node->right);
        res = max(l + r, res);
        return max(l, r) + 1;
    }
};