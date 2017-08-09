/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode tree_node_t;
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorder == NULL || postorder ==NULL || inorderSize == 0 || postorderSize == 0) return NULL;
    
    int idx = -1;
    for (int i = 0; i < inorderSize; i++) {
        if (postorder[postorderSize-1] == inorder[i]) {
            idx = i;
            break;
        }
    }
    if (idx == -1) return NULL;
    
    tree_node_t *root = (tree_node_t *) malloc(sizeof(tree_node_t));
    root->val = postorder[postorderSize-1];
    
    root->left = buildTree(inorder, idx, postorder, idx);
    root->right = buildTree(inorder + idx + 1, inorderSize - idx - 1, postorder + idx, postorderSize - idx - 1);
    
    return root;
}
