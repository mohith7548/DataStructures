#include<bits/stdc++.h>
using namespace std;
struct BstNode{
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* GetNewNode(int data){
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left=newNode->right=NULL;
	return newNode;
}

BstNode* Findmin(BstNode* root){
	while(root->left!=NULL) root=root->left;
	return root;
}

BstNode* Insert(BstNode* root,int data){
	if(root==NULL){
		root = GetNewNode(data);
		return root;
	}
	else if(data < root->data){
		root->left = Insert(root->left,data);
	}
	else if(data > root->data) {
		root->right = Insert(root->right,data);
	}
	return root;

}

BstNode* Search(BstNode* root,int data){
	if(root==NULL) return root;
	else if(root->data == data) return root;
	else if(data <= root->data)  root->left=Search(root->left,data);
	else root->right=Search(root->right,data);
}

BstNode* Delete(BstNode* root,int data){
	if(root==NULL) return root;
	else if(data < root->data) root->left = Delete(root->left,data);
	else if(data > root->data) root->right = Delete(root->right,data); 
	else{
		if(root->left==NULL && root->right==NULL){
			delete root;
			root=NULL;
		}
		else if(root->left == NULL){
			BstNode* temp=root;
			root=root->right;
			delete temp;
		}
		else if(root->right == NULL){
			BstNode* temp=root;
			root=root->left;
			delete temp;
		}
		else{
			BstNode* temp = Findmin(root->right);
			root->data=temp->data;
			root->right=Delete(root->right,temp->data);
		}
	}
	return root;
}

void Inorder(BstNode* root){
	if(root==NULL) return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}

int FindlengthRoot(BstNode* root,int key,int length){
	if(key == root->data) {
		return length;
	}
	else if(root == NULL){
		cout<<key<<" Element Not Found"<<endl;
		return 0;
	}
	else if(key < root->data){
		length++;
		return FindlengthRoot(root->left,key,length);
	}
	else if(key > root->data){
		length++;
		return FindlengthRoot(root->right,key,length);
	}
}

BstNode* FindLength(BstNode* root,int key1,int key2){
	int length=0;
	if(key1 < root->data && key2 < root->data || key1 > root->data && key2 > root->data){
		cout<<"Length = "<<abs(FindlengthRoot(root,key1,length)-FindlengthRoot(root,key2,length));
	}
	else if(key1 > root->data && key2 < root->data || key1 < root->data && key2 > root->data){
		cout<<"Length = "<<FindlengthRoot(root,key1,length)+FindlengthRoot(root,key2,length);
	} 
	return root;
}

BstNode* display(BstNode* ptr,BstNode* root, int level)
{
    int i;
    if (ptr != NULL)
    {
        ptr->right=display(ptr->right,root, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
		}
        cout<<ptr->data;
        ptr->left=display(ptr->left,root, level+1);
    }
}

int height(BstNode* root){
	int h=0;
	if(root!=NULL){
		int left_height = height(root->left);
		int right_height= height(root->right);
		int max_height = (left_height > right_height)?  left_height : right_height;
		h = max_height+1;
	}
	return h;
}

void PrintChild(BstNode* root){
 	if(root->left !=NULL && root->right !=NULL)  cout<<root->left<<" "<<root->right<<" ";
	else if(root->left ==NULL && root->right !=NULL)  cout<<root->right<<" ";
	else if(root->left !=NULL && root->right ==NULL)  cout<<root->left<<" ";
}

void LevelOrder(BstNode* root1,BstNode* root2){
	while(root1!=NULL || root2!=NULL){
		PrintChild(root1);
		PrintChild(root2);
		root1=root->

	}	
	return;
}

int main(){
	BstNode* root=NULL;
	int choice;
	int data;
	while(1){
		cout<<"\n``````Operations on Binary Search Tree````````"<<endl;
		cout<<"``````````````````````````````````````````````"<<endl;
		cout<<"1.Insert\n2.Delete\n3.Search\n4.Inorder\n5.Distance b/w two Nodes\n6.Display\n7.Level Order Traversal\n"<<endl;
		cout<<"``````````````````````````````````````````````"<<endl;
        cout<<"Enter your choice\n";
        cin>>choice;
        switch(choice){
        	case 1:
        			{cout<<"\nEnter data\n";
        			cin>>data;
        			root=Insert(root,data);}
        			break;
        	case 2: 
        			{cout<<"\nEnter data\n";
        			cin>>data;
        			root=Delete(root,data);}
        			break;
        	case 3:
        			{cout<<"\nEnter data to Search for:\n";
        			cin>>data;
        			BstNode* temp=GetNewNode(data);
        			if(temp==Search(root,data)) cout<<"Found!"<<endl;
        			else cout<<"Not Found!\n";}
        			break;
        	case 4:
        			{cout<<"\nInorder Traversal of the tree is:\n";
        			Inorder(root);}
        			break;
        	case 5:
        			{cout<<"\nEnter two Nodes:\n";
        			int key1,key2; cin>>key1>>key2;
        			root=FindLength(root,key1,key2);}
        			break;
        	case 6:
        			{root=display(root,root,1);}
        			break;
        	case 7:
        			{cout<<"\nLevel order Traversal of the tree is:\n";
        					cout<<root->data<<" "<<root->left->data<<" "<<root->right->data<<" ";
        				LevelOrder(root->left,root->right);}
        			break;
        	default:
        			return 0;

        }
	}
}
