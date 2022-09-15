#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev, *next;
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
        printf("The linked list is EMPTY!\n");
    }
    else{
        printf("The linked list is NOT EMPTY!\n");
    }
    
    displayMenu();
}

void isFull(){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("The linked list is FULL!\n");
    }
    displayMenu();
}

void insertAtFront()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &temp->data);
    temp->prev = NULL;
    temp->next = head;
    head = temp;
    displayNodes();
    displayMenu();
}

void insertAtEnd()
{
    struct node *temp, *trav;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter number to be inserted: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    trav = head;

    if (head == NULL) {
 
        head = temp;
    }
    else {
        while (trav->next != NULL)
            trav = trav->next;
        temp->prev = trav;
        trav->next = temp;
    }
    displayNodes();
    displayMenu();
}

void deleteFirst()
{
    struct node* temp;
    if (head == NULL)
        printf("\nList is empty\n");
    else {
        temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
    }
    displayNodes();
    displayMenu();
}
void deleteEnd()
{
    struct node* temp;
    if (head == NULL)
        printf("\nList is empty\n");
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    if (head->next == NULL)
        head = NULL;
    else {
        temp->prev->next = NULL;
        free(temp);
    }
    displayNodes();
    displayMenu();
}

void searchAtStart(){
    struct node *temp;
    int data;
    printf("Enter data to search: ");
    scanf("%d", &data);
    temp = head;
    while(temp != NULL){
        if(temp->data == data){
            printf("Data found at start!\n");
            break;
        }
        temp = temp->next;
    }
    displayMenu();
}

void searchAtEnd(){
    struct node *temp;
    int data;
    printf("Enter data to search: ");
    scanf("%d", &data);
    temp = head;
    while(temp != NULL){
        if(temp->data == data){
            printf("Data found at end!\n");
            break;
        }
        temp = temp->next;
    }
    displayMenu();
}

void options(int choice, int n){

    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice){
        case 1:
            printf("How many nodes do you want to create? ");
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
            insertAtFront();
            break;
        case 5:
            insertAtEnd();
            break;
        case 6:
            deleteFirst();
            break;
        case 7:
            deleteEnd();
            break;
        case 8:
            searchAtStart();
            break;
        case 9:
            searchAtEnd();
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
    }
    printf("Want more? ");
    scanf("%d", &choice);
}

int main(){
    // Menu driven
    displayMenu();
    
    int choice;
   
    int n;
    options(choice, n);
    
}