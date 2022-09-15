// Write a C Program to create a Double-Way linked list and perform the basic
// operations:
// a) Creation
// b) isEmpty
// c) isFull
// d) Insertion_from_start
// e) Insertion_from_end
// f) Deletion_from_start
// g) Deletion_from_end
// h) Search_from_start
// i) Search_from_end

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void displayMenu(){
    printf("\nMENU\n");
    printf("1. Create node\n");
    printf("2. Is Empty\n");
    printf("3. Is Full\n");
    printf("4. Insert from front\n");
    printf("5. Insert from end\n");
    printf("6. Delete from first\n");
    printf("7. Delete from end\n");
    printf("8. Search from start\n");
    printf("9. Search from end\n");
    printf("10. Exit\n");
}

void displayNodes(){
    struct node *temp = head;
    printf("\nThe data are: ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
}

void create_node(int n){
    for(int i=0; i<n; i++){
        struct node *new_node, *temp;
        int data;
        printf("Enter data: ");
        scanf("%d", &data);
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->prev = NULL;
        new_node->next = NULL;
        if(head == NULL){
            head = new_node;
        }
        else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
    }
    displayNodes();
    displayMenu();
}

void isEmpty() {
    if(head == NULL){
        printf("The list is empty");
    }
    else{
        printf("The list is not empty");
    }
    displayMenu();
}

void isFull() {
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("The list is full");
    }
    else{
        printf("The list is not full");
    }
    displayMenu();
}

void insert_from_start() {
    struct node *new_node;
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    if(head == NULL){
        head = new_node;
    }
    else{
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    displayNodes();
    displayMenu();
}

void insert_from_end() {
    struct node *new_node, *temp;
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    if(head == NULL){
        head = new_node;
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    displayNodes();
    displayMenu();
}

void delete_from_start() {
    struct node *temp;
    if(head == NULL){
        printf("The list is empty");
    }
    else{
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }
    displayNodes();
    displayMenu();
}

void delete_from_end() {
    struct node *temp;
    if(head == NULL){
        printf("The list is empty");
    }
    else{
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
    displayNodes();
    displayMenu();
}

void search_from_start() {
    struct node *temp;
    int data, flag=0;
    printf("Enter data to search: ");
    scanf("%d", &data);
    temp = head;
    while(temp != NULL){
        if(temp->data == data){
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if(flag == 1){
        printf("Data found");
    }
    else{
        printf("Data not found");
    }
    displayMenu();
}

void search_from_end() {
    struct node *temp;
    int data, flag=0;
    printf("Enter data to search: ");
    scanf("%d", &data);
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        if(temp->data == data){
            flag = 1;
            break;
        }
        temp = temp->prev;
    }
    if(flag == 1){
        printf("Data found");
    }
    else{
        printf("Data not found");
    }
    displayMenu();
}


int main(){
    int choice, n;
    displayMenu();
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                create_node(n);
                break;
            case 2:
                isEmpty();
                break;
            case 3:
                isFull();
                break;
            case 4:
                insert_from_start();
                break;
            case 5:
                insert_from_end();
                break;
            case 6:
                delete_from_start();
                break;
            case 7:
                delete_from_end();
                break;
            case 8:
                search_from_start();
                break;
            case 9:
                search_from_end();
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}

