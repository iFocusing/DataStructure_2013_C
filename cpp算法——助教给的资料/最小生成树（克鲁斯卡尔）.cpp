#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

typedef struct  info{
	int vexA;
	int vexB;
	int weight;
}info;


vector<info> v;
vector<info> result;
map<int,info> m;
set<int> s;

char * a[] = {"162135","062543","0115465435","052552","132656","462432"};
char b[]="ABCDEF";
#define N 6


void initMap(){
	char * temp = NULL;
	int vexA,vexB,weight,key;
	int t;
	info fo;
	for(int i = 0;i<N;i++){
		temp = a[i];
		while(*temp !='\0'){
			vexA = i;
			vexB = *temp-'0';
			temp++;
			weight = *temp-'0';
			temp++;
			if(vexA>vexB){t = vexA;vexA = vexB; vexB = t;}
			key = 100*vexA + vexB;
			fo.vexA = vexA;
			fo.vexB = vexB;
			fo.weight = weight;
			m.insert(make_pair(key,fo));	
		}	
	}	
}

bool lessThan(info i1, info i2){
	return i1.weight<i2.weight;	
}

void initVector(){
	map<int ,info>::iterator it = m.begin();
	info fo;
	while(it != m.end()){
		fo= it->second;
		v.push_back(fo);
		it++;
	}
	sort(v.begin(),v.end(),lessThan);	
}

void printVector(){
	vector<info>::iterator it = v.begin();
	while (it != v.end()){	
		cout<< it->vexA<<" "<<it->vexB<<" "<<it->weight<<endl;
		it++;	
	}	
}

void printMap(){
	map<int ,info>::iterator it = m.begin();
	info fo;
	while(it != m.end()){
		fo= it->second;
		cout<< fo.vexA<<" "<<fo.vexB<<" "<<fo.weight<<endl;
		it++;
	}	
}


int u[6]= {-1,-1,-1,-1,-1,-1};

int  find2(int vex){
	if(u[vex]==-1)
		return vex;
	else return find2(u[vex]);	
}

int setUnion(int vexA ,int vexB){
	u[find2(vexB)] = vexA;	
}

void computer(){
	vector<info>::iterator it = v.begin();
	info n;
	int vexA,vexB,weight;

	int i = 0;
	while(i<N-1){
		n = *it;
		vexA = n.vexA;
		vexB = n.vexB;
		if(find2(vexA)!=find2(vexB)){
			setUnion(vexA,vexB);
			result.push_back(n);
			i++;	
		}		
		it++;	
	}	
}

void printResult(){
	vector<info>::iterator it = result.begin();
	while(it != result.end()){
		cout<<it->vexA<<" "<<it->vexB<<" "<<it->weight<<endl;	
		it++;
	}	
}



int main(){
	initMap();
	printMap();
	cout<<endl;
	initVector();
	printVector();
	cout<<endl;
	computer();
	printResult();
	system("pause");

}
