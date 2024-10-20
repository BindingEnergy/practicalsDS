#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node *createNode(int data) {
    Node *pnode = (Node *)malloc(sizeof(Node));
    if (pnode == NULL) {
        printf("\nCannot create Node !");
        return NULL;
    }
    pnode->data = data;
    pnode->next = NULL;
    return pnode;
}

void insertAtBeg(int data) {
    Node *pnode = createNode(data);
    if (pnode == NULL) {
        printf("\nCannot create Node! Memory OVERFLOW!");
        return;
    }
    if (head == NULL) {
        head = pnode;
        pnode->next = head;
    } else {
        Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        pnode->next = head;
        current->next = pnode;
        head = pnode;
    }
    printf("\nInserted Node: %d", pnode->data);
}

void insertAtEnd(int data) {
    Node *pnode = createNode(data);
    if (pnode == NULL) {
        printf("\nCannot create Node! Memory OVERFLOW!");
        return;
    }
    if (head == NULL) {
        head = pnode;
        pnode->next = head;
    } else {
        Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = pnode;
        pnode->next = head;
    }
    printf("\nInserted Node: %d", pnode->data);
}

void forwardTraversal() {
    Node *current;
    if (head == NULL) {
        printf("\nList is EMPTY!");
        return;
    }
    current = head;
    printf("\nList is: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}

void createList() {
    printf("\nEnter number of Nodes to create: ");
    int n;
    scanf("%d", &n);
    int data;
    for (int i = 1; i <= n; i++) {
        printf("\nEnter data for Node %d: ", i);
        scanf("%d", &data);
        if (head == NULL) {
            insertAtBeg(data);
        } else {
            insertAtEnd(data);
        }
    }
}

void deleteAtBeg() {
    if (head == NULL) {
        printf("\nList is Empty!");
        return;
    }
    Node *deleted = head;
    if (head->next == head) {
        head = NULL;
    } else {
        Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        head = head->next;
        current->next = head;
    }
    printf("\nDeleted Node: %d", deleted->data);
    free(deleted);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("\nList is Empty!");
        return;
    }
    Node *current, *follow;
    if (head->next == head) {
        current = head;
        head = NULL;
    } else {
        current = head;
        follow = NULL;
        while (current->next != head) {
            follow = current;
            current = current->next;
        }
        follow->next = head;
    }
    printf("\nDeleted Node: %d", current->data);
    free(current);
}

void countNodes() {
    if (head == NULL) {
        printf("\nList is Empty!");
        return;
    }
    int count = 1; 
    Node *current = head;
    while (current->next != head) {
        current = current->next;
        count++;
    }
    printf("\nTotal nodes in list: %d", count);
}

int main() {
    while (1) {
        printf("\n1. Create List\n2. Insert at Beginning\n3. Insert At End\n4. Forward Traversal");
        printf("\n5. Delete Beginning\n6. Delete End\n7. Total Nodes");
        printf("\nEnter choice: ");
        int choice;
        scanf("%d", &choice);
        int data;
        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                printf("\nEnter data: ");
                scanf("%d", &data);
                insertAtBeg(data);
                break;
            case 3:
                printf("\nEnter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                forwardTraversal();
                break;
            case 5:
                deleteAtBeg();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                countNodes();
                break;
            default:
                exit(0);
        }
    }
}