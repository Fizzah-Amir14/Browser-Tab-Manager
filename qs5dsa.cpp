#include <iostream>
#include <string>
using namespace std;
struct node{
     int id;                
    string title;             
    string url;      
    node *next;
    node *prev;

};
void openTab(node *&head,int i,string t,string u){
    node *newnode=new node;
    newnode->id=i;
    newnode->title=t;
    newnode->url=u;
    if(head==NULL){
        head=newnode;
        newnode->next=NULL;
        newnode->prev=NULL;
        return;
    }
    if(head->next==NULL){
        head->next=newnode;
        newnode->prev=head;
        return;

    }
    else{
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }temp->next=newnode;
        newnode->prev=temp;
    }
}
void displayTabsForward(node *&head){
    if(head==NULL)  return;
    else{
        node *temp=head;
        while(temp!=NULL){
            cout<<"Id:"<<temp->id<<"Website title:"<<temp->title<<"URL:"<<temp->url<<endl;
            temp=temp->next;
        }cout<<endl;
    }
}
void displayTabsReverse(node *&head){
    if(head==NULL) return;
    else{
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
       while(temp!=NULL){
           cout<<"Id:"<<temp->id<<"Website title:"<<temp->title<<"URL:"<<temp->url<<endl;
           temp=temp->prev;
       }cout<<endl;
    }
}
void  closeTabByID(node *&head,int targetId){
    if(head==NULL )return;
    if(head->next==NULL && head->id==targetId){
        delete head;
        head=NULL;
        return;
    }
     if (head->id == targetId) {
        node* todel = head;
        head = head->next;
        head->prev = NULL;     
        delete todel;
        return;
    }
    node *temp=head;
    while (temp->next != NULL) {
    temp = temp->next;
}


if (temp->id == targetId) {
    temp->prev->next = NULL;  
    delete temp;
}
  
    while(temp!=NULL){
        if(temp->id==targetId){
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete temp;
            return;
        }temp=temp->next;
    }
}
void switchTab(node* head, int targetId) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->id == targetId) {
            cout << "Switched to Tab " << temp->id 
                 << ": " << temp->title 
                 << " (" << temp->url << ")" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Tab with ID " << targetId << " not found." << endl;
}

int main(){
node *head=NULL;
openTab(head,12,"Youtube","www.youtube.com");
openTab(head,13,"WhatsApp","www.whatsapp.com");
openTab(head,14,"FaceBook","www.facebook.com");

cout<<"Opening  tabs in forward order:"<<endl;
displayTabsForward(head);
cout<<"Opening  tabs in reverse order:"<<endl;
displayTabsReverse(head);
closeTabByID(head,14);
displayTabsForward(head);
switchTab(head,13);


return 0;
}

