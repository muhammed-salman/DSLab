#include<stdio.h>
#include<stdlib.h>

typedef struct bst{
	int data;
	struct bst *left,*right;
}node;

void traverse_inorder(node *r){
	if(r!=NULL){
		traverse_inorder(r->left);
		printf("%d\t",r->data);
		traverse_inorder(r->right);
	}
}
void insert(node **r,int num){
	node *temp,*ptr;
	temp=*r;
	
	if(temp==NULL){
		ptr=(node*)malloc(sizeof(node));
		ptr->data=num;
		ptr->left=NULL;
		ptr->right=NULL;
		*r=ptr;
	}
	else{
		if(num>temp->data){
				insert(&temp->right,num);
		}
		else{
				insert(&temp->left,num);
		}
	}
}
int search_bst(node *r,int num){
	if(r==NULL)
		return 0;
	else{
		if(r->data==num)
			return 1;
		else{	
			if(num>r->data)
				return search_bst(r->right,num);
			else
				return search_bst(r->left,num);
		}
			
	}
}

void search_node(node **x,node *root,node **parent,int num,int *f){
	node *temp;
	temp=root;
	if(temp==NULL)
		return;
	while(temp!=NULL)
	{
		if(temp->data==num)
		{
			*f=1;
			*x=temp;
			return;
		}
		*parent=temp;
		if(num > temp->data)
			temp=temp->right;
		else
			temp=temp->left;	
	}				
}
void delete(node **r,int num){
	node *temp,*parent,*xsucc,*x;
	int f=0;
	parent=NULL;x=NULL;xsucc=NULL;
	temp=*r;
	search_node(&x,temp,&parent,num,&f);
	if(f==0){
		printf("\nThe Element %d id not found",num);
		return;
	}
	//x has no child
	if(x->left==NULL && x->right==NULL)
	{
		if(x->data > parent->data)
			parent->right=NULL;
		else
			parent->left=NULL;		
	}
	//x has left child
	else if(x->left!=NULL && x->right==NULL)
	{
		if(x->data > parent->data)
			parent->right=x->left;
		else
			parent->left=x->left;
	}
	//x has right child
	else if(x->right!=NULL && x->left==NULL)
	{
		if(x->data > parent->data)
			parent->right=x->right;
		else
			parent->left=x->right;
	}
	//x has both left and right child
	else if(x->left!=NULL && x->right!=NULL)
	{
		xsucc=x->right;
		parent=x;
		while(xsucc->left!=NULL)
		{
			parent=xsucc;
			xsucc=xsucc->left;
		}
		x->data=xsucc->data;
		x=xsucc;
		if(x->data > parent->data)
			parent->right=NULL;
		else
			parent->left=NULL;
	}
	free(x);
}

int main(){
	node *root=NULL;
	insert(&root,20);
	insert(&root,15);
	insert(&root,13);
	insert(&root,17);
	insert(&root,16);
	insert(&root,19);
	insert(&root,18);
	insert(&root,25);
	insert(&root,26);
	printf("\n");
	traverse_inorder(root);
	if(search_bst(root,30)==1)
		printf("\nThe Number is Found");
	else
		printf("\nThe Number is not Found");
	delete(&root,26);
	printf("\n");
	traverse_inorder(root);
	delete(&root,17);
	printf("\n");
	traverse_inorder(root);
	return 0;
}
