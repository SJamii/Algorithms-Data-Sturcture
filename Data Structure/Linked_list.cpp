#include<bits/stdc++.h>
using namespace std;

class Node{       //structure of a  node
	public:
		int data;
		Node* next;
};

void printList(Node* n)
{
	while(n!=NULL)
	{
		cout<<n->data<<" ";
		n = n->next;
	}
}

void push(Node** head_ref, int new_data)    //For Inserting node at the head
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	*head_ref = new_node;
}

void insertAfter(Node* prev_node, int new_data)   //For Inserting after given node
{
	if(prev_node == NULL) cout<<"Error! Previous node cannot be null!"<<endl;
	else
	{
		Node* new_node = new Node();
		new_node->data = new_data;
		new_node->next = prev_node->next;
		prev_node->next = new_node;
	}
}

void append(Node** head_ref, int new_data) //For inserting at the end of the node
{
	Node* new_node = new Node();
	Node *last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	if(*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}
	while(last->next != NULL)
	{
		last = last->next;
	}
	last->next = new_node;
	return;
}

int main()
{
	Node* head = NULL;
	append(&head,7);
	push(&head,2);
	push(&head,5);
	append(&head,9);
	insertAfter(head->next,8);
	printList(head);
}
