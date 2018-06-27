 #include<iostream>
 #define N 6
 #include<stack>
 #include<list>
 using namespace std;
 
 //char * a= "0102032124345354";
 char * a=   "0203102124345354";
 char b[]="ABCDEF";
 typedef struct node{
		int vexA;
		int vexB;
 }node;
	
	list<node> edges;
	
	void initEdges(){
		char * temp = a;
		node n;
		while(*temp != '\0'){
			n.vexA = *temp -'0';
			++temp;
			n.vexB = *temp -'0';
			++temp;
			
			edges.push_front(n);
		}	
	}
	int indegree[N] = {0};//每个顶点的入度 
	
	void initIndegree(){
		list<node>::iterator it = edges.begin();
		while (it != edges.end()){
			indegree[it->vexB]++;
			it ++;	
		}	
	}
	
	stack<int> s;
	int check(){
		for(int i =0;i<N;i++){
			if(indegree[i]==0){
				s.push(i);
			}	
		}
		int count = 0;
		int t;
		list<node>::iterator it= NULL;
		while(!s.empty()){
			t = s.top();
			s.pop();
			cout<<t<<endl; ////////输出
			count++; 
			it = edges.begin();
			while(it != edges.end()){
				if(it->vexA == t){
					indegree[it->vexB]--;
					if(indegree[it->vexB]==0)s.push(it->vexB);					
				}
				it++;	
			}	
		}
		if(count<N) return 0;
		else return 1;		
	}
	
	int main(){
		initEdges();
		initIndegree();	
		int ok = check();
		
		cout<<"Ok:"<<ok<<endl;
		system("pause");
	}
	
	

