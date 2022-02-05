#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
struct node {
	int data,no,counter;
	node *head=NULL,*tail=NULL,*next,*temp,*curr;
	
	//**********ISERTION FUNCTION************
	
	void CreateFunction(){
		system("cls");
		if(head==NULL && tail==NULL){
			temp=new node;
			cout<<"Enter data into new node: ";
			cin>>temp->data;
			temp->next=NULL;
			head=temp;
			tail=temp;
		}
		else if(head->next==NULL && tail->next==NULL){
			temp=new node;
			cout<<"Enter data into new node 2: ";
			cin>>temp->data;
			temp->next=NULL;
			if(head->data>temp->data){
				tail=head;
				head=temp;
				head->next=tail;
				tail->next=NULL;
			}
			else{
				tail=temp;
				head->next=tail;
			}
		}
		else{
			temp=new node;
			cout<<"Enter data into new node 3 and so on: ";
			cin>>temp->data;
			temp->next=NULL;
			curr=head;
			if(curr->data>=temp->data){
				temp->next=head;
				head=temp;
			}
			else{}
		}
	}
	//**********DISPLAY FUNCTION**********
	void Displayfunction(){
		system("cls");
		curr=head;
		cout<<"******Result******\n\n";
		while(curr!=NULL){
			cout<<curr->data<<endl;
			curr=curr->next;
		}
		getch();
	}
	
	//**********SEARCH FUNCTION**********
	
	void SearchFunction(){
		system("cls");
		curr=head;
		counter=1;
		cout<<"Enter data to search : ";
		cin>>no;
		while(curr!=NULL){
			if(curr->data==no){
				cout<<"Data found on "<<counter<<" node";
				getch();
				break;
			} 
			counter++;
			curr=curr->next;
		}	
	}
	
	//**********DELETION FUNCTION**********
	
	void DeleteFunction(){
		system("cls");
		cout<<"Enter data to delete : ";
		cin>>no;
		curr=head;
		while(curr!=NULL){
			if(head->data==no){
				curr=curr->next;
				delete head;
				head=curr;
				break;
			}
			else if(curr->next->data==no){
				temp=curr->next;
				curr->next=temp->next;
				delete temp;
				break;
			}
			else if(curr->next==tail){
				delete tail;
				tail=curr;
				tail->next=NULL;
			}
			curr=curr->next;
		}
		cout<<"Node deleted";
		getch();
	}
	
	//**********UPDATE FUNCTION**********
	
	void UpdateFunction(){
		system("cls");
		cout<<"Enter data to search for Update : ";
		cin>>no;
		curr=head;
		while(curr!=NULL){
			if(curr->data==no){
				cout<<"Enter data to Update now: ";
				cin>>no;
				curr->data=no;
				break;
			}
			curr=curr->next;
		}
	}
};

//**********MAIN FUNCTION**********

int main(){
	node obj;
	int n;
	do{
		system("cls");
		cout<<"\n\n\t\t1. Create node" 
			<<"\n\n\t\t2. Search node" 
			<<"\n\n\t\t3. Display node"
			<<"\n\n\t\t4. Delete node "
			<<"\n\n\t\t5. Update node "
			<<"\n\n\t\t6.Exit "
			<<"\n\n\tEnter Menu : ";
		cin>>n;
		switch(n){
			case 1:{
				obj.CreateFunction();
				break;
			}
			case 2:{
				obj.SearchFunction();
				break;
			}
			case 3:{
				obj.Displayfunction();
				break;
			}
			case 4:{
				obj.DeleteFunction();
				break;
			}
			case 5:{
				obj.UpdateFunction();
				break;
			}
			case 6:{
				break;
			}
		}
	}
	while(n!=6);
}


