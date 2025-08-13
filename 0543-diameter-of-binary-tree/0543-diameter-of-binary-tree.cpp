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
public:
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, int> depthMap;
        stack<TreeNode*> st;
        int diameter = 0;

        if (root != nullptr) {
            st.push(root);
        }

        while (!st.empty()) {
            TreeNode* node = st.top();

            // If left child exists and is not processed yet
            if (node->left != nullptr && depthMap.find(node->left) == depthMap.end()) {
                st.push(node->left);
            }
            // Else if right child exists and is not processed yet
            else if (node->right != nullptr && depthMap.find(node->right) == depthMap.end()) {
                st.push(node->right);
            }
            else {
                // Process current node
                st.pop();

                int leftDepth = depthMap.count(node->left) ? depthMap[node->left] : 0;
                int rightDepth = depthMap.count(node->right) ? depthMap[node->right] : 0;

                // Store height of current node
                depthMap[node] = 1 + max(leftDepth, rightDepth);

                // Update diameter
                diameter = max(diameter, leftDepth + rightDepth);
            }
        }

        return diameter;
    }
};
