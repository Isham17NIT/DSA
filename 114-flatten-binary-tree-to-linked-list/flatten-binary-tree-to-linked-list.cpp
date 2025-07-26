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
private:
    void flattenLL(TreeNode* root)
    {
        if(root)
        {
            flattenLL(root->left);
            flattenLL(root->right);
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = nullptr;
            TreeNode* temp1 = root;
            while(temp1->right){
                temp1 = temp1->right;
            }
            temp1->right = temp;
        }
        return;
    }
public:
    void flatten(TreeNode* &root) {
        flattenLL(root);
    }
};