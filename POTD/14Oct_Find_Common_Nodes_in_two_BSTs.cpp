class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
     vector<int> result;
        stack<Node*> stack1;
        stack<Node*> stack2;

        while (true) {
            if (root1 != nullptr) {
                stack1.push(root1);
                root1 = root1->left;
            }
            else if (root2 != nullptr) {
                stack2.push(root2);
                root2 = root2->left;
            }
            else if (!stack1.empty() && !stack2.empty()) {
                root1 = stack1.top();
                root2 = stack2.top();

                if (root1->data == root2->data) {
                    result.push_back(root1->data);
                    stack1.pop();
                    stack2.pop();
                    root1 = root1->right;
                    root2 = root2->right;
                }
                else if (root1->data < root2->data) {
                    stack1.pop();
                    root1 = root1->right;
                    root2 = nullptr;
                }
                else if (root1->data > root2->data) {
                    stack2.pop();
                    root2 = root2->right;
                    root1 = nullptr;
                }
            }
            else {
                break;
            }
        }
        return result;
    }
};