#include <bits/stdc++.h>
using namespace std;
struct Node{
	int element;
	list<int> adjelement;
	list<int> weight;
};
class Graph{
private:
	int v;
	Node *vertex;
public:
	Graph(int k){
		v=k; 
		vertex = new Node[v];
	}
	void Addlink(int,int,int);
	int ReturnIndex(int);
	void TakeElements();
	void Dijkestra();
	void BFS(int);
	void DFS(int);
	void subDFS(int,bool[]);
};

void Graph::TakeElements(){
	cout<<"Enter "<<v<<" elements:\n";
	for(int i=0;i<v;++i){
		cin>>vertex[i].element;
	}
}

int Graph::ReturnIndex(int k){
	for(int i=0;i<v;++i){
		if(k == vertex[i].element) return i;
	}
	return -1;
}

void Graph::Addlink(int a,int b,int c){
	vertex[ReturnIndex(a)].adjelement.push_back(b);
	vertex[ReturnIndex(a)].weight.push_back(c);
}

void Graph::subDFS(int s,bool visited[]){
	for(int i=0 ; i< vertex[ReturnIndex(s)].adjelement.size() ; ++i){
		auto k=vertex[ReturnIndex(s)].adjelement.begin();
		advance(k,i);
		if(!visited[ReturnIndex(*k)]){
			visited[ReturnIndex(*k)] = true;
			cout<<*k<<" ";
			subDFS(*k,visited);
		}
	}
	return;
}

void Graph::DFS(int s){
	bool visited[v];
	for(int i=0;i<v;++i)
		visited[i] = false;
	visited[ReturnIndex(s)] = true;
	cout<<s<<" ";
	subDFS(s,visited);
	cout<<endl;
}

void Graph::BFS(int s){
	bool *visited = new bool[v];
	for(int i=0;i<v;++i)
		visited[i] = false;
	list<int> queue;
	visited[ReturnIndex(s)]= true;
	queue.push_back(s);
	list<int> :: iterator it; 
	while(!queue.empty()){
		s = queue.front();
		cout<<s<<" ";
		queue.pop_front();
		for(it = vertex[ReturnIndex(s)].adjelement.begin() ; it!=vertex[ReturnIndex(s)].adjelement.end() ; it++){
			int k= *it;
			if(!visited[ReturnIndex(k)]){
				visited[ReturnIndex(k)] = true;
				queue.push_back(k);
			}
		}
	}
	cout<<endl;
}

int main(){
	system("clear");
	cout<<"````````````This program is to implement Dijkestra's using Adajency List``````````````\n";
	cout<<"Enter no.of nodes:\n";
	int n,x,y,z;cin>>n;
	Graph g(n);
	g.TakeElements();
	while(1){
		cout<<"\n``````OPERATIONS ON GRAPH````````\n";
		cout<<"1.Addlink\n2.BFS\n3.DFS\n4.Dijkestra\n";
		cout<<"Enter your choice:\n";
		int choice;cin>>choice;
		switch(choice){
			case 1:
					cout<<"Enter two elements and their path weight\n";
					cin>>x>>y>>z;
					g.Addlink(x,y,z);
					break;
			case 2:
					cout<<"Enter an element to start traversal from:\n";
					cin>>n;g.BFS(n);
					break;
			case 3:
					cout<<"Enter an element to start traversal from:\n";
					cin>>n;g.DFS(n);
					break;
			default:
					return 0;
		}
	}
}