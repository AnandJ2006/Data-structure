#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void insertatbegin(int data){
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    if(head==NULL){
        nn->next=nn;
        head=nn;
        return;
    }
    struct node *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    nn->next=head;
    temp->next=nn;
    head=nn;
}
void insertatend(int data){
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    if(head==NULL){
        nn->next=nn;
        head=nn;
        return;
    }
    struct node *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=nn;
    nn->next=head;
}
void deleteatbegin(){
    struct node *temp=head;
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    struct node *last=head;
    while(last->next!=head){
        last=last->next;
    }
    head=temp->next;
    last->next=head;
    free(temp);
}
void deleteatend(){
    struct node *temp=head;
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    struct node *prev=NULL;
    while(temp->next!=head){
        prev=temp;
        temp=temp->next;
    }
    prev->next=head;
    free(temp);
}
void display(){
    if(head==NULL){
        printf("Empty");
    }
    struct node *temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}
int main(){
    insertatbegin(3);
    insertatbegin(2);
    insertatbegin(1);
    display();
    insertatend(4);
    display();
    deleteatbegin();
    display();
    deleteatend();
    display();
    
}