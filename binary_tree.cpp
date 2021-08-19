#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};


struct Node* newNode(int value)
{
    Node* n = new Node;
    n->key = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Node* insertValue(struct Node* root, int value,
                         queue<Node *>& q)
{
    Node* node = newNode(value);
    if (root == NULL)
        root = node;


    else if (q.front()->left == NULL)
        q.front()->left = node;

    else {
        q.front()->right = node;
        q.pop();
    }


    q.push(node);
    return root;
}


Node* createTree(int arr[], int n)
{
    Node* root = NULL;
    queue<Node*> q;
    for (int i = 0; i < n; i++)
      root = insertValue(root, arr[i], q);
    return root;
}


void levelOrder(struct Node* root)
{
    if (root == NULL)
        return;
    queue<Node*> n;
    n.push(root);
    while (!n.empty()) {
        cout << n.front()->key << " ";
        if (n.front()->left != NULL)
            n.push(n.front()->left);
        if (n.front()->right != NULL)
            n.push(n.front()->right);
        n.pop();
    }
}



void pre_order(struct Node *node)
{
    printf("%d ",node->key);

    if(node->left!=NULL)
    {
        pre_order(node->left);
    }
    if(node->right!=NULL)
    {
        pre_order(node->right);
    }
}

void post_order(struct Node *node)
{

    if(node->left!=NULL)
    {
        post_order(node->left);
    }
    if(node->right!=NULL)
    {
        post_order(node->right);
    }
    printf("%d ",node->key);
}

void in_order(struct Node *node)
{

    if(node->left!=NULL)
    {
        in_order(node->left);
    }

    printf("%d ",node->key);

    if(node->right!=NULL)
    {
        in_order(node->right);
    }

}

int main()
{
    int arr[] = { 10, 20, 30, 40, 50, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = createTree(arr, n);

    printf("Normal:\n");
    levelOrder(root);
    printf("\n");

    printf("pre_order:\n");
    pre_order(root);
    printf("\n");

    printf("post_order:\n");
    post_order(root);
    printf("\n");

    printf("in_order:\n");
    in_order(root);
    printf("\n");
    return 0;
}
