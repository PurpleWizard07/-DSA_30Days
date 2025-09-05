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
    int pos = 0; // counter for inorder position

    TreeNode* inorder(TreeNode* root, int k) {
        if (!root) return nullptr;

        TreeNode* left = inorder(root->left, k);
        if (left) return left;

        pos++;
        if (pos == k) return root;

        return inorder(root->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node = inorder(root, k);
        return node ? node->val : -1;
    }
};


// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         stack<TreeNode*> st;
//         TreeNode* curr = root;
//         int count = 0;

//         while (curr || !st.empty()) {
//             while (curr) {
//                 st.push(curr);
//                 curr = curr->left;
//             }
//             curr = st.top(); st.pop();
//             count++;
//             if (count == k) return curr->val;
//             curr = curr->right;
//         }
//         return -1; 
//     }
// };
