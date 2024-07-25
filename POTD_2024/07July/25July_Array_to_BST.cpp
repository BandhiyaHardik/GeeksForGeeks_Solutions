class Solution {
  public:
    Node* abc(vector<int>& nums,int left,int right){
        if(left>right){
            return NULL;
        }
        int mid= left + (right-left)/2;
        Node* node =new Node(nums[mid]);
        node->left=abc(nums,left,mid-1);
        node->right=abc(nums,mid+1,right);
    }
    
    Node* sortedArrayToBST(vector<int>& nums) {

        Node* root=abc(nums,0,nums.size()-1);
        return root;
    }
};