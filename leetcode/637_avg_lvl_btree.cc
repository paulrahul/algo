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
    void bfs(TreeNode* root, int level, vector<int>* num_siblings, vector<double>* averages) {
        if (averages->size() < level) {
            averages->push_back(0.0);
            num_siblings->push_back(1);
        } else {
            num_siblings->at(level - 1)++;
        }
        
        int idx = num_siblings->at(level - 1);
        double old_sum = averages->at(level - 1) * (idx - 1);
        double new_avg = (old_sum + root->val) / idx;
        averages->at(level - 1) = new_avg;
        
        
        if (root->left != nullptr) {
            bfs(root->left, level + 1, num_siblings, averages);
        }
        
        if (root->right != nullptr) {
            bfs(root->right, level + 1, num_siblings, averages);
        }
    }
    
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        vector<int> num_siblings;
        bfs(root, 1, &num_siblings, &averages);
        
        return averages;
    }
};