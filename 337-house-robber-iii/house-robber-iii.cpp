
class Solution {
public:
    int robSub(TreeNode* root, unordered_map<TreeNode*, int>& mp) {
        if (root == NULL) return 0;

        if (mp.find(root) != mp.end()) {
            return mp[root];
        }

        int val = 0;

        if (root->left != NULL) {
            val += robSub(root->left->left, mp)
                 + robSub(root->left->right, mp);
        }

        if (root->right != NULL) {
            val += robSub(root->right->left, mp)
                 + robSub(root->right->right, mp);
        }

        val = max(val + root->val,
                  robSub(root->left, mp) + robSub(root->right, mp));

        mp[root] = val;

        return val;
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        return robSub(root, mp);
    }
};