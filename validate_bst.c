/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int start = 1;

bool isValidSubBST(struct TreeNode* root, int min, int max) {
    /* True if node is NULL */
    if (root == NULL) return 1;
    /* False if node->val is out of bound */
    if (start == 1) {
        start = 0;
        if (root->val < min || max < root->val) return 0;
    } else {
        if (root->val <= min || max <= root->val) return 0;
    }
    /* Search sub-trees on the left and right */
    return isValidSubBST(root->left, min, root->val) &&
        isValidSubBST(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root) {
    return isValidSubBST(struct TreeNode* root, INT_MIN, INT_MAX);
}

/* Common error, think of it:
 *        10 
 *       /  \
 *      5   15
 *         /  \
 *        6    20
 */
//bool isValidBST(struct TreeNode* root) {
//    int result = 1;
//    /* Continue checking left child until left == NULL */
//    if (root->left != NULL) {
//        if (root->left->val < root->val) {
//            result &= isValidBST(root->left);
//        } else {
//            /* Interrupt checking once violation BST rule */
//            return 0;
//        }
//    }
//    /* Continue checking right child until right == NULL */
//    if (root->right != NULL) {
//        if (root->val < root->right->val) {
//            result &= isValidBST(root->right);
//        } else {
//            /* Interrupt checking once violation BST rule */
//            return 0;
//        }
//    }
//    
//    return result;
//}
