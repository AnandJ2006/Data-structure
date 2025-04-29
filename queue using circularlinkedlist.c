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
    if(front==0&&rear==0){
        front=rear=newnode;
        rear->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}
void dequeue(){
    struct node *temp=front;
    if(front==0&&rear==0){
        printf("Empty\n");
    }
    else if(front==rear){
        front=rear=0;
        free(temp);
    }
    else{
        front=front->next;
        rear->next=front;
        free(temp);
    }
}
void display(){
    struct node *temp=front ;
    if(front==0&&rear==0){
        printf("Empty");
    }
    else{
        while(temp->next!=front){
          printf("%d ",temp->data);
          temp=temp->next;
            
        }
        printf("%d ",temp->data);
    }
    printf("\n");
}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    
}