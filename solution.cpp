#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int left;
    int right;
    TreeNode() : left(-1), right(-1) {}
    TreeNode(int l, int r) : left(l), right(r) {}
};

class BinaryTree {
private:
    vector<TreeNode> nodes;
    int n;
    
    void swapAtDepth(int node, int currentDepth, int targetDepth) {
        if (node == -1) return;
        
        if (currentDepth % targetDepth == 0) {
            // Swap left and right children
            swap(nodes[node].left, nodes[node].right);
        }
        
        // Recursively process children
        swapAtDepth(nodes[node].left, currentDepth + 1, targetDepth);
        swapAtDepth(nodes[node].right, currentDepth + 1, targetDepth);
    }
    
    void inorderTraversal(int node, vector<int>& result) {
        if (node == -1) return;
        
        inorderTraversal(nodes[node].left, result);
        result.push_back(node);
        inorderTraversal(nodes[node].right, result);
    }
    
public:
    BinaryTree(int size) : n(size) {
        nodes.resize(n + 1); // 1-based indexing
    }
    
    void setChildren(int node, int left, int right) {
        nodes[node].left = left;
        nodes[node].right = right;
    }
    
    void performSwapOperation(int k) {
        swapAtDepth(1, 1, k); // Start from root at depth 1
    }
    
    vector<int> getInorderTraversal() {
        vector<int> result;
        inorderTraversal(1, result);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    BinaryTree tree(n);
    
    for (int i = 1; i <= n; i++) {
        int left, right;
        cin >> left >> right;
        tree.setChildren(i, left, right);
    }
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;
        
        tree.performSwapOperation(k);
        
        vector<int> inorder = tree.getInorderTraversal();
        
        for (int j = 0; j < inorder.size(); j++) {
            if (j > 0) cout << " ";
            cout << inorder[j];
        }
        cout << "\n";
    }
    
    return 0;
}