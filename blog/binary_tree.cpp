#include <queue>
#include <vector>


using namespace std;

/*二叉树结构体定义*/
class TreeNode
{   
public:
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    int val;
    TreeNode *left;
    TreeNode *right;
};

/*AVL树定义*/
struct AVL
{
    int val;
    int height = 0;
    AVL *left;
    AVL *right;
    AVL() = default;
    AVL(int num) : val(num), left(nullptr), right(nullptr) {}
};

/*获取节点高度*/
int height(AVL *root)
{
    return root == nullptr ? -1 : root->height;
}

/*更新结点高度*/
void updateHeight(AVL *root)
{   
    //最高子树高度+1
    root->height = max(height(root->left), height(root->right)) + 1;
}

/*获取平衡因子*/
// 节点左树高度-节点右树高度
int balanceFactor(AVL *root)
{
    if (root == nullptr) return 0;

    return height(root->left) - height(root->right);
}


/*层序遍历*/
vector<int> levelOrder(TreeNode *root)
{
    queue<TreeNode*> que;
    que.push(root);

    vector<int> ans;

    while (!que.empty())
    {   
        TreeNode *node = que.front();
        ans.push_back(node->val);
        que.pop();

        if (node->left != nullptr)
            que.push(node->left);
        if (node->right != nullptr)
            que.push(node->right);
    }
    
    return ans;
}

/*前序遍历*/
void preOrder(TreeNode *root, vector<int> &vec)
{
    if (root == nullptr) return;
    vec.push_back(root->val);
    preOrder(root->left, vec);
    preOrder(root->right, vec);

}

/*中序遍历*/
void midOrder(TreeNode *root, vector<int> &vec)
{
    if (root == nullptr) return;
    midOrder(root->left, vec);
    vec.push_back(root->val);
    midOrder(root->right, vec);
}

/*后序遍历*/
void postOrder(TreeNode *root, vector<int> vec)
{
    if (root == nullptr) return;
    postOrder(root->left, vec);
    postOrder(root->right, vec);
    vec.push_back(root->val);
}

/*二叉搜索树查找节点*/
TreeNode* search(TreeNode *root, int num)
{
    TreeNode *cur = root;
    while (cur != nullptr)
    {
        if (cur->val > num)
            cur = cur->left;
        else if (cur->val < num)
            cur = cur->right;
        else
            break; 
    }
    return cur;
}

/*搜索二叉树 插入节点*/
TreeNode *insert(TreeNode *root, int num)
{
    if (root == nullptr) return nullptr;
    TreeNode *cur = root;
    TreeNode *pre = nullptr;

    while (cur != nullptr)
    {
        if (cur->val == num) return nullptr;
        pre = cur;
        if (cur->val < num)
            cur = cur->right;
        else
            cur = cur->left; 
    }

    TreeNode *node = new TreeNode(num);
    if (pre->val < num)
        pre->right = node;
    else
        pre->left = node;
    
    return node;
}


/*删除节点*/

TreeNode *getInOrderNext(TreeNode *root)
{
    if (root == nullptr) return nullptr;

    while (root->left != nullptr)
        root = root->left;
    return root;
}

TreeNode *remove(TreeNode *root, int num)
{   
    // 空树 返回null
    if (root == nullptr) return nullptr;
    
    TreeNode *cur = root;
    TreeNode *pre = nullptr;
    // 循环查找 该被删除的节点
    while (cur != nullptr)
    {
        if (cur->val == num)
            break;
        pre = cur;
        if (cur->val < num)
            cur = cur->right;
        else
            cur = cur->left;
    }
    
    // 没找到
    if (cur == nullptr) return nullptr;
    // 子节点数为0 / 1
    if (cur->left == nullptr || cur->right == nullptr)
    {
        TreeNode *child = (cur->left != nullptr) ? cur->left : cur->right;
        if (pre->left = cur)
            pre->left = child;
        else
            pre->right = child;
        delete cur;
    }
    else
    {
        TreeNode *nex = getInOrderNext(cur->right);
        int tem = nex->val;
        remove(root, nex->val);
        cur->val = tem;
    }

    return cur;
}

/*AVL树右旋*/
AVL *rightRotate(AVL *root)
{
    AVL *child = root->left;
    AVL *grandChild = child->right;

    child->right = root;
    root->left = grandChild;

    updateHeight(child);
    updateHeight(root);

    return child;
}

/*AVL树左旋*/
AVL *leftRotate(AVL *root)
{
    AVL *child = root->right;
    AVL *grandChild = child->left;

    child->left = root;
    root->right = grandChild;

    updateHeight(root);
    updateHeight(child);

    return child;
}

/*执行旋转 恢复平衡*/
AVL *rotata(AVL *node)
{   
    // 获取节点node的平衡因子
    int _balanceFactor = balanceFactor(node);
    // 左偏树
    if (_balanceFactor > 1)
    {
        // 右旋
        if (balanceFactor(node->left) >= 0)
            return rightRotate(node);
        else
            node->left = rightRotate(node->left);
            return leftRotate(node);  
    }
    
    if (_balanceFactor < -1)
    {
        if (balanceFactor(node->right) <= 0)
        {
            return leftRotate(node);
        }
        else
            node->right = leftRotate(node->right);
            return leftRotate(node);
    }

    // 平衡 无需选择
    return node;
}

/*AVL树递归插入节点的辅助方法*/
AVL *insertHelper(AVL *node, int val)
{
    if (node == nullptr) return new AVL(val);

    if (val < node->val)
        node->left = insertHelper(node->left, val);
    else if (val > node->val)
        node->right = insertHelper(node->right, val);
    else 
        return node;
    updateHeight(node);
    node = rotata(node);

    return node;
}

AVL *insert(AVL *root, int val)
{
    root = insertHelper(root, val);
    return root;
}

/*删除节点*/

AVL *getInOrderNext(AVL *root)
{
    if (root == nullptr) return nullptr;

    while (root->left != nullptr)
        root = root->left;
    return root;
}


AVL * removeHelper(AVL *root, int val)
{
    if (root == nullptr)
        return nullptr;

    if (val < root->val)
        root->left = removeHelper(root->left, val);
    else if (val > root->val)
        root->right = removeHelper(root->right, val);
    else
    {
        if (root->left == nullptr || root->right == nullptr)
        {
            AVL *child = root->left != nullptr ? root->left : root->right;
            if (child == nullptr) //没有子节点
            {
                delete root;
                return nullptr;
            }
            else  //1个子节点
            {
                delete root;
                return child;
            }
        }
        else
        {
            AVL *tem = getInOrderNext(root->right);
            int temVal = tem->val;
            root->right = removeHelper(root->right, tem->val);
            root->val = temVal;
        }
    }
    updateHeight(root);
    root = rotata(root);
    
    return root;
}

AVL *remove(AVL *root, int val)
{
    root = removeHelper(root, val);
    return root;
}

int main()
{
    /*初始化节点*/
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;


    /*节点插入与删除*/
    // 与链表类似， 通过修改指针实现

    TreeNode *p = new TreeNode(0);
    // 增加p
    n1->left = p;
    p->left = n2;
    // 删除p
    n1->left = n2;
    delete p;
    
}
