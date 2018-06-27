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
	
	void initIndegree(){//����ÿ���������� 
		list<node>::iterator it = edges.begin();
		while (it != edges.end()){
			indegree[it->vexB]++;
			it ++;	
		}	
	}
	
	int ve[N] = {0}; //�������д�������翪ʼʱ�� 
	
	stack<int> s;
	stack<int> T;//�������ж���ջ 
	int earlist(){
		for(int i =0;i<N;i++){//���Ϊ0 �Ķ�����ջ 
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
			cout<<t<<endl; ////////���
			T.push(t); ///����������ջ 
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
	
	void printVE(){//������翪��ʱ�� 
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
		initVL();//��ʼ����ٿ���ʱ�� 
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
	
		void printVL(){//�����ٿ���ʱ�� 
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
	
//ͼ�Ĺؼ�·��	

