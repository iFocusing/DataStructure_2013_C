 #include<iostream>
 #define N 9
 #include<stack>
 #include<list>
 using namespace std;
 
 //char * a= "0102032124345354";
 //char * a=   "0203102124345354";
 char *a = "016024035141241352469477574682784";
 char b[]="ABCDEFGHI";
 typedef struct node{
		int vexA;
		int vexB;
		int weight;
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
			n.weight = *temp -'0';
			++temp;
			edges.push_front(n);
		}	
	}
	int indegree[N] = {0};
	
	void initIndegree(){//计算每个顶点的入度 
		list<node>::iterator it = edges.begin();
		while (it != edges.end()){
			indegree[it->vexB]++;
			it ++;	
		}	
	}
	
	int ve[N] = {0}; //该数组中存的是最早开始时间 
	
	stack<int> s;
	stack<int> T;//拓扑序列顶点栈 
	int earlist(){
		for(int i =0;i<N;i++){//入度为0 的顶点入栈 
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
			T.push(t); ///入拓扑序列栈 
			count++; 
			it = edges.begin();
			while(it != edges.end()){
				if(it->vexA == t){
					indegree[it->vexB]--;
					if(indegree[it->vexB]==0)s.push(it->vexB);					
					if(ve[t]+it->weight >ve[it->vexB])
						ve[it->vexB] =  ve[t]+it->weight;
				}
				it++;	
			}	
		}
		if(count<N) return 0;
		else return 1;		
	}
	
	void printVE(){//输出最早开工时间 
		for(int i =0;i<N;i++)
			cout<<ve[i]<<" ";		
	}
	
	int vl[N] = {0};
	void initVL(){
		for(int i =0;i<N;i++){
			vl[i] = ve[N-1];	
		}	
	}
	int  latest(){
		initVL();//初始化最迟开工时间 
		list<node>::iterator it= NULL;
		  while(!T.empty()){
				int t = T.top();
				T.pop();
				it = edges.begin();
				while(it != edges.end()){
				   if(it->vexA == t){
							if(vl[it->vexB]- it->weight <vl[t])
								vl[t] = vl[it->vexB] - it->weight;
						}
						it++;	
				}
				
			}
	}
	
		void printVL(){//输出最迟开工时间 
		for(int i =0;i<N;i++)
			cout<<vl[i]<<" ";		
	}
	
	int main(){
		initEdges();
		initIndegree();	
		int ok = earlist();
		
		cout<<"Ok:"<<ok<<endl;
		printVE();
		cout<<endl;
		latest();
		printVL();
		system("pause");
		return 0;
	}
	
//图的关键路径	

