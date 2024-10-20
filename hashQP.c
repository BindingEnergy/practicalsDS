#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct{
    int key;
    int value;
}HashTable;

void initialiseTable(HashTable table[]){
    for(int i = 0 ; i < TABLE_SIZE ; i++){
        table[i].key= -1;
        table[i].value = 0;
    }
}

int hash(int key){
    return key%TABLE_SIZE;
}

void insert(HashTable table[], int key , int value){
    int hashIndex = hash(key);
    int placeIndex = hashIndex;

    //handling collision using quadratic probing
    for(int i = 0 ; i < TABLE_SIZE ; i++){
        placeIndex = (placeIndex+i*i) % TABLE_SIZE;
        if(table[placeIndex].key == -1){
            table[placeIndex].key = key;
            table[placeIndex].value = value;
            return;
        }
    }
    printf("\nTable Full !");
}

int search(HashTable table[] , int key , int value){
    int hashIndex = hash(key);
    int placeIndex = hashIndex;
    for(int i = 0 ; i < TABLE_SIZE ; i++){
        placeIndex = (placeIndex + i*i) % TABLE_SIZE;
        if(table[placeIndex].key == key && table[placeIndex].value == value){
            return placeIndex;
        }
    }
    return -1;
}

void delete(HashTable table[] ,int value){
    int placeIndex = 0;
    for(int i = 0 ; i< TABLE_SIZE ; i++){
        placeIndex = (placeIndex + i*i)%TABLE_SIZE;
        if(table[placeIndex].value == value){
            table[placeIndex].key  = -1;
            table[placeIndex].value = 0;
            return;
        }
    }
    printf("\n%d not found in Table !",value);
}

void display(HashTable table[]){
    printf("\n----------HASH TABLE----------");
    printf("\n==============================\n");
    for(int i = 0 ; i < TABLE_SIZE ;i++){
        printf("%10d%20d%20d\n",(i+1),table[i].key,table[i].value);
    }
}

void main(){
    HashTable table[TABLE_SIZE];
    initialiseTable(table);

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\nEnter choice: ");
        int choice;
        scanf("%d", &choice);
        int key, value, index;
        switch (choice) {
            case 1:
                printf("\nEnter key and value: ");
                scanf("%d%d", &key, &value);
                insert(table, key, value);
                break;
            case 2:
                printf("\nEnter key and value: ");
                scanf("%d%d", &key, &value);
                index = search(table, key, value);
                if (index != -1) {
                    printf("\nValue %d found at index %d\n", value, index+1);
                } else {
                    printf("\nValue %d not found in the table\n", value);
                }
                break;
            case 3:
                printf("\nEnter value to delete: ");
                scanf("%d", &value);
                delete(table, value);
                break;
            case 4:
                display(table);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}