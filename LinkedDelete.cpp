#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};
void push(Node** head_ref, int new_data){

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void DeleteNode(Node** head_ref, int key){
    Node* temp = (*head_ref);

    Node* last = NULL;
    if(temp != NULL && temp->data != key){
        *head_ref = temp->next;
        delete temp;
        return;
    }
    while(temp !=NULL && temp->data != key){
        last = temp;
        temp = temp->next;
    }
    if( temp == NULL)
        return;
    last->next = temp->next;
    delete temp;
}
void printLinkedList(Node* head){
    while(head!= NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}
main(){

}