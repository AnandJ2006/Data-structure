#include<stdio.h>
#define max 5
int que[max],front=-1,rear=-1;
void enqueue(int data){
    if((rear+1)%max==front){
        printf("Queue Full \n");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        que[rear]=data;
    }
    else{
        rear=(rear+1)%max;
        que[rear]=data;
    }
}
void dequeue(){
    if(front ==-1&&rear==-1){
        printf("Empty");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front=(front+1)%max;
    }
}
void display(){
    int i=front;
    if(front==-1&&rear==-1){
        printf("Queue is Empty \n");
    }
    else{
        while(i!=rear){
            printf("%d ",que[i]);
            i=(i+1)%max;
        }
        printf("%d ",que[rear]);
    }
    printf("\n");
}
int main(){
    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    display();
    dequeue();
    display();
}