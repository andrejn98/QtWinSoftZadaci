#include<stdio.h>
#include<stdlib.h>
 
struct node {
    int key;
    struct node *left, *right;
};
 
struct node *newNode(int item) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
 
struct node* insert(struct node* node, int key) {
    if (node == NULL)
        return newNode(key);
 
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    return node;
}
 
/* ako binarnoto drvo ne e prazno da se najde
najmalata odnosno najlevata vrednost ili list */
struct node * minValueNode(struct node* node) {
    struct node* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
/* brishenje na vrednost */
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return root;
 
    // ako vrednost za brishenje e pomala od korenot 
    // da pobara rekurzivno na levo
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // ako vrednost za brishenje e pogolema od korenot 
    // da pobara rekurzivno na desno
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // ako vrednost za brishenje e ista so korenot 
    // togas taa vrednost da se izbrishe
    else {
        // ako korenot nema deca
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        
        // ako ima deca treba da se najde naredniot koren
        // so minValueNode, odnosno najmalata vrednost 
        // ili najleviot list na desnoto dete
        struct node* temp = minValueNode(root->right);
 
        // se smestuva vrednosta na najdenoto dete vo korenot
        root->key = temp->key;
 
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
 
int main() {

    struct node *root = NULL;
    int x,y;
    printf("Vnesete broj na teminja sose korenot:\n");
    scanf("%d", &x);

    for(int i=0;i<x;i++)
    {
        scanf("%d", &y);
        root = insert(root, y);
    }

    printf("Inorder izminuvanje na drvoto:\n");
    inorder(root);
    printf("\n");
    printf("Vnesete teme za brishenje:\n");
    scanf("%d", &x);

    root = deleteNode(root, x);
    printf("Inorder izminuvanje na drvoto po brishenjeto:\n");
    inorder(root);
 
    return 0;
}