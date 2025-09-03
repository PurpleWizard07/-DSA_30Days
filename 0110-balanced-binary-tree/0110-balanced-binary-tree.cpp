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


// BOTTOM UP 

class Solution {
public:
    int checkHeight(TreeNode* root) {
        if (!root) return 0;

        int left = checkHeight(root->left);
        if (left == -1) return -1;  // left unbalanced

        int right = checkHeight(root->right);
        if (right == -1) return -1; // right unbalanced

        if (abs(left - right) > 1) return -1; // this node unbalanced

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};



// BRUTE FORCE (TOP-DOWN)

// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if(!root) return true;

//         int left = height(root->left);
//         int right = height(root->right);
//         if(abs(left - right) > 1) return false;
//         return isBalanced(root->left) && isBalanced(root->right);
//     }
//     int height(TreeNode* root) {
//         if(root == nullptr) return 0;
//         return 1 + max(height(root->left), height(root->right));
//     }
// };