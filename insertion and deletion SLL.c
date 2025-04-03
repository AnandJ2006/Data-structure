#include<stdio.h>
#include<stdlib.h>
struct node {
   int data;
   struct node *next;
};
void insertionatbeg(struct node **head,int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;

}
void insertionatend(struct node **head,int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    struct node *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newnode->data=data;
    newnode->next=NULL;
    temp->next=newnode;
}
void insertionatmid(struct node **head,int data,int pos){
    struct node *newnode=(struct node *)malloc(sizeof(struct node ));
    struct node *temp=*head;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode->data=data;
    newnode->next=temp->next;
    temp->next=newnode;
}
void deletionatbeg(struct node **head){
    struct node *temp=*head;;
    *head=temp->next;
    free(temp);
}
void deletionatend(struct node **head){
    struct node *temp=*head;
    struct node *prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    free(temp);
}
void deletionatmid(struct node **head,int pos){
    struct node *temp=*head;
    struct node *prev=NULL;
    int i=1;
    while(i<pos){
        prev=temp;
        temp=temp->next;
        i++;
    }
    prev->next=temp->next;
    free(temp);
}
void rev(struct node **head){
    struct node *currentnode=*head;
    struct node *prevnode=NULL;
    struct node *nextnode=NULL;
    while(currentnode!=NULL){
        nextnode=currentnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    *head=prevnode;
}
void modify(struct node **head,int newnnode,int oldnode){
    
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
int main(){
    struct node *head=NULL;
    insertionatbeg(&head,4);
    insertionatbeg(&head,3);
    insertionatbeg(&head,2); 
    insertionatbeg(&head,1);
    display(head);
    insertionatend(&head,5);
    insertionatend(&head,6);
    display(head);
    insertionatmid(&head,69,3);
    display(head);
    deletionatbeg(&head);
    display(head);
    deletionatend(&head);
    display(head);
    deletionatmid(&head,2);
    display(head);
    rev(&head);
    display(head);
}