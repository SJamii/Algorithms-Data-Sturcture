    //Binary Search Tree
     
    #include<bits/stdc++.h>
    using namespace std;
    vector<int>v;
     
    struct Node{
    	int data;
    	struct Node *left,*right;
    };
     
    struct Node *root;
     
    void insert(int val)
    {
    	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); //Memory allocation
    	newNode->data = val;
    	newNode->right = NULL;
    	newNode->left = NULL;
    	if(root == NULL)
    	{
    		root = newNode;
    		//cout<<"Root is inserted "<<val<<endl;
    	}
    	else
    	{
    		struct Node *temp = root;
    		while(1)
    		{
    			if(newNode->data <= temp->data)
    			{
    				//left 
    				if(temp->left == NULL)
    				{
    					v.push_back(temp->data);
    					temp->left = newNode;
    					break;
    				}
    				else
    				{
    					temp = temp->left;
    				}
    			}
    			else
    			{
    				//right
    				if(temp->right == NULL)
    				{
    					v.push_back(temp->data);
    					temp->right = newNode;
    					break;
    				}
    				else
    				{
    					temp = temp->right;
    				}
    				
    			}
    		}
    	}
    }
     
    int main()
    {
    	root = NULL;
    	int num; cin>>num;
    	//int ara[num+5];
    	while(num--)
    	{
    		int x;cin>>x;
    		insert(x);
    	}
    	for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    	cout<<endl;
    }
