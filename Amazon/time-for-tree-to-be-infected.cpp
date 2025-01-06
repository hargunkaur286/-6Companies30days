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
    // Function to find the target node in the tree
    TreeNode* findnode(TreeNode* root, int target) {
        // Base condition: If the root is null or the target is found
        if (!root || root->val == target) {
            return root;
        }

        // Recursively search in the left and right subtrees
        TreeNode* left = findnode(root->left, target);
        if (left) return left; // If found in the left subtree, return it

        return findnode(root->right, target); // Otherwise, search in the right subtree
    }

    // Function to build the graph representation of the tree
    unordered_map<TreeNode*, vector<TreeNode*>> umap;
    void buildmap(TreeNode* node, TreeNode* parent) {
        if (!node) return;

        if (umap.find(node) == umap.end()) {
            vector<TreeNode*> vec;
            umap[node] = vec;
            if (parent) {
                umap[node].push_back(parent);
                umap[parent].push_back(node);
            }
            buildmap(node->left, node);
            buildmap(node->right, node);
        }
    }

    // Function to simulate the burning process
    void burntree(TreeNode* root, TreeNode* target, vector<vector<int>>& ans) {
        if (!root) return;
        buildmap(root, nullptr);
        if (umap.find(target) == umap.end()) return;

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        visited.insert(target);
        q.push(target);

        while (!q.empty()) {
            vector<int> res;
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                auto curr = q.front();
                q.pop();
                res.push_back(curr->val);
                for (auto next : umap[curr]) {
                    if (visited.find(next) != visited.end())
                        continue;

                    visited.insert(next);
                    q.push(next);
                }
            }
            ans.push_back(res);
        }
    }

    // Main function to calculate the amount of time to burn the tree
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> ans;
        TreeNode* targetnode = findnode(root, start);
        if (!targetnode) return 0;
        burntree(root, targetnode, ans);
        if (ans.size() == 0) return 0;
        return ans.size() - 1;
    }
};