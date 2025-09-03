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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qNodes;
        qNodes.push(p);
        qNodes.push(q);

        while (!qNodes.empty()) {
            TreeNode* n1 = qNodes.front(); qNodes.pop();
            TreeNode* n2 = qNodes.front(); qNodes.pop();

            if (!n1 && !n2) continue;
            if (!n1 || !n2) return false;
            if (n1->val != n2->val) return false;

            qNodes.push(n1->left);
            qNodes.push(n2->left);
            qNodes.push(n1->right);
            qNodes.push(n2->right);
        }
        return true;
    }
};




 // RECURSIVE

// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         // Case 1: both empty
//         if (!p && !q) return true;

//         // Case 2: one empty
//         if (!p || !q) return false;

//         // Case 3: value mismatch
//         if (p->val != q->val) return false;

//         // Recursive check on both subtrees
//         return isSameTree(p->left, q->left) &&
//                isSameTree(p->right, q->right);
//     }
// };
