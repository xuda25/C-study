#������
   �������� Binary Tree����һ�ַ��������ݽṹ����������������֮���������ϵ�������š�һ��Ϊ�����ķ����߼�������������������Ҳ���Խ��Ϊ��λ�洢�ģ���������ֵ����������ָ�롹�� 

``` C++
/*�������ṹ�嶨��*/
class TreeNode
{   
public:
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    int val;
    TreeNode *left;
    TreeNode *right;
};
```
![](2023-03-20-21-38-47.png)
��������ָ��ֱ�ָ�����ӽ�� Left Child Node���͡����ӽ�� Right Child Node�������ҳƸý��Ϊ�����ӽ��ġ������ Parent Node��������������ĳ��㣬�����ӽ�����µ�����Ϊ�ý��ġ������� Left Subtree����������ͬ��

����Ҷ����⣬ÿ����㶼���ӽ������������磬������ͼ�ġ���� 2����������㣬��ô�����ӽ������ӽ��ֱ�Ϊ����� 4���͡���� 5�������������������ֱ�Ϊ����� 4 �������½���γɵ������͡���� 5 �������½���γɵ�������

## ��������������



## ��������������

``` C++
/*��ʼ���ڵ�*/
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;


    /*�ڵ������ɾ��*/
    // ���������ƣ� ͨ���޸�ָ��ʵ��

    TreeNode *p = new TreeNode(0);
    // ����p
    n1->left = p;
    p->left = n2;
    // ɾ��p
    n1->left = n2;
    delete p;
```

## ��������������

- ����������(��������)�����нڵ㱻����
- ��ȫ��������ֻ����ײ�û�������ҿ���ʼ��
- ����������������Ҷ�ӽڵ㣬�����ڵ��������ӽڵ�
- ƽ�������������ڵ���������߶Ȳ�<=1
  
## ���������˻�
- ������������ȫ���ӳ��˶����������Ρ�������
- ������һ�����ˣ���Ϊ���ԣ��������O(n)

![](2023-03-21-13-35-02.png)

## ���鴢�������
�ڵ�����:i
���ӽڵ�����:2i + 1
���ӽڵ�����:2i + 2

������������������ʽ�ڴ������ж������� �������������ʾ��λ



# ����������
������Ҳ��ͨ��ָ������ڵ㣬 ������һ�ַ��������ݽṹ�� �����������Ӹ���

�����㷨: ��������� ǰ������� ��������� �������

## �������
�Զ����� һ������ ÿ���������

    ������ �����������

``` C++
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

```
    ʱ�临�Ӷ�O(n)
    �ռ临�Ӷ�O(n)

## ǰ�����򡢺�������
    �����ֱ�����ʽ  **������ȱ���**�� �������ߵ�ͷ �ڻ�ͷ����

    ��������ͼ��� ̫ţ��

![](2023-03-21-14-10-12.png)

![](2023-03-21-14-12-01.png)

``` C++
/*ǰ�����*/
void preOrder(TreeNode *root, vector<int> &vec)
{
    if (root == nullptr) return;
    vec.push_back(root->val);
    preOrder(root->left, vec);
    preOrder(root->right, vec);

}

/*�������*/
void midOrder(TreeNode *root, vector<int> &vec)
{
    if (root == nullptr) return;
    midOrder(root->left, vec);
    vec.push_back(root->val);
    midOrder(root->right, vec);
}

/*�������*/
void postOrder(TreeNode *root, vector<int> vec)
{
    if (root == nullptr) return;
    postOrder(root->left, vec);
    postOrder(root->right, vec);
    vec.push_back(root->val);
}
```
ʱ�临�Ӷ�O(n)

# ����������

1. ���ڸ��ڵ㣬 �����������нڵ��ֵ<���ڵ�ֵ<�����������нڵ��ֵ
2. ����ڵ����������������Ҳ�Ƕ���������������������1

![](2023-03-21-14-34-59.png)

## �����������Ĳ���

1. ���ҽڵ�


    ����Ŀ��ֵ�� ����һ��cur�ڵ㣬 ��root����
- cur->val > num ˵���������� cur = cur->left;
- cur->val < num ˵���������� cur = cur->right;
- cur->val == num �ҵ�Ŀ��ֵ ����

    ������������ֲ���һ���� ÿ���ų�һ�룬 ѭ���������Ϊ�������ĸ߶ȣ� ʱ�临�Ӷ�O(logn)

``` C++
/*�������������ҽڵ�*/
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
```

## ��������������Ԫ��
1. ���ҵ�Ӧ�ò����λ��
2. ����
    ��Ϊ������<�ڵ�<�������� ���� ��������ȵ�ֵ �������ֱ�ӷ���

```C++
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

```

## ɾ���ڵ�
�����ֿ�����
1. ��ɾ���ڵ�û���ӽڵ�  ֱ��ɾ������
2. ��ɾ�������һ���ӽڵ㣬 preָ���ӽڵ㼴��
3.  ��ɾ���ڵ��������ӽڵ㣬 ���������ɾ���ڵ������� ����һ���ڵ��滻��ɾ���ڵ㼴��

```C++
/*ɾ���ڵ�*/

TreeNode *getInOrderNext(TreeNode *root)
{
    if (root == nullptr) return nullptr;

    while (root->left != nullptr)
        root = root->left;
    return root;
}

TreeNode *remove(TreeNode *root, int num)
{   
    // ���� ����null
    if (root == nullptr) return nullptr;
    
    TreeNode *cur = root;
    TreeNode *pre = nullptr;
    // ѭ������ �ñ�ɾ���Ľڵ�
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
    
    // û�ҵ�
    if (cur == nullptr) return nullptr;
    // �ӽڵ���Ϊ0 / 1
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
```

    ���Ͽ�֪�� �������������� �������������������

## ������������Ч��

![](2023-03-22-13-38-30.png)

## ����������Ӧ����ƽ���

������ܱ�Ϊ����  ����ӶȻ��˻�

## ������������Ӧ��
- ϵͳ�еĶ༶��������Ч���ҡ����롢ɾ��������
- ���������㷨�ĵײ����ݽṹ��
- �洢��������������������


# AVL��(ƽ�����������)
    Ƶ����ɾ��ĵ�ʹ�ó����У�AVL ����ʼ�ձ��ֺܸߵ�������ɾ���Ч�ʣ����кܺõ�Ӧ�ü�ֵ(���˻�)

``` C++
/*AVL������*/
struct AVL
{
    int val;
    int height = 0; // �ڵ�߶�
    AVL *left;
    AVL *right;
    AVL() = default;
    AVL(int num) : val(num), left(nullptr), right(nullptr) {}
};
```
    �ڵ�߶�����ԶҶ�ڵ㵽�ýڵ�ľ��룬 ���߹��ı������� **Ҷ�ڵ�ĸ߶�Ϊ0** **�սڵ�ĸ߶�Ϊ-1**

``` C++
/*��ȡ�ڵ�߶�*/
int height(AVL *root)
{
    return root == nullptr ? -1 : root->height;
}

/*���½��߶�*/
void updateHeight(AVL *root)
{   
    //��������߶�+1
    root->height = max(height(root->left), height(root->right)) + 1;
}

/*��ȡƽ������*/
// �ڵ������߶�-�ڵ������߶�
int balanceFactor(AVL *root)
{
    if (root == nullptr) return 0;

    return height(root->left) - height(root->right);
}
```
    ����һ��AVL����ƽ�����ӵľ���ֵ<= 1(ƽ�������)

## AVL����ת
    �ڲ�Ӱ����Ϊ����������ǰ���� ��֤��Ϊƽ�������

    ʧ��ڵ㣺ƽ�����Ӿ���ֵ>1�Ľڵ�
    ��ת��������������������������������������������

1. ����
``` C++
/*AVL������*/
AVL *rightRotate(AVL *root)
{
    AVL *child = root->left;
    AVL *grandChild = child->right;

    child->right = root;
    root->left = grandChild;

    updateHeight(grandChild);
    updateHeight(child);
    updateHeight(root);

    return child;
}
```
2. ����
```C++
/*AVL������*/
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
```

    ���������͡������������Ǿ���ԳƵģ����߶�Ӧ���������ʧ�����Ҳ�ǶԳƵġ����ݶԳ��ԣ����ǿ��Ժܷ���شӡ��������Ƶ�����������������أ�ֻ�轫�������������еİ����е� left �滻Ϊ right �����е� right �滻Ϊ left �����ɵõ������������롣

3. ������������


4. ������������

## ��ת��ѡ��
![](2023-03-22-14-33-28.png)

![](2023-03-22-14-34-03.png)

```C++
/*ִ����ת �ָ�ƽ��*/
AVL *rotata(AVL *node)
{   
    // ��ȡ�ڵ�node��ƽ������
    int _balanceFactor = balanceFactor(node);
    // ��ƫ��
    if (_balanceFactor > 1)
    {
        // ����
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

    // ƽ�� ����ѡ��
    return node;
}
```