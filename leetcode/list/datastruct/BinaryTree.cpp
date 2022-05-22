# include <iostream>
# include <string>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

void CreatBiTree(TreeNode** treenode, char *c)       // 前序遍历法创建二叉树
{
    char ch;
    ch = *c;
    if(ch == '#')
    {
        treenode = nullptr;
        c = c+1;
    }
    else
    {
        TreeNode * node = new TreeNode();
        (*treenode) = node;
        (*treenode)->val = ch;
        c = c+1;
        CreatBiTree(&(*treenode)->left, c);
        CreatBiTree(&(*treenode)->right, c);
    }
}

int main()
{
    TreeNode* T = new TreeNode();
    char s[] = {'A', 'B', '#', 'D', '#', '#', 'C', '#', '#', '\0'};
    CreatBiTree(&T, s);

    return 0;
}
