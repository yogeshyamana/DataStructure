#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
}*top = NULL;

void push(int x){

    Node *t = new Node();
    if(t==NULL){
        cout<<"stack is Full";
    }
    t->data = x;
    t->next = top;
    top = t;
}

int pop(){
    Node *p;
    int x =-1;
    if(top->next==NULL)
        cout<<"Stack is Empty";
    else {
        p = top;
        top = top->next;
        x = p->data;
        delete p;
    }
    return x;

}

void diplay(){
    Node *p;
    p= top;
    while(p!=NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

int main(){

    push(23);
    push(34);
    push(2);
    push(9);    

    diplay();

    cout<<pop();

}