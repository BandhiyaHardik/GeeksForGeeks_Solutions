class Solution
{
    public:
        Node* insert(Node* root, int x) {
        
             Node* temp = new Node(x);
        Node* parent = nullptr;
        Node* curr = root;
        while (curr != nullptr) {
            parent = curr;
            if (curr->data > x)
                curr = curr->left;
            else if (curr->data < x)
                curr = curr->right;
            else  
                return root;
        }

        if (parent == nullptr) 
            return temp;
        if (parent->data > x)
            parent->left = temp;
        else
            parent->right = temp;
        return root;
    }

};
