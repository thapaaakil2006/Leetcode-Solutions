/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // Maps value to the actual TreeNode pointer
        unordered_map<int, TreeNode*> nodeMap;
        // Keeps track of all values that are children
        unordered_set<int> children;
        
        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            int isLeft = desc[2];
            
            // 1. Create or retrieve the parent node
            if (nodeMap.find(parentVal) == nodeMap.end()) {
                nodeMap[parentVal] = new TreeNode(parentVal);
            }
            TreeNode* parentNode = nodeMap[parentVal];
            
            // 2. Create or retrieve the child node
            if (nodeMap.find(childVal) == nodeMap.end()) {
                nodeMap[childVal] = new TreeNode(childVal);
            }
            TreeNode* childNode = nodeMap[childVal];
            
            // 3. Link parent and child
            if (isLeft == 1) {
                parentNode->left = childNode;
            } else {
                parentNode->right = childNode;
            }
            
            // 4. Mark this node as a child
            children.insert(childVal);
        }
        
        // 5. Find the root (the parent node that is never anyone's child)
        for (const auto& desc : descriptions) {
            int parentVal = desc[0];
            if (children.find(parentVal) == children.end()) {
                return nodeMap[parentVal];
            }
        }
        
        return nullptr;
    }
};