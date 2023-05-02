#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data= data;
        next = NULL;
    }
};
void printList (Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp = temp->next;
    }
}
Node* insertAtBeginning(Node* head, int data)
{

     //handling NULL case
    if(head==NULL) return new Node(data);

    Node* temp = new Node(data);
    temp->next =head;
    return temp;
}
Node* insertAtLast(Node* head, int data)
{
    //handling head=NULL case
    if(head==NULL) return new Node(data);
    
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next= new Node(data);
    temp->next->next =NULL;
    return head;
}
Node* deleteAtBeginning(Node* head)
{
    if(head==NULL) return NULL;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;

}
Node* deleteAtLast(Node* head)
{
    if(head==NULL) return NULL;
    Node* temp =head;
    Node* prev = NULL;
    while(temp->next !=NULL)
    {
        prev = temp;
        temp= temp->next;
    }
    prev->next =NULL;
    delete temp;
    return head;

}
int main()
{
    Node* head = new Node(1);
    head->next = NULL;
    printList(head);
    cout<<endl;
    Node* updatedList = insertAtBeginning(head, 2);
    printList(updatedList);
    cout<<endl;
    //cout<<"befor inserting at last "; printList(updatedList); cout<<endl;
    updatedList = insertAtLast(updatedList, 3);
    printList(updatedList); cout<<endl;
    updatedList= deleteAtBeginning(updatedList);
    printList(updatedList); cout<<endl;
    updatedList = deleteAtLast(updatedList);
    printList(updatedList);

}