/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root) {
    int result = 1;
    /* Continue checking left child until left == NULL */
    if (root->left != NULL) {
        if (root->val > root->left->val) {
            result &= isValidBST(root->left);
        } else {
            /* Interrupt checking once violation BST rule */
            return 0;
        }
    }
    /* Continue checking right child until right == NULL */
    if (root->right != NULL) {
        if (root->val < root->right->val) {
            result &= isValidBST(root->right);
        } else {
            /* Interrupt checking once violation BST rule */
            return 0;
        }
    }
    
    return result;
}
