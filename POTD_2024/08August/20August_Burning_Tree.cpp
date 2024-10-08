class Solution {
  public:
   int ans(Node*ptr , int &target , int &maxtime)

    {
        if(ptr==NULL)
            return 0;
        int val_1=ans(ptr->left , target , maxtime);
        int val_2=ans(ptr->right , target , maxtime);
        if(ptr->data==target)
        {
            maxtime=max(maxtime , max( val_1 , val_2 ) );
            return -1;
        }
        else
        {
            if( val_1>=0 && val_2>=0)
                return max( val_1 , val_2 ) + 1;


            if( val_1>val_2)
                swap(  val_1 , val_2);


            maxtime=max( maxtime , val_2 - val_1 );
            return  val_1 - 1;
        }
    }
    int minTime(Node* root, int target) 
    {
        int maxtime=0;
        ans(root , target , maxtime);
        return maxtime;
    }
};