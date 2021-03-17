#include<bits/stdc++.h>
using namespace std;

class newstack{
public:
    int size;
    int top;
    int *s;
};

void create(newstack *st){
    cout<<"Enter Size";
    cin>>st->size;
    st->top = -1;
    st->s = new int[st->size]; 
}
void display( newstack st){
    int i;
    for(i=st.top ; i>=0;i--){
        cout<<st.s[i]<<" ";
    }
}
void push( newstack *st , int x){

    if(st->top == st->size-1)
        cout<<"Stack Overflow";
    else{
        st->top++;
        st->s[st->top] = x;
    }

}
int pop(newstack *st){
    
    int x=-1;
    if(st->top==-1)
        cout<<"Stack is Empty";
    else{
        x = st->s[st->top--];
    }
    return x;
}
int peak(newstack st, int index){
    int x=-1;
    if(st.top-index<0)
        cout<<"Invalid index";
    x= st.s[st.top-index+1];
    return x;
}

int isEmpty(newstack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}

int full( newstack st){
    
    return (st.top == st.size-1);
    
}

int stacktop(newstack st){
    if(!isEmpty(st))
        return st.s[st.top];
    return -1;
}
int main(){

    newstack st;
    create(&st);

    push(&st, 23);
    push(&st, 14);
    push(&st, 57);
    push(&st, 11);
    push(&st, 36);

    //display(st);


    cout<<peak(st , 4);
    cout<<endl;
    cout<<stacktop(st);
}