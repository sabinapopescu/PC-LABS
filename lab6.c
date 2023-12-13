#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define COUNT 10


struct node {
    int data;
    struct node* left;
    struct node* right;
	int key;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct node* insertNode(struct node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void printSpaces(int count) {
    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

void printTree(struct node* root, int space) {
    if (root == NULL) return;
    space += 10;
    printTree(root->right, space);
    printf("\n");
    printSpaces(space);
    printf("%d\n", root->data);
    printTree(root->left, space);
}

void printBinaryTree(struct node* root) {
    printTree(root, 0);
}

void print2DUtil(struct node* root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    print2DUtil(root->left, space);
}


void print2D(struct node* root)
{
    print2DUtil(root, 0);
}


int maxDepth(struct node* node) {
    if (node == NULL)
        return 0;
    else {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
unsigned int getLeafCount(struct node* node)
{
  if(node == NULL)       
    return 0;
  if(node->left == NULL && node->right==NULL)      
    return 1;            
  else
    return getLeafCount(node->left)+
           getLeafCount(node->right);      
}
struct node* findLCA(struct node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    struct node* left_lca = findLCA(root->left, n1, n2);
    struct node* right_lca = findLCA(root->right, n1, n2);
    if (left_lca && right_lca)
        return root;
    return (left_lca != NULL) ? left_lca : right_lca;
}
struct node* findMin(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
         if (root->left == NULL) {
           struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
         }
         struct node* temp = findMin(root->right);

        // copy the in-order successor's content to this node
        root->data = temp->data;

        // delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
bool isBalanced(struct node* root) {
    if (root == NULL)
        return true; // A null tree is balanced

    int lDepth = maxDepth(root->left);
    int rDepth = maxDepth(root->right);

    if (abs(lDepth - rDepth) <= 1 &&
        isBalanced(root->left) &&
        isBalanced(root->right))
        return true;

    return false; // If we reach here, the tree is not balanced
}
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
int main() {
    struct node* root = NULL;
    int data;
    int lca1, lca2;
    int keyToDelete;
    printf("Enter integers to insert into the binary tree (non-integer to stop):\n");
    while(scanf("%d", &data) == 1) {
        root = insertNode(root, data);
        printBinaryTree(root);
    }
     clearInputBuffer();
printf("Enter the values you want to find the LCA to: ");
scanf("\n%d", &lca1);
 clearInputBuffer();
scanf("%d", &lca2);
struct node* lca = findLCA(root, lca1, lca2);
if (lca != NULL)
    printf("LCA(%d, %d) = %d\n", lca1, lca2, lca->data);
else
    printf("LCA(%d, %d) not found\n", lca1, lca2);
    
    printf("Height of tree is %d\n", maxDepth(root));
	printf("Number of leafs is %d\n", getLeafCount(root));
	if (isBalanced(root))
        printf("Tree is balanced\n");
    else
        printf("Tree is not balanced\n");
         clearInputBuffer();
printf("Enter the key to delete: ");
scanf("\n%d", &keyToDelete);
root = deleteNode(root, keyToDelete);

printf("\nAfter deleting node with key %d:\n", keyToDelete);
print2D(root);

getchar();
return 0;
}

