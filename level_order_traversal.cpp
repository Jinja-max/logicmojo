#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    vector<vector<int>> res;
    while (!q.empty())
    {
        vector<TreeNode *> nextlevel;
        vector<int> temp;
        while (!q.empty())
        {
            temp.push_back(q.front()->val);
            if (q.front()->left != nullptr)
                nextlevel.push_back(q.front()->left);
            if (q.front()->right != nullptr)
                nextlevel.push_back(q.front()->right);
            q.pop();
        }
        res.push_back(temp);
        for (int i = 0; i < nextlevel.size(); i++)
            q.push(nextlevel[i]);
    }

    return res;
}

int main()
{
    TreeNode *root = new TreeNode;
    root->val = 1;
    root->left = new TreeNode;
    root->left->val = 2;
    root->right = new TreeNode;
    root->right->val = 3;
    // Assuming the initial tree construction is in place

    // Extend left subtree to level 2
    root->left->left = new TreeNode;
    root->left->left->val = 4;
    root->left->right = new TreeNode;
    root->left->right->val = 5;

    // Extend right subtree to level 2
    root->right->left = new TreeNode;
    root->right->left->val = 6;
    root->right->right = new TreeNode;
    root->right->right->val = 7;
    // Extending left subtree to level 3
    root->left->left->left = new TreeNode;
    root->left->left->left->val = 8;
    root->left->left->right = new TreeNode;
    root->left->left->right->val = 9;
    root->left->right->left = new TreeNode;
    root->left->right->left->val = 10;
    root->left->right->right = new TreeNode;
    root->left->right->right->val = 11;

    // Extending right subtree to level 3
    root->right->left->left = new TreeNode;
    root->right->left->left->val = 12;
    root->right->left->right = new TreeNode;
    root->right->left->right->val = 13;
    root->right->right->left = new TreeNode;
    root->right->right->left->val = 14;
    root->right->right->right = new TreeNode;
    root->right->right->right->val = 15;

    vector<vector<int>> res;
    res = levelOrder(root);
    for (int i = 0; i < res.size(); i++)
    {
        cout << "level : " << i << " is : ";
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}