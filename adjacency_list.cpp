//GRAPHS CREATION AND TRAVERSALS
#include <iostream>
using namespace std;
# define MAX 10
class Node
{
	public:
    	int data;
    	Node *next;
};

class queue
{
	int q[MAX];
	int front=-1,rear=-1;
	public:
		void insert(int n)
		{
			if(front==-1)
			{
				front++;
				q[front]=n;				
			}
	
			if(rear==999)
			{
				cout<<("\nQueue overflow\n");
			}
		
			rear++;
			q[rear]=n;
		}
		
	
		int delete1()
		{
			int i;
			if(front==-1 && rear==-1)
			{
				cout<<("\nQueue Underflow\n");
			}
		
			if(front!=-1 && front==rear)
			{
				i=q[front];
				front=-1;
				rear=-1;
				return i;
			}
		
			return q[front++];
		}
		
		int isempty()
		{
			if(front==-1 && rear==-1)
			return 1;
			else
			return 0;
		}
	
}qu;

class stack
{
	int st[MAX];
	int top=-1;
	public:
		void push(int s)
		{
			if(top==MAX-1)
			{
				cout<<"\nOverflow";
			}
			else{
				st[++top]=s;	
			}
		}
		
		int pop()
		{
			if(top==-1)
			{
				cout<<"\nUnderflow";
				return 0;
			}
			else
			{
				return st[top--];
			}
	
		}
		void display()
		{
			int i;
			cout<<"\nStack:\n";
			for(i=top;i!=-1;i--)
			cout<<st[i];
		}
		int isfull()
		{
			if(top==MAX)
			return 1;
			
			else 
				return 0;
		}
		
		int isempty()
		{
			if(top==-1)
			return 1;
			else
			return 0;
		}
}s;

class List:public Node
{
	public:
    	Node *listptr,*temp;
};
int visited[10];

class Graph
{
  	public:
        int V;
        List* array;
       
        Graph(int n)
        {
            V = n;
            array = new List [V];
            for (int i = 0; i < V; ++i)
			{
            	array[i].listptr = NULL;
            	array[i].temp = NULL;
            	visited[i]=0;            
			}         
        }
        void create(int current,int nextnode);
        void DFS(int v);
        void BFS(int v);
        void display();
};

void Graph::create(int current, int nextnode)
{
	Node *newnode = new Node;  
	newnode->data = nextnode ;
    newnode->next = NULL;
    if(array[current].listptr==NULL)
    {
      	array[current].listptr=array[current].temp=newnode;
    }
    else
    {
        array[current].temp->next=newnode;
        array[current].temp=array[current].temp->next;
    }
           
	newnode = new Node;
    newnode->data = current;
    newnode->next = NULL;
    if(array[nextnode].listptr==NULL)
    {
      	array[nextnode].listptr=array[nextnode].temp=newnode;
    }
    else
    {
   	    array[nextnode].temp->next=newnode;
        array[nextnode].temp=array[nextnode].temp->next;
    }
}

void Graph::display()
{
	for (int i=0;i<V;i++)
    {
    	Node *temp1 = array[i].listptr;
        cout<<"\nlist of vertex "<<i<<" ";
        while(temp1)
        {
            cout<<"-> "<<temp1->data;
            temp1 = temp1->next;
        }
        cout<<"\n";
    }
}

void Graph::DFS(int v)
{
	Node *temp1=array[v].listptr,*temp2=array[v].listptr;
	visited[v]=1;
	int x,y,i,count=0;
	cout<<" "<<v;
			
	do
	{
		x=0;
		for(temp2=array[v].listptr;temp2;temp2=temp2->next,x++);
		s.push(v);
		for(y=0,temp1=array[v].listptr;temp1;temp1=temp1->next,y++)
		{
			if(visited[temp1->data]==0)
			{
				cout<<" "<<temp1->data;
				visited[temp1->data]=1;
				s.push(temp1->data);
				break;
			}					
			if(x-1==y)
			{
				s.pop();
			}				
		}
		v=s.pop();
		for(i=0;i<V;i++)
		{
			if(visited[i]==1)
			{
				++count;
			}
		}
		if(s.isempty()==1 && count==V-1)
		{
			s.push(v);
		}
	}while(s.isempty()!=1);
}

void Graph::BFS(int v)
{
	for(int i=0;i<V;i++)
	{
		visited[i]=0;
	}
	Node *temp1=array[v].listptr;
	visited[v]=1;
	int d;
	qu.insert(v);
	while(qu.isempty()!=1)
	{
		d=qu.delete1();
		cout<<" "<<d;
		for(temp1=array[d].listptr;temp1;temp1=temp1->next)
		{
			if(visited[temp1->data]!=1)
			{		
				qu.insert(temp1->data);
				visited[temp1->data]=1;
			}
		}
	}
}
int main()
{
    int s,r;
	char ch,c='y';
	int choice=0,no;
	cout<<"\nEnter number of elements in the graph: ";
	cin>>no;
    Graph g(no);
      	
   	while(c!='n'||c!='N')
	{
		cout<<"Enter \n1.CREATION OF ADJACENCY LIST \n2.DFS TRAVERSAL \n3.BFS TRAVERSAL \n4.EXIT \nEnter your choice: ";
   		cin>>choice;
   		switch(choice)
   		{
   			case 1: cout<<"\nCreate Adjacency Linked list: \n";
				    do
				    {
				    	cout<<"\nStarting node : ";
				   		cin>>s;
				  		cout<<"\nConnection : ";
				   		cin>>r;
				  		g.create(s,r);		   		
		   				cout<<"\nDo you want to enter more nodes?(Y/N) :: ";
						cin>>ch;
					}while(ch=='y'||ch=='Y');
					g.display();
					break;
			
			case 2: cout<<"DFS traversal is: \n";
					g.DFS(0);
					break;
			
			case 3: cout<<"BFS traversal is: \n";
					g.BFS(0);
					break;
			
			case 4: return 0;
		}
		cout<<"\nDo you want to continue(Y/N): ";
		cin>>c;
	}
	return 0;	
}
	

