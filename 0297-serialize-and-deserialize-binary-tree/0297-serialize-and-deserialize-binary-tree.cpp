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

class Codec {
public:
    // Serialize: preorder traversal
    string serialize(TreeNode* root) {
        if (!root) return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Deserialize helper
    TreeNode* build(queue<string>& nodes) {
        string val = nodes.front(); nodes.pop();
        if (val == "null") return nullptr;
        
        TreeNode* node = new TreeNode(stoi(val));
        node->left = build(nodes);
        node->right = build(nodes);
        return node;
    }

    // Deserialize: split string into queue, then recurse
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        string token;
        stringstream ss(data);
        while (getline(ss, token, ',')) {
            nodes.push(token);
        }
        return build(nodes);
    }
};
