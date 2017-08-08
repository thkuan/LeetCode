/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode tree_node_t;

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorder == NULL || inorder ==NULL || preorderSize == 0 || inorderSize == 0) return NULL;
    
    int idx = -1;
    for (int i = 0; i < preorderSize; i++) {
        if (preorder[0] == inorder[i]) {
            idx = i;
            break;
        }
    }
    if (idx == -1) return NULL;
    
    tree_node_t *root = (tree_node_t *) malloc(sizeof(tree_node_t));
    root->val = preorder[0];
    
    root->left = buildTree(preorder + 1, idx, inorder, idx);
    root->right = buildTree(preorder + idx + 1, preorderSize - idx - 1, inorder + idx + 1, inorderSize - idx - 1);
    
    return root;
}
