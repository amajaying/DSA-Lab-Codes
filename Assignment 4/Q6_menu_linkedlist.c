#include<stdio.h>
#include<stdlib.h>

void choice();

struct node{
    int n;
    struct node* next;
};
struct node* head = NULL, * temp, * newnode;
void create_node(){
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter number: ");
    scanf("%d", &newnode->n);
    newnode->next=NULL;
    if(head==NULL)
        head=temp=newnode;
    else{
        temp->next = newnode;
        temp = newnode;
    }
}
void displayMenu(){
    printf("------------------------------MENU------------------------------\n");
    printf("1. Traverse the linked list and print the data.\n");
    printf("2. Find the sum of all nodes.\n");
    printf("3. Search an data element in the given linked list.\n");
    printf("4. Insert a node at front.\n");
    printf("5. Insert a node at last.\n");
    printf("6. Insert a node at any position.\n");
    printf("7. Delete a node at front.\n");
    printf("8. Delete a node at last.\n");
    printf("9. Delete a node at any position.\n");
    printf("10. Exit.\n");
    printf("----------------------------------------------------------------\n");
    choice();
}
void traverseDisplay(){
    temp = head;
    printf("\nThe data of the linked list are: \n\n");
    while(temp != NULL){
        printf("The data is: %d\n", temp->n);
        temp = temp->next;
    }
}
void sumNodes(){
    temp = head;
    int sum = 0;   
    while(temp != NULL){
        sum = sum + temp->n;
        temp = temp->next;
    }
    printf("\nThe sum of all nodes: %d\n\n", sum);
}
void search(){
    int k;
    printf("Enter data to search: ");
    scanf("%d", &k);
    temp = head;
    int x=1;
    while(temp != NULL){
        if(temp->n == k){
            printf("Found\n");
            x=0;
        }
        temp = temp->next;
    }
    if(x)
        printf("Not Found!\n");
}
void insertFirst(){
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter number: ");
    scanf("%d", &newnode->n);
    if(head==NULL)
        head=newnode;
    else{
        temp=head;
        head = newnode;
        newnode->next = temp;
    }
    traverseDisplay();
}
void insertLast(){
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter number: ");
    scanf("%d", &newnode->n);
    temp = head;
    newnode->next=NULL;
    if(head==NULL)
        head=temp=newnode;
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        temp = newnode;
    }
    traverseDisplay();
}

void insertPos(){
    int pos;
    printf("Enter position to insert node: ");
    scanf("%d", &pos);
    temp = head;
    int i = 1;
    while(i<pos-1){
        temp = temp -> next;
        i++;
    }
    struct node *temp1;
    temp1 = temp->next;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter number: ");
    scanf("%d", &newnode->n);
    temp->next = newnode;
    newnode->next = temp1;
    traverseDisplay();
}
void delFirst(){
    temp = head;
    if(head==NULL)
        printf("The linked list doesn't exist!");
    else{
        head = temp->next;
        free(temp);
    }
    traverseDisplay();
}
void delLast(){
    temp = head;
    if(head==NULL)
        printf("The linked list doesn't exist!");
    else{
        struct node *temp1;
        while (temp->next!=NULL)    
        {
            temp1 = temp;
            temp = temp->next;     
        }
        temp1->next=NULL;
        free(temp);
    }
    traverseDisplay();
}
void delPos(){
    temp = head;
    if(head==NULL)
        printf("The linked list doesn't exist!");
    else{
        int pos;
        printf("Enter position to delete: ");
        scanf("%d", &pos);
        int i=1;
        temp=head;
        struct node *temp1;
        while (i<pos-1)    
        {
            temp = temp->next;
            i++;     
        }
        temp1=temp->next;
        temp->next=temp1->next;
        free(temp1);
        traverseDisplay();
    }
}
void goBack(){
    int x;
    printf("Press 1 to go back to MENU and 0 to exit: ");
    scanf("%d", &x);
    if(x)
        displayMenu();
    else
        exit(0);
}

void choice(){
    int choice;
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    switch (choice){
        case 1:
            traverseDisplay();
            goBack();
        case 2:
            sumNodes();
            goBack();
        case 3:
            search();
            goBack();
        case 4:
            insertFirst();
            goBack();
        case 5:
            insertLast();
            goBack();
        case 6:
            insertPos();
            goBack();
        case 7:
            delFirst();
            goBack();
        case 8:
            delLast();
            goBack();
        case 9:
            delPos();
            goBack();
        default:
            exit(1);
    }
}
int main(){
    int a;
    printf("How many nodes do you want to create? ");
    scanf("%d", &a);
    while(a--)
        create_node();
    displayMenu();
}