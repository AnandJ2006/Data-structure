#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=0;
struct node *rear=0;
void enqueue(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node ));
    newnode->data=data;
    newnode->next=NULL;
    if(front ==0 && rear == 0){
        front = rear =newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue(){
    struct node *temp=front;
    if(front==0&&rear==0){
        printf("Empty \n");
    }
    else{
        front=front->next;
        free(temp);
    }
}
void display(){
    struct node *temp=front;
    while(temp!=0){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
    enqueue(1);
    display();
}