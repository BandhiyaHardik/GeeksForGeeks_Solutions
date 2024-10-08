struct Node *insert(struct Node *head, int data) {

    Node *newNode=new Node(data);

    newNode->npx=head;

    if(head){
        head->npx=XOR(newNode,head->npx);
    }
    return newNode;
}

vector<int> getList(struct Node *head) {

    Node *curr=head,*prev=NULL,*next;
    vector<int>ans;
    while(curr){
        ans.push_back(curr->data);
        next=XOR(prev,curr->npx);
        prev=curr;
        curr=next;
    }
    return ans;
}