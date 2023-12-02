#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
    node(int input){
        data=input;
        next=nullptr;
    }
    
};

class clsnode{
    public:
    int data;
    clsnode* next;
    clsnode(int input){
        data=input;
        next=nullptr;
    }
};



int main()
{   
  
  
    node newnode(0);
    node* current=&newnode;
    for(int i=1;i<=10;i++){
        current->next=new node(i*10);
        current=current->next;
    }
   node* start = &newnode;
   while(start!=nullptr){
        cout<<start->data<<"->";
        start=start->next;
   }
    cout<<endl;
    return 0;
}