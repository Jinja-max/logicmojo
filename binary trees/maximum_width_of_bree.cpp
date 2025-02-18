#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printPreOrder(TreeNode *node)
{
    if (node == nullptr)
        return;
    std::cout << node->val << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printQueue(deque<TreeNode *> &dq)
{
    cout << endl;
    if (dq.empty())
        cout << "empty";
    for (auto it : dq)
        cout << it << " ";
    cout << endl;
}

int widthOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    deque<TreeNode *> dq;
    dq.push_back(root);
    printQueue(dq);
    int ans = 1;
    while (!dq.empty())
    {
        int size = dq.size();
        if (size > ans)
            ans = size;
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = dq.front();
            dq.pop_front();
            printQueue(dq);
            if (curr != NULL)
            {
                dq.push_back(curr->left);
                printQueue(dq);
                dq.push_back(curr->right);
                printQueue(dq);
            }
            else
            {
                dq.push_back(NULL);
                dq.push_back(NULL);
            }
        }
        while (!dq.empty() && dq.front() == NULL)
        {
            dq.pop_front();
            printQueue(dq);
        }
        while (!dq.empty() && dq.back() == NULL)
        {
            dq.pop_back();
            printQueue(dq);
        }
    }
    return ans;
}

int main()
{
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node3_right = new TreeNode(3);
    TreeNode *node9 = new TreeNode(9);

    // Level 1
    TreeNode *node3_left = new TreeNode(3, node5, node3_right);
    TreeNode *node2 = new TreeNode(2, nullptr, node9);

    // Root
    TreeNode *root = new TreeNode(1, node3_left, node2);
    cout << endl;
    // printPreOrder(root);
    cout << widthOfBinaryTree(root) << endl;

    cout << endl;
    return 0;
}