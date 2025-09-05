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

class Solution {
    unordered_map<int, int> ino; // maps value -> index in inorder
    int preoPos = 0; // global pointer to track root in preorder

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left > right) return nullptr; // no elements in this range

        // Step 1: Pick root from preorder
        int rootVal = preorder[preoPos++];
        TreeNode* root = new TreeNode(rootVal);

        // Step 2: Find root’s index in inorder
        int mid = ino[rootVal];

        // Step 3: Build left and right subtrees
        root->left = build(preorder, inorder, left, mid - 1);
        root->right = build(preorder, inorder, mid + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Fill hashmap for quick index lookup
        for (int i = 0; i < inorder.size(); i++) {
            ino[inorder[i]] = i;
        }
        // Call helper with full inorder range
        return build(preorder, inorder, 0, inorder.size() - 1);
    }
};
