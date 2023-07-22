class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        unordered_set<int> hs;
        Node* curr = head;
        Node* prev = nullptr;
        
        while (curr != nullptr)
        {
            int val = curr->data;
            if (hs.find(val) != hs.end())
            {
                prev->next = curr->next;
                delete curr;
            }
            else
            {
                hs.insert(val);
                prev = curr;
            }
            
            curr = prev->next;
        }
        
        return head;
    }
};
