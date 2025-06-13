#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
void insertatbegin(int data){
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    if(head==NULL){
        nn->next=nn;
        nn->prev=nn;
        head=nn;
        return;
    }
    struct node *temp=head->prev;
    nn->next=head;
    nn->prev=temp;
    temp->next=nn;
    head->prev=nn;
    head=nn;
}
void insertatend(int data){
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    nn->data=data;
    if(head==NULL){
        nn->next=nn;
        nn->prev=nn;
        head=nn;
        return;
    }
    struct node *temp=head->prev;
    temp->next=nn;
    nn->next=head;
    nn->prev=temp;
    head->prev=nn;
}
void deleteatbegin(){
    struct node *temp=head;
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    struct node *last=head->prev;
    head=temp->next;
    head->prev=last;
    last->next=head;
    free(temp);
}
void deleteatend(){
    struct node *temp=head->prev;
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    struct node *last=temp->prev;
    last->next=head;
    head->prev=last;
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