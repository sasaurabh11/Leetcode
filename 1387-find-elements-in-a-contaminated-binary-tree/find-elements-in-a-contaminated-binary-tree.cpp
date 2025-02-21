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
class FindElements {
public:
    TreeNode* root;

    void solve(TreeNode* root) {
        if(root == NULL) return;

        if(root->left != NULL) {
            root->left->val = 2 * root->val + 1;
            solve(root->left);
        }

        if(root->right != NULL) {
            root->right->val = 2 * root->val + 2;
            solve(root->right);
        }
    }

    FindElements(TreeNode* root) {
        this->root = root;
        root->val = 0;
        solve(root);
    }
    
    bool check(TreeNode* root, int target) {
        if(root == NULL) return false;

        if(root->val == target) return true;

        bool ans1 = check(root->left, target);
        bool ans2 = check(root->right, target);

        return ans1 | ans2;
    }

    bool find(int target) {
        return check(root, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */