#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *head = NULL;

Node *createNode(int data){
    Node *pnode = (Node *)malloc(sizeof(Node));
    if(pnode == NULL){
        printf("\nCannot create Node !");
    }
    pnode->data = data;
    pnode->next = NULL;
    return pnode;
}

void insertAtBeg(int data){
    Node *pnode = createNode(data);
    if(pnode == NULL){
        printf("\ncannot create Node !Memory OVERFLOW !");
        free(pnode);
        return;
    }
    if(head == NULL){
        head = pnode;
    }else{
        pnode->next = head;
        head = pnode;
    }
    printf("\nInserted Node: %d",pnode->data);
}

void insertAtEnd(int data){
    Node *pnode = createNode(data);
    if(pnode == NULL){
        printf("\ncannot create Node !Memory OVERFLOW !");
        free(pnode);
        return;
    }
    if(head == NULL){
        head = pnode;
    }else{
        Node *current;
        current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = pnode;
    }
    printf("\nInserted Node: %d",pnode->data);
}

void insertBefore(int data,int node){
    Node *pnode = createNode(data);
    if(pnode == NULL){
        printf("\ncannot create Node !Memory OVERFLOW !");
        free(pnode);
        return;
    }
    if(head == NULL){
        printf("\nList is empty !");
        return;
    }
    Node *current,*follow;
    current = head;
    follow=NULL;
    while(current != NULL && current->data != node){
        follow = current;
        current = current->next;
    }
    if(current == NULL){
        printf("\nNode entered does not exist !");
        return;
    }
    if(current == head){
        pnode->next = head;
        head = pnode;
    }else{
        pnode->next = current;
        follow->next = pnode;
    }
    printf("\nInserted Node: %d",pnode->data);
}

void forwardTraversal() {
    Node *current;
    if (head == NULL) {
        printf("\nList is EMPTY!");
        return;
    }
    current = head;
    printf("\nList is: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n"); 
}

void createList(){
    printf("\nEnter number of Nodes to create: ");
    int n;
    scanf("%d",&n);
    int data;
    for(int i = 1 ; i <= n ; i++){
        printf("\nEnter data for Node %d: ",i);
        scanf("%d",&data);
        if(head == NULL){
            insertAtBeg(data);
        }else{
            insertAtEnd(data);
        }
    }
}


void deleteAtBeg(){
    if(head == NULL){
        printf("\nList is Empty !");
        return;
    }
    Node *current;
    current = head;
    head = head->next;
    printf("\nDeleted Node: %d",current->data);
    free(current);
}

void deleteAtEnd(){
    if(head == NULL){
        printf("\nList is Empty !");
        return;
    }
    Node *current, *follow;
    current = head;
    follow =NULL;
    while(current->next != NULL){
        follow = current;
        current = current->next;
    }
    follow->next = NULL;
    printf("\nDeleted Node: %d",current->data);
    free(current);
}

void deleteBefore(int node){
    if(head == NULL){
        printf("\nList is empty !");
        return;
    }
    Node *current,*follow;
    current = head;
    Node *prev = NULL;
    follow=NULL;
    if (head->data == node || head->next->data == node) {
        printf("\nNothing to delete before the head or the first node!");
        return;
    }

    while(current->next != NULL && current->next->data != node){
        prev = follow;
        follow = current;
        current = current->next;
    }
    if(current->next == NULL){
        printf("\nNode entered does not exist !");
        return;
    }
    if(follow == head){
        head = current;
    }else{
        prev->next = current;
    }
    printf("\nDeleted Node: %d",follow->data);
    free(follow);
    
}

void countNodes(){
    if(head == NULL){
        printf("\nList is Empty !");
        return;
    }
    int count =0;
    Node *current = head;
    while(current != NULL){
        current = current->next;
        count++;
    }
    printf("\nTotal nodes in list: %d",count);
}

void search(int element){
    if(head == NULL){
        printf("\nList is Empty !");
        return;
    }
    Node *current = head;
    while(current != NULL && current->data != element){
        current= current->next;
    }
    if(current == NULL){
        printf("\nNode not Found !");
    }else{
        printf("\n%d found in List !",element);
    }
}

void sortList(){
    Node *current,*forward;
    current = head;
    forward = head->next;
    while(current != NULL){
        forward = current->next;
        while(forward!=NULL){
            if(current->data > forward->data){
                int temp  = current->data;
                current->data = forward->data;
                forward->data = temp;
            }
            forward = forward->next;
        }
        current = current->next;
    }
}

void main(){
    while(1){
        printf("\n1.Create List\n2.Insert at Beginning\n3.Insert At End\n4.Insert Before\n5.Forward Traversal");
        printf("\n6.Delete begnning\n7.Delete End\n8.Delete Before\n9.Total Nodes\n10.SortList\n11.Search");
        printf("\nEnter choice: ");
        int choice;
        scanf("%d",&choice);
        int data,node;
        switch(choice){
            case 1:
                createList();
                break;
            case 2:
                printf("\nEnter data: ");
                scanf("%d",&data);
                insertAtBeg(data);
                break;
            case 3:
                printf("\nEnter data: ");
                scanf("%d",&data);
                insertAtBeg(data);
                break;
            case 4:
                printf("\nEnter data: ");
                scanf("%d",&data);
                printf("\nEnter node: ");
                scanf("%d",&node);
                insertBefore(data,node);
                break;
            case 5:
                forwardTraversal();
                break;
            case 6:
                deleteAtBeg();
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8:
                printf("\nEnter node: ");
                scanf("%d",&node);
                deleteBefore(node);
                break;
            case 9:
                countNodes();
                break;
            case 10:
                sortList();
                forwardTraversal();
                break;
            case 11:
                printf("\nEnter element to search: ");
                scanf("%d",&node);
                search(node);
                break;
            default:
                exit(0);
        }
    }
}
