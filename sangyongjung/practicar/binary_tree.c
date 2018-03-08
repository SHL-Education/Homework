#include <stdio.h>
#include <malloc.h>

#define EMPTY 0

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}tree;
  
tree *get_node()
{
    tree *tmp;
    tmp = (tree *)malloc(sizeof(tree));
    tmp -> left = EMPTY;
    tmp -> right = EMPTY;
    return tmp;
}

void tree_ins(tree **root, int data)
{
    if(*root == NULL)
    {
         *root = get_node();
         (*root) -> data = data;
         return ;
    }
    else if(data < (*root) -> data)
    tree_ins(&(*root) -> left, data);
    else if(data > (*root) -> data)
    tree_ins(&(*root) -> right, data);
}

int print_tree(tree *root)
{
    if(root)
    {
        printf("%d\n", root -> data);
        print_tree(root -> left);
        print_tree(root -> right);
    }
    return 0;
}

tree *chg_node(tree *root)
{
    tree *tmp;
    tmp = root;
    if(!root -> left)
      root = root -> right;
    if(!root -> right)
      root = root -> left;
    
    free(tmp);
 
    return root;
}

tree *find_max(tree *root, int *data)
{
    if(root -> right)
     root -> right = find_max(root -> right, data);
     
    else
    {
      *data = root -> data;
      root = chg_node(root);
    }
    return root;
}


tree *detree(tree *root, int data)
{
    int num;
    if(root == NULL)
    {
         printf("Not Found!\n");
         return NULL;
    }
    else if(data < root -> data) 
     root -> left = detree(root -> left, data);
    else if(data > root -> data)
     root -> right = detree(root -> right, data);
    else if(root -> left && root -> right)
    {
       root -> left = find_max(root -> left, &num);   
       root -> data = num;
    }
    else
      root = chg_node(root); 
      
    return root;
}

int main(void)
{
    tree *root = EMPTY;
    int i;
    int arr[13] = {50, 45, 73, 32, 48, 46, 16, 37, 120, 47, 130, 127, 124};
    for(i = 0; i < 13 ; i++)
    {
         tree_ins(&root, arr[i]);
    }
    print_tree(root);
    
    root = detree(root, 50);
  
    print_tree(root);
    return 0;
}
