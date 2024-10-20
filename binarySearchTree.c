#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *root = NULL;

Node* createNode(int data) {
    Node *pnode = (Node*)malloc(sizeof(Node));
    if (pnode == NULL) {
        printf("\nMemory Overflow !");
        return NULL;
    }
    pnode->data = data;
    pnode->left = pnode->right = NULL;
    return pnode;
}

void insert(int data) {
    Node *pnode = createNode(data);
    if (pnode == NULL) {
        return;
    }
    if (root == NULL) {
        root = pnode;
    } else {
        Node *current = root;
        Node *follow = NULL;
        while (current != NULL) {
            follow = current;
            if (current->data > pnode->data)
                current = current->left;
            else
                current = current->right;
        }
        if (follow->data > pnode->data)
            follow->left = pnode;
        else
            follow->right = pnode;
    }
    printf("\nInserted Node: %d", pnode->data);
}

void create() {
    printf("\nEnter number of nodes to create: ");
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("\nEnter data: ");
        int data;
        scanf("%d", &data);
        insert(data);
    }
}

void search(int node) {
    if (root == NULL) {
        printf("\nTree is Empty !");
        return;
    }
    int data;
    printf("\nEnter node to search: ");
    scanf("%d", &data);
    Node *current = root;
    while (current != NULL && current->data != data) {
        if (current->data > data)
            current = current->left;
        else
            current = current->right;
    }
    if (current == NULL) {
        printf("\nNode not found !");
    } else {
        printf("%d Found in the tree !", data);
    }
}

void preorder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void totalNodes(Node *root, int *count) {
    if (root != NULL) {
        (*count)++;
        totalNodes(root->left, count);
        totalNodes(root->right, count);
    }
}

int leafNodes(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return leafNodes(root->left) + leafNodes(root->right);
}

int internalNodes(Node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
        return 0;
    else
        return 1 + internalNodes(root->left) + internalNodes(root->right);
}

void deleteNode() {
    if (root == NULL) {
        printf("\nTree is Empty !");
        return;
    }
    int data;
    printf("\nEnter node to delete: ");
    scanf("%d", &data);
    Node *current = root;
    Node *follow = NULL;
    while (current != NULL && current->data != data) {
        follow = current;
        if (current->data > data)
            current = current->left;
        else
            current = current->right;
    }
    if (current == NULL) {
        printf("\nNODE NOT FOUND !");
        return;
    }
    if (current->left == NULL && current->right == NULL) {
        if (current == root) {
            root = NULL;
        } else if (follow->left == current) {
            follow->left = NULL;
        } else {
            follow->right = NULL;
        }
    } else if (current->left == NULL) {
        if (current == root) {
            root = root->right;
        } else if (follow->left == current) {
            follow->left = current->right;
        } else {
            follow->right = current->right;
        }
    } else if (current->right == NULL) {
        if (current == root) {
            root = root->left;
        } else if (follow->left == current) {
            follow->left = current->left;
        } else {
            follow->right = current->left;
        }
    } else {
        Node *c = current->right;
        Node *f = current;
        while (c->left != NULL) {
            f = c;
            c = c->left;
        }
        if (f != current) {
            f->left = c->right;
        } else {
            f->right = c->right;
        }
        current->data = c->data;
        current = c;
    }
    printf("Deleted Node is: %d", current->data);
    free(current);
}

int height(Node *root) {
    if (root == NULL) {
        return -1;
    }
    int lheight = height(root->left);
    int rheight = height(root->right);
    if (lheight > rheight)
        return lheight + 1;
    else
        return rheight + 1;
}

int main() {
    int choice, data, count;
    while (1) {
        printf("\n\n--- Binary Search Tree Menu ---\n");
        printf("1. Create Tree\n");
        printf("2. Insert Node\n");
        printf("3. Search Node\n");
        printf("4. Preorder Traversal\n");
        printf("5. Inorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Total Nodes\n");
        printf("8. Leaf Nodes\n");
        printf("9. Internal Nodes\n");
        printf("10. Delete Node\n");
        printf("11. Height of Tree\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 3:
                search(data);
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                count = 0;
                totalNodes(root, &count);
                printf("Total Nodes: %d\n", count);
                break;
            case 8:
                printf("Leaf Nodes: %d\n", leafNodes(root));
                break;
            case 9:
                printf("Internal Nodes: %d\n", internalNodes(root));
                break;
            case 10:
                deleteNode();
                break;
            case 11:
                printf("Height of Tree: %d\n", height(root));
                break;
            case 12:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}