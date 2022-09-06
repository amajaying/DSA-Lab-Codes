#include<stdio.h>
#include<stdlib.h>
struct node{
    int coff;
    int power;
    struct node* next;
};
void create_node(int x, int y, struct node** temp){
    struct node *r, *z;
    z=*temp;
    if(z==NULL){
        r=(struct node*) malloc (sizeof(struct node));
        r->coff = x;
        r->power = y;
        *temp = r;
        r->next = (struct node*) malloc (sizeof(struct node));
        r=r->next;
        r->next=NULL;
    }
    else{
        r->coff = x;
        r->power = y;
        r->next = (struct node*)malloc(sizeof(struct node));
        r = r->next;
        r->next = NULL;
    }
}

void add(struct node* pol1, struct node* pol2, struct node* pol){
    while (pol1->next && pol2->next)
    {
        if(pol1->power > pol2->power){
            pol->power = pol1->power;
            pol->coff = pol1->coff;
            pol1 = pol1->next;
        }
        else if(pol1->power < pol2->power){
            pol->power = pol2->power;
            pol->coff = pol2->coff;
            pol2 = pol2->next;
        }
        else{
            pol->power = pol1->power;
            pol->coff = pol1->coff + pol2->coff;
            pol1 = pol1->next;
            pol2 = pol2->next;
        }
        pol->next = (struct node*) malloc(sizeof(struct node));
        pol = pol->next;
        pol->next = NULL;
    }
    while(pol1->next || pol2->next){
        if(pol1->next){
            pol->power = pol1->power;
            pol->coff = pol1->coff;
            pol1 = pol1->next;
        }
        if(pol2->next){
            pol->power = pol2->power;
            pol->coff = pol2->coff;
            pol2 = pol2->next;
        }
        pol->next = (struct node*)malloc(sizeof(struct node));
        pol = pol->next;
        pol->next = NULL;
    }
}


void sub(struct node* pol1, struct node* pol2, struct node* pol){
    while (pol1->next && pol2->next)
    {
        if(pol1->power > pol2->power){
            pol->power = pol1->power;
            pol->coff = pol1->coff;
            pol1 = pol1->next;
        }
        else if(pol1->power < pol2->power){
            pol->power = pol2->power;
            pol->coff = pol2->coff;
            pol2 = pol2->next;
        }
        else{
            pol->power = pol1->power;
            pol->coff = pol1->coff - pol2->coff;
            pol1 = pol1->next;
            pol2 = pol2->next;
        }
        pol->next = (struct node*) malloc(sizeof(struct node));
        pol = pol->next;
        pol->next = NULL;
    }
    while(pol1->next || pol2->next){
        if(pol1->next){
            pol->power = pol1->power;
            pol->coff = pol1->coff;
            pol1 = pol1->next;
        }
        if(pol2->next){
            pol->power = pol2->power;
            pol->coff = pol2->coff;
            pol2 = pol2->next;
        }
        pol->next = (struct node*)malloc(sizeof(struct node));
        pol = pol->next;
        pol->next = NULL;
    }
}

void display(struct node* a){
    while (a->next != NULL){
        printf("%dx^%d", a->coff, a->power);
        a=a->next;
        if(a->coff >= 0){
            if(a->next != NULL)
                printf("+");
        }
    }
}
int main(){
    struct node *pol1 = NULL, *pol2 = NULL, *pol = NULL;
    int d1, e, c, d2;
    printf("Polynomial 1:\n");
    printf("Enter the highest degree: ");
    scanf("%d", &d1);
    int counter1 = d1;
    while (counter1 >= 0)
    {
        e = counter1;
        printf("Enter coefficient of x^%d: ", e);
        scanf("%d", &c);
        create_node(c, e, &pol1);
        counter1--;
    }
    printf("Polynomial 2:\n");
    printf("Enter the highest degree: ");
    scanf("%d", &d2);
    int counter2 = d2;
    while (counter2 >= 0)
    {
        e = counter2;
        printf("Enter coefficient of x^%d: ", e);
        scanf("%d", &c);
        create_node(c, e, &pol2);
        counter2--;
    }
    printf("1st Number: ");
    display(pol1);
    printf("\n2nd Number: ");
    display(pol2);
    pol = (struct node*)malloc(sizeof(struct node));
    add(pol1, pol2, pol);
    printf("\nAdded polynomial: ");
    display(pol);
    sub(pol1, pol2, pol);
    printf("\nSubtracted polynomial: ");
    display(pol);
}