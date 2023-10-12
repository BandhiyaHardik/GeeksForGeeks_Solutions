class Solution {
     string mark = "$";
    unordered_set<string> subtree;
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
        string str = dup(root);

        if (str == "#")
            return 1;
        else
            return 0;
    }

    string dup(Node* root) {
        string s = "";
        if (root == nullptr)
            return s + mark; 

        string lstr = dup(root->left);
        if (lstr == "#") 
            return "#";

        string rstr = dup(root->right);
        if (rstr == "#") 
            return "#";

        s = s + to_string(root->data) + lstr + rstr;
        if (s.length() > 3 && subtree.find(s) != subtree.end()) 
            return "#";

        subtree.insert(s);
        return s;
    }
};