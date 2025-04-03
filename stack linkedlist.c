#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    
};
struct node *top=NULL;
void push(int data){

    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->data=data;
    p->next=top;
    top=p;
}
void pop(){
    struct node *temp=top;
    top=top->next;
    free(temp);
}
void peek(){
    struct node *temp=top;
    int data=temp->data;
    printf("\n %d",data);
}
void display(){
    struct node *temp=top;
    if(top==NULL){
        printf("Stack is Empty");
    }
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
    
}
int main(){
    push(1);
    push(2);
    push(3);
    display();
    pop();
    display();
    peek();
}