#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
void insertionstart(struct node **head, int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newnode;
    }
    *head = newnode;
}

void insertionend(struct node **head,int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    struct node *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=temp;
    temp->next=newnode;
}
void insertionmid(struct node **head,int data,int pos){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    struct node *temp=*head;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode->data=data;
    newnode->next=temp->next;
    struct node *after=temp->next;
    temp->next=newnode; 
    after->prev=newnode;
    
}
void deletionbegin(struct node **head){
    struct node *temp=*head;
    (*head)=(*head)->next;
    (*head)->prev=NULL;
    free(temp);
}
void deletionend(struct node **head){
    struct node *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    struct node *before=temp->prev;
    before->next=NULL;
    free(temp);

}
void deletionmid(struct node **head,int pos ){
    struct node *temp=*head;
    int i=1;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    struct node *before=temp->prev;
    struct node *after=temp->next;
    before->next=after;
    after->prev=before;
    free(temp);
}

void display(struct node *temp)
{
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");

}
int main()
{
    struct node *head=NULL;
    insertionstart(&head,40);
    insertionstart(&head,50);
    insertionstart(&head,60);
    display(head);
    insertionend(&head,70);
    insertionend(&head,80);
    insertionend(&head,90);
    display(head);
    insertionmid(&head,69,3);
    display(head);
    deletionbegin(&head);
    display(head);
    deletionend(&head);
    display(head);
    deletionmid(&head,3);
    display(head);
}