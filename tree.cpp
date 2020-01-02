/*
	Name: Aditya Gade		Date:30/12/2019		Class: SE-A
	A C++ Program for Linked Implementation of Binary Tree, traversals recursive and non recursive.
*/
#include<iostream>
#include<stdlib.h>
#include"MyStack.h"
using namespace std;

class Node{

	Node* right;
	Node* left;
	char data;
	
	friend class BinaryTree;
	
	Node(){
		
		left=right=NULL;
	}
};

class BinaryTree{
		Node* root;
		int count;
	public:
		BinaryTree(){
			root=NULL;
		}
		
		void create(){
		
			Node* current,*temp;
			char choice;
			do{
			
				temp=new Node;
				cout<<"\nPlease Enter Data for newly created node : ";
				cin>>temp->data;
				temp->right=temp->left=NULL;
				if(!root)
					root=temp;
				else{
					
					current=root;
					do{
						char leftOrRight;
						do{
							cout<<"\nPLEASE ENTER ('l'/'r'/'L'/'R')\n";
							cout<<"\nDo you want to attach "<<temp->data<<" to left or right of "
										<<current->data<<" : ";
							cin>>leftOrRight;
						}while(leftOrRight!='r' && leftOrRight!='l' && leftOrRight!='R' && leftOrRight!='L');
						if(leftOrRight=='l'|| leftOrRight=='L'){
						
							if(current->left==NULL){
								
								current->left=temp;
								cout<<"\n"<<temp->data<<" added to the left of "<<current->data;
								break;
							}
							else
								current=current->left;
						}
						else{	//ASSUMED FOR RIGHT AS AN OPTION
						
							if(current->right==NULL){
							
								current->right=temp;
								cout<<"\n"<<temp->data<<" added to the right of "<<current->data;
								break;
							}
							else
								current=current->right;
						}
						count++;
					}while(1);
				}
				cout<<"\nDo You Want to add more Nodes? (Y/N)) : ";
				cin>>choice;
			}while(choice=='Y'||choice =='y');
		}
		//Function Calling Functions
		void inorderDisplay(int z=0){
			if(z)
				inorderNonRecursive();
			else
				inorder(root);
		}
		void preorderDisplay(int z=0){
			if(z)
				preorderNonRecursive();
			else
				preorder(root);
		}
		void postorderDisplay(int z=0){
			if(z)
				postorderNonRecursive();
			else
				postorder(root);
		}
		//	RECURSIVE TRAVERSALS	:
		void inorder(Node* temp){
			if(temp!=NULL){
			
				inorder(temp->left);
				cout<<temp->data<<"\t";
				inorder(temp->right);
			}
		}
		
		void preorder(Node* temp){
			if(temp!=NULL){
			
				cout<<temp->data<<"\t";			
				preorder(temp->left);
				preorder(temp->right);
			}
		}
		
		void postorder(Node* temp){
			if(temp!=NULL){
			
				postorder(temp->left);
				postorder(temp->right);
				cout<<temp->data<<"\t";
			}
		}
		
		//NON RECURSIVE TRAVERSALS	:
		void inorderNonRecursive(){
			MyStack <Node*> stack(count+1);
			Node* temp=root;
			do{
				while(temp!=NULL){
					stack.push(temp);
					temp=temp->left;
				}
				if(!stack.isEmpty()){
					temp=stack.pop();
					cout<<temp->data<<"\t";
					temp=temp->right;
				}
				else
					break;
			}while(1);
		}
		
		void preorderNonRecursive(){
			MyStack <Node*> stack(count+1);
			Node* temp=root;
			do{
				while(temp!=NULL){
					cout<<temp->data<<"\t";
					stack.push(temp);
					temp=temp->left;
				}
				if(!stack.isEmpty()){
					temp=stack.pop();
					temp=temp->right;
				}
				else
					break;
			}while(1);
		}
		void postorderNonRecursive(){
		}
};
int main()
{
	BinaryTree B1;
	char switchChoice;
	do{
	
		cout<<"\nMENU:\n";
		cout<<"1.Create and Insert Nodes:"<<endl;
		cout<<"2.Inorder Display(R)"<<endl;
		cout<<"3.Postorder Display(R)"<<endl;
		cout<<"4.Preorder Display(R)"<<endl;
		cout<<"5.Inorder Display(NR)"<<endl;
		cout<<"6.Postorder Display(NR)"<<endl;
		cout<<"7.Preorder Display(NR)"<<endl;
		cout<<"0.Exit"<<endl;
		cout<<"\nEnter your Choice: ";
		cin>>switchChoice;
		switch(switchChoice)
		{
			case '1':
				B1.create();
				break;
			case '2':
				cout<<"Entered Tree Inorder is(R):\n\n";			
				B1.inorderDisplay();
				break;
			case '3':
				cout<<"Entered Tree Postorder is(R):\n\n";			
				B1.postorderDisplay();
				break;
			case '4':
				cout<<"Entered Tree Preorder is(R):\n\n";			
				B1.preorderDisplay();
				break;
			case '5':
				cout<<"Entered Tree Inorder is(NR):\n\n";			
				B1.inorderDisplay(1);
				break;
			case '6':
				cout<<"Entered Tree Postorder is(NR):\n\n";			
				B1.postorderDisplay(1);
				break;
			case '7':
				cout<<"Entered Tree Preorder is(NR):\n\n";			
				B1.preorderDisplay(1);
				break;
			case '0':
				cout<<"\nExiting the Program!!\n";
				exit (0);
			default:
				cout<<"\nPlease Enter a Valid Choice\n";
		}
	}while(1);
	return 0;
}
/*OUTPUT:
unix@unix-dx2480-MT:~$ cd SEA18
unix@unix-dx2480-MT:~/SEA18$ g++ tree.cpp
unix@unix-dx2480-MT:~/SEA18$ ./a.out

MENU:
1.Create and Insert Nodes:
2.Inorder Display(R)
3.Postorder Display(R)
4.Preorder Display(R)
5.Inorder Display(NR)
6.Postorder Display(NR)
7.Preorder Display(NR)
0.Exit

Enter your Choice: 1

Please Enter Data for newly created node : A

Do You Want to add more Nodes? (Y/N)) : y

Please Enter Data for newly created node : B

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach B to left or right of A : l

B added to the left of A
Do You Want to add more Nodes? (Y/N)) : y

Please Enter Data for newly created node : E

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach E to left or right of A : l

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach E to left or right of B : l

E added to the left of B
Do You Want to add more Nodes? (Y/N)) : y

Please Enter Data for newly created node : C

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach C to left or right of A : l

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach C to left or right of B : r

C added to the right of B
Do You Want to add more Nodes? (Y/N)) : y

Please Enter Data for newly created node : H

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach H to left or right of A : l

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach H to left or right of B : r

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach H to left or right of C : l

H added to the left of C
Do You Want to add more Nodes? (Y/N)) : y

Please Enter Data for newly created node : J

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach J to left or right of A : l

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach J to left or right of B : r

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach J to left or right of C : r

J added to the right of C
Do You Want to add more Nodes? (Y/N)) : y

Please Enter Data for newly created node : D

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach D to left or right of A : r

D added to the right of A
Do You Want to add more Nodes? (Y/N)) : y

Please Enter Data for newly created node : F

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach F to left or right of A : r

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach F to left or right of D : l

F added to the left of D
Do You Want to add more Nodes? (Y/N)) : y

Please Enter Data for newly created node : G

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach G to left or right of A : r

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach G to left or right of D : r

G added to the right of D
Do You Want to add more Nodes? (Y/N)) : y

Please Enter Data for newly created node : I

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach I to left or right of A : r

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach I to left or right of D : r

PLEASE ENTER ('l'/'r'/'L'/'R')

Do you want to attach I to left or right of G : r

I added to the right of G
Do You Want to add more Nodes? (Y/N)) : n

MENU:
1.Create and Insert Nodes:
2.Inorder Display(R)
3.Postorder Display(R)
4.Preorder Display(R)
5.Inorder Display(NR)
6.Postorder Display(NR)
7.Preorder Display(NR)
0.Exit

Enter your Choice: 2
Entered Tree Inorder is(R):

E	B	H	C	J	A	F	D	G	I	
MENU:
1.Create and Insert Nodes:
2.Inorder Display(R)
3.Postorder Display(R)
4.Preorder Display(R)
5.Inorder Display(NR)
6.Postorder Display(NR)
7.Preorder Display(NR)
0.Exit

Enter your Choice: 5
Entered Tree Inorder is(NR):

E	B	H	C	J	A	F	D	G	I	
ALL YOUR DATA IS SUCCESFULLY EMPTIED!!!

MENU:
1.Create and Insert Nodes:
2.Inorder Display(R)
3.Postorder Display(R)
4.Preorder Display(R)
5.Inorder Display(NR)
6.Postorder Display(NR)
7.Preorder Display(NR)
0.Exit

Enter your Choice: 4
Entered Tree Preorder is(R):

A	B	E	C	H	J	D	F	G	I	
MENU:
1.Create and Insert Nodes:
2.Inorder Display(R)
3.Postorder Display(R)
4.Preorder Display(R)
5.Inorder Display(NR)
6.Postorder Display(NR)
7.Preorder Display(NR)
0.Exit

Enter your Choice: 7
Entered Tree Preorder is(NR):

A	B	E	C	H	J	D	F	G	I	
ALL YOUR DATA IS SUCCESFULLY EMPTIED!!!

MENU:
1.Create and Insert Nodes:
2.Inorder Display(R)
3.Postorder Display(R)
4.Preorder Display(R)
5.Inorder Display(NR)
6.Postorder Display(NR)
7.Preorder Display(NR)
0.Exit

Enter your Choice: 3
Entered Tree Postorder is(R):

E	H	J	C	B	F	I	G	D	A	
MENU:
1.Create and Insert Nodes:
2.Inorder Display(R)
3.Postorder Display(R)
4.Preorder Display(R)
5.Inorder Display(NR)
6.Postorder Display(NR)
7.Preorder Display(NR)
0.Exit

Enter your Choice: 6
Entered Tree Postorder is(NR):


MENU:
1.Create and Insert Nodes:
2.Inorder Display(R)
3.Postorder Display(R)
4.Preorder Display(R)
5.Inorder Display(NR)
6.Postorder Display(NR)
7.Preorder Display(NR)
0.Exit

Enter your Choice: 0

Exiting the Program!!
unix@unix-dx2480-MT:~/SEA18$ 
*/
