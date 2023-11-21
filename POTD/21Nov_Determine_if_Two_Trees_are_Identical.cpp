class Solution
{
    public:
    bool isSame(Node * r1, Node * r2){
        if((r1 == nullptr) ^ (r2 == nullptr))
            return 0;
        
        return (r1 == nullptr) or (r1 -> data == r2 -> data);
    }
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        bool ok = isSame(r1, r2);
        
        if(r1){
            ok = ok and isIdentical(r1 -> left, r2 -> left) and isIdentical(r1 -> right, r2 -> right);
        }
        
        return ok;
    }
};