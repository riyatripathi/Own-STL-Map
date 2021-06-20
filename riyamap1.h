#include<iostream>
#include <string> 
using namespace std;
template<typename T>
class node{
public:
	string key;
	T value;
	node *next;
	node(string key , T value){
		this->key=key;
		this->value=value;
		this->next=NULL;
	}
};
 
template<typename T>
class riyamap1{
private:
	int count;
	int bucketsize;
	double LF;
	node<T>**bucketarray;
private:
	void initialise(){
		for(int i=0;i<bucketsize;i++){
			bucketarray[i] = NULL;
		}
	}
public:
	riyamap1(){
		this->count=0;
		this->bucketsize=5;
		this->bucketarray = new node<T>*[bucketsize];
		initialise();
		this->LF=0.7;
	}
	riyamap1(double Lf){
		this->count=0;
		this->bucketsize=5;
		this->bucketarray = new node<T>*[bucketsize];
		initialise();
		this->LF=Lf;
	}

	riyamap1(int size){
		this->count=0;
		this->bucketsize=size;
		this->bucketarray = new node<T>*[bucketsize];
		initialise();
		this->LF=0.7;
	}
	riyamap1(int size,double Lf){
		this->count=0;
		this->bucketsize=size;
		this->bucketarray = new node<T>*[bucketsize];
		initialise();
		this->LF=Lf;
	}
private:
	int hashcode(string key){
		int p=37,multi=1,sum=0;
		for(int i=key.length()-1;i>=0;i--){
			sum=sum + multi*key[i];
			sum%=bucketsize;
			multi=multi*p;
			multi%=bucketsize;
		}
		return sum % bucketsize;
	}

	void rehash(){
		count = 0;
		node<T>** oldArray = bucketarray;
		int oldSize = bucketsize;
		bucketsize = 2 *(oldSize);
		bucketarray = new node<T>*[bucketsize];
		initialise();
		for(int i=0;i<oldSize;i++){
			node<T> *head = oldArray[i];
			node<T> *prev = NULL; 
			while(head != NULL){
				string k = head->key;
				T val = head->value;
				insert(k,val);
				prev = head;
				head = head->next;
				prev->next = NULL;
				delete prev;
			}
		}
		delete [] oldArray;
	}
 public:

	void insert(string key,T value){
		int index = hashcode(key);
		node<T>* temp = bucketarray[index];
		
		while(temp!=NULL){
			if(temp->key==key){
				temp->value=value;
			}
			temp=temp->next;
		}
			node<T> *newnode = new node<T>(key,value);
			 newnode->next=bucketarray[index];
			 bucketarray[index]=newnode;
			 count++;
			double lf=(1.0*count)/bucketsize;
			if(lf>LF) rehash();
	}

	int size(){
		return count;
	}

	bool find(string key){
		int index = hashcode(key);
		node<T>* temp = bucketarray[index];
		while(temp!=NULL){
			if(temp->key==key){
				return true;
			}
			temp=temp->next;
		}
		return false;
	}

	int getvalue(string key){
		int index = hashcode(key);
		node<T>* temp = bucketarray[index];
		while(temp!=NULL){
			if(temp->key==key){
				return temp->value;
			}
			temp=temp->next;
		}
		return 0;
	}


	T erase(string key){
	   int index = hashcode(key);
	   node<T>* temp = bucketarray[index];
	   node<T>* prev=NULL;
	   while(temp!=NULL){
	   	if(prev==NULL && temp->key==key){
	   		bucketarray[index]=temp->next;
	   		 T val=temp->value;
	   temp->next=NULL;
	   delete temp;
	   count--;
	   return val;
	   	}
	   	else{
	   	if(prev!=NULL&&temp->key==key){
	   		break;
	   	}
	   	prev=temp;
	   	temp=temp->next;
	   }
	}
	   T val=temp->value;
	   prev->next=temp->next;
	   temp->next=NULL;
	   delete temp;
	   count--;
	  	return val;
	}



public:

	int bucket(){
		return bucketsize;
	}

	double loadingfactor(){
		return (1.0)*count/bucketsize;
	}

	int getindex(string key){
		return hashcode(key);
	}

	void traverse(){

		for(int i=0;i<bucketsize;i++){
			node<T>*temp=bucketarray[i];
			while(temp!=NULL){
			string k=temp->key;
			T value=temp->value;
			temp=temp->next;
			cout<<"key is "<<k<<" & value is "<<value<<endl;
		}
		}
	}
};




