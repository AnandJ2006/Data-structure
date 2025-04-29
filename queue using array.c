#include<stdio.h>
#define max 5
int que[max],front=-1,rear=-1;
void enqueue(int data){
    if(rear == max-1){ 
        printf("Queue is Full \n");
    }
    else if(front == -1 && rear==-1){
        front=rear=0;
        que[rear]=data;
    }
    else{
        rear++;
        que[rear]=data;
    }
}
void dequeue(){
    if(front==-1 && rear==-1){
        printf("Empty");
    }
    else if(front==rear){
        front = rear = -1;
    }
    else{
        front++;
    }
} 

void display(){
    if(front == -1 && rear==-1){
        printf("Empty \n");
    }
    for(int i=front;i<rear+1;i++){
        printf("%d ",que[i]);
    }
    printf("\n");
}
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    dequeue();
    display();
    dequeue();
    dequeue();
    display();
    dequeue();
    display();
}