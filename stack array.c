#include<stdio.h>
int MAX=5;
int stack[5];
int top=-1;
int iffull(){
    if(top==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
int ifempty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int pop(){
    if(!ifempty()){
        int data=stack[top];
        stack[top]=0;
    }
    return 0;
}
int push(int data){
    if(!iffull()){
      top=top+1;
      stack[top]=data;
    }
    return 0;
}
int peek(){
    int data=stack[top];
    printf("%d\n ",data);
}
int display(){
    for(int i=0;i<5;i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main(){
   push(8);
   push(9);
   push(10);
   push(11);
   push(112);
   display();
   peek();
   pop();
   display();
}