#include<iostream>
#include<iostream>
#include <string>
#include "riyamap1.h"
using namespace std;

int main(){
	riyamap1<int> map(0.5);
	int val = 10;
	for(int i=0;i<val;i++){
		char k = ' ' + i;
		string key ="abc";
		key = key + k;
		int value = (i+1)*2;
		cout<<"inserting value = "<<value<<" | ";
		map.insert(key,value);
		cout<<"Size : "<<map.size()<<" | ";
		cout<<"Loading Factor : "<<map.loadingfactor()<<endl;
	}
	cout<<endl;
	for(int i=0;i<val;i++){
		char k = ' ' + i;
		string key ="abc";
		key = key + k;
		cout<<"Index : "<<map.getindex(key)<<" | ";
		cout<<key<<" : "<<map.getvalue(key)<<endl;
	}
	return 0;
}
