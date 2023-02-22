class Solution{
    public:
    void connect(Node *root)
    {
       queue<Node*>q;
       q.push(root);
       q.push(NULL);
       
       while(!q.empty())
       {
           Node* curr=q.front();
           q.pop();
           if(curr!=NULL)
           {
               curr->nextRight=q.front();
               if(curr->left)
               {
                   q.push(curr->left);
               }
               if(curr->right)
               {
                   q.push(curr->right);
               }
           }
           else
           {
               if(!q.empty())
               {
                    q.push(NULL);   
               }
           }
       }
       
       
    }    
};