#include <queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


 //bfs
 #include <vector>
 using namespace std;


//level wise bfs on a binary tree, use the queue to track left to right
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        queue<TreeNode*> queue;
        vector<int> result;

        //add the root to the queue
        queue.push(root);

        while(!queue.empty()){
            TreeNode* rightmost = nullptr;
            auto length = queue.size(); //how many to pop

            for(size_t i{0}; i<length; ++i){
                auto node = queue.front(); queue.pop();
                if(node){
                    rightmost = node;
                    queue.push(node->left); //left then right
                    queue.push(node->right);
                }
            }
            //make sure right side isnt null when pushing

            if(rightmost) result.push_back(rightmost->val); //handles the root case as well
        }
        return result;

    }
};
