#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//void deleteNode(struct Node* &root, int key);

// Data structure to store a BST node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// Function to create a new binary tree node having a given key
struct Node* newNode(int key)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = key;
    node->left = node->right = NULL;
 
    return node;
}
 
// Function to perform inorder traversal on the tree
void inorder(struct Node* root)
{
    if (root == NULL) {
        return;
    }
 
    inorder(root->left);
    printf("\n %d \n",root->data);
    inorder(root->right);
}
 
// Recursive function to insert a key into a BST
struct Node* insert(struct Node *root, int key)
{
    // if the root is null, create a new node and return it
    if (root == NULL) {
        return newNode(key);
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }
 
    return root;
}

// HELPER FUNCTION FOR DELETE
int inOrderSuccessor(struct Node* root) {
    int minimum = root->data;
    while (root->left != NULL) 
    {
        minimum = root->left->data;
        root = root->left;
    }
    return minimum;
}


// DELETE
struct Node* deleteRecursively(struct Node* root, int value) {

    if (root == NULL)
        return root;

    if (value < (int) root->data) {
        root->left = deleteRecursively(root->left, value);
    } else if (value > root->data) {
        root->right = deleteRecursively(root->right, value);
    } else {

        if (root->left == NULL) 
        {
            return root->right;
        } 
        else if (root->right == NULL)
            return root->left;

        root->data = inOrderSuccessor(root->right);
        root->right = deleteRecursively(root->right, root->data);
    }

    return root;

}


// SEARCH 
int searchRecursively(struct Node* root, int value) 
{
    if (root == NULL)
        return 0;


    if (root->data == value)
        return 1;

    if (value < root->data)
        return searchRecursively(root->left, value);

    else if (value > root->data)
        return searchRecursively(root->right, value);


    return 0;
    
}

// Function to get the count of full Nodes in
// a binary tree
int getfullCount(struct Node *Tree)
{
    static int cnt=0;
    struct Node *temp=Tree;
    if(temp!=NULL)
     {
       cnt++;
       getfullCount(temp->left);
       getfullCount(temp->right);
     }
    return cnt;
}

int getLeafCount(struct Node* Tree)
{
    static int pt;
    if(Tree == NULL)
        return 0;
    if(Tree->left == NULL && Tree->right==NULL)
        return 1;
    else
        pt= getLeafCount(Tree->left)+getLeafCount(Tree->right);
     return pt;
}

int maxDepth(struct Node* Tree)
{
    if (Tree == NULL)
        return 0;
    else 
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(Tree->left);
        int rDepth = maxDepth(Tree->right);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}



int main()
{
    struct Node* root = NULL;
    
    int item;
    int choice;
    int searchKeyValue;
    do
	{
        //clrscr();
        printf("\n\n **** BST using RECURSION ****\n");
        printf("\n 1. Insert\n 2. Display (Inorder) \n 3. Delete\n 4. Search \n 5. Count All Nodes ");
        printf("\n 6. Count Leaf Nodes \n 7. Max Depth  \n 8. Exit");
        printf("\n\n Enter ur choice : ");
        scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\n Enter any element : ");
				scanf("%d",&item);
				// printf(" Enter percentage : ");
				// scanf("%f",&perc);
				root = insert(root, item);
				break;

			case 2:
				inorder(root);
				getch();
				break;

			case 3:
				printf("\n Which element do you want to delete : ");
				scanf("%d",&item);
				deleteRecursively(root,item);
                inorder(root);
				getch();
				break;

			case 4:
                printf("\n Enter the element to search : ");
                scanf("%d",&item);
				searchKeyValue = searchRecursively(root,item);
				if(searchKeyValue == 1)
                    printf("\n Node exists");
                else
                    printf("\n Node does not exist");
                getch();
				break;

			case 5:
				printf("\n Number of nodes : %d \n",getfullCount(root));
				getch();
				break;

            case 6:
                printf("\n Number of leaf nodes : %d \n",getLeafCount(root));
                getch();
                break;

            case 7: 
                printf("\n Maximum depth : %d \n",maxDepth(root));
                getch();
                break;

			case 8:
				exit(0);
				break;

			default :
				printf("\n\n Invalid choice... \n");
		}
	}while(choice!=8);
 
    return 0;
}
