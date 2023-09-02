class Solution
{
    vector<int> al;
public:
    int getCount(Node *node, int bud)
    {
        int cnt = 0;
        al.clear();
        vis_leaf(node, 0);
       sort(al.begin(), al.end());

        for (int i = 0; i < al.size(); i++)
        {
            if (bud - al[i] >= 0)
            {
                cnt++;
                bud -= al[i];
            }
            else
            {
                return cnt;
            }
        }

        return cnt;
    }

    void vis_leaf(Node* node, int level)
    {
        if (node == nullptr)
            return;

        level++;

        if (node->left == nullptr && node->right == nullptr)
        {
            al.push_back(level);
            return;
        }

        vis_leaf(node->left, level);
        vis_leaf(node->right, level);
    }
};