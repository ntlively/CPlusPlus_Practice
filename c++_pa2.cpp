#include <iostream>
#include "pa2.h"
#include <stdlib.h> 
#include <string.h>
using namespace std;
LinkedList * linklist = new LinkedList();

void Node::insert(int input, string name){
		
	kbsize = input;
	pname = name;
	}
	
void LinkedList::initialize(int input, string name){

int x=1;

if (header == NULL){
	header = new Node();
	header->kbsize=input;
	header->pname=name;

}else{

Node * temp2 = header;	
while(x==1){
	if (temp2->next == NULL){	
		temp2->next =new Node();
		temp2->next->kbsize=input;
		temp2->next->pname=name;
		x=0;
	}
	temp2=temp2->next;
}
}
}



void LinkedList::remove(string name){
	int allfree=0;
		if (header == NULL){
			cout<<"This is an empty linked list, you cannot remove any programs! \n";
			return;
		}
	
	Node * temp = header;
	
	while(temp->next != NULL){
		
		if(temp->pname==name){
			temp->kbsize=0;
			temp->pname = "Free";
			allfree=1;
			cout<<"Program: "<<name<<" removed successfully.\n";
			}
		
		temp=temp->next;
		
		}
	if(temp->next==NULL){
		if(temp->pname==name){
			temp->kbsize=0;
			temp->pname="Free";
			allfree=1;
			cout<<"Program: "<<name<<" removed successfully.\n";
			}
		}
	
	if(allfree==0){
		cout<<"There is no program of that name in the list. \n";
		}
	
	}
	
int LinkedList::search(string name){

		if (header == NULL){
			cout<<"This is an empty linked list, you cannot search any values! \n";
			return 0;
		}else{
	int n=1;
	Node * temp = header;
	
	while(temp->next != NULL){
		if(temp->pname==name){	
			cout<<"Page#"<<n<<"\n";	
			cout<<temp->pname<<"\n";
			cout<<temp->kbsize<<"\n";
			return 1;
			}
		temp=temp->next;
		n=n+1;
		}
	}
	return 0;
	}
	

void LinkedList::traverse(){

	Node * temp = header;
	
	for(int i=0;i<32;i++){			
								
		cout<<temp->pname<<": ";
		cout<<"("<<temp->kbsize<<" KB)"<<" Page: "<<i+1<<"\n";
		temp = temp->next;
	
		}
	}



void menuprint(){
	
	cout<<"1. Add program\n";
	cout<<"2. Kill program\n";
	cout<<"3. Fragmentation\n";
	cout<<"4. Print Memory\n";
	cout<<"5. Exit\n";
	
	}
	
	
void LinkedList::addbestp(string name, int size){
	int pages =0;
	if(size>4){
		pages = size/4;
		if(size%4!=0){
			pages=pages+1;
		}	
	}else{
		pages=1;
	}
	cout<<"the number of needed pages:\n"<<pages<<"\n";
	
	Node* temp= header;	
	Node* startspot= temp;	
	int spotcheck=0;
	int pagecheck=1;

if(linklist->search(name)==1){
	cout<<"That program is already running.\n";
	return;
	}
while(spotcheck!=pages){
	if(pagecheck>32 || pages>32){
		cout<<"There is not enough memory for that program\n";
		return;
		}
	if(temp->pname=="Free" && spotcheck==0){
		startspot=temp;
		spotcheck=spotcheck+1;
		if(temp->next!= NULL){	
			temp=temp->next;
		}
		if(pages==1){
			break;
		}	
	}
	
	if(temp->pname=="Free" && spotcheck>0 && pages>1){
		spotcheck=spotcheck+1;
		if(temp->next!= NULL){	
			temp=temp->next;
		}
		if(spotcheck==pages){
			break;
		}		
	}
	if(temp->pname!="Free"){
		spotcheck=0;
		if(temp->next!= NULL){	
		temp=temp->next;
		}
	}
	pagecheck=pagecheck+1;	
}
	for(int i=0;i<pages;i++){
		if(size%4==0){	
			startspot->kbsize=size/pages;
			startspot->pname=name;
			startspot=startspot->next;
		}else if(size%4!=0){
			
			if(pages==1){
				startspot->kbsize=size;
				startspot->pname=name;
			}
			else if(i<pages-1){
				startspot->kbsize=4;
				startspot->pname=name;
				startspot=startspot->next;
			}else{
				startspot->kbsize=size%4;
				startspot->pname=name;
				startspot=startspot->next;
				}
			}	
		}
		
		cout<<"Program: "<<name<<" added successfully. "<<pages<<" pages used.\n";	
}

void LinkedList::addworstp(string name, int size){
	int arr[32]={};
	int arr2[32]={};
	int arr3[32]={};
	int finalspot=0;
	int pages =0;
	int gaps=0;
	if(size>4){
		pages = size/4;
		if(size%4!=0){
			pages=pages+1;
		}	
	}else{
		pages=1;
	}
	cout<<"the number of needed pages:\n"<<pages<<"\n";
	
	Node* temp= header;	


if(linklist->search(name)==1){
	cout<<"That program is already running.\n";
	return;
	}

for(int j=0;j<31;j++){
	
	if(temp->pname=="Free"){
	arr2[j]=0;
	}
	if(temp->pname!="Free"){	
	arr2[j]=1;
	}
	temp=temp->next;
	}

	if(temp->pname=="Free"){
	arr2[32]=0;
	}
	if(temp->pname!="Free"){
	arr2[32]=1;
	}

int free=0;
int k=0;
for(int i=0;i<32;i++){
	
	if(arr2[i]==0){
		free=free+1;
		}
	if(arr2[i]==1||i==31){
		arr[k]=free;
		arr3[k]=i-free;
		free=0;
		k=k+1;
		}
	if(free==32){
		arr[k]=free;
		arr3[k]=i-free;
		}
	}

for(int i=0;i<31;i++){
	if(arr2[i]==0 && arr2[i+1]==1){
		gaps=gaps+1;
	}
}
int temps=0;

	for(int j=0; j<32;j++){
		if(arr[j]>temps){
			temps=arr[j];
			finalspot=j;		
		}
	}

if(pages>32){
		cout<<"There is not enough memory for that program\n";
		return;
		}
if(pages>temps){
	cout<<"There is not enough memory for that program\n";
	return;
	}

temp=header;

if(gaps==0){
	for(int i=0; i<=arr3[finalspot];i++){
		temp=temp->next;
	}
}
if(gaps>0){
	for(int i=0; i<arr3[finalspot];i++){
		temp=temp->next;
	}
}

for(int i=0;i<pages;i++){
		if(size%4==0){	
			temp->kbsize=size/pages;
			temp->pname=name;
			temp=temp->next;
		}else if(size%4!=0){
			
			if(pages==1){
				temp->kbsize=size;
				temp->pname=name;
			}
			else if(i<pages-1){
				temp->kbsize=4;
				temp->pname=name;
				temp=temp->next;
			}else{
				temp->kbsize=size%4;
				temp->pname=name;
				temp=temp->next;
				}
			}	
		}

cout<<"Program: "<<name<<" added successfully. "<<pages<<" pages used.\n";
	
	}		


void LinkedList::frag(){
//Please note that a fragment here is defined as any chunk of free space between two running programs
//This means that a 1kb space between programs is called 1 fragment, while a 8 kb space between programs is also 1 fragment
//This definition excludes free space from the end of the list, they are not fragments.
//This function works
	int frags=0;	
	if (header == NULL){
			cout<<"This is an empty linked list, no fragments! \n";
			return;
	}
	
	Node * temp = header;
	Node* temp2= header;
		do{	
				if(temp->kbsize<4){
					temp2=temp2->next;
					if(temp2->kbsize!=0){
						frags=frags+1;
						temp2=temp;
						}
					}
				
		temp=temp->next;
		temp2=temp;
		
	}while(temp->next!=NULL);
		if(temp->next==NULL)
				if(temp->kbsize<4 &&temp->kbsize!=0 ) {
						frags=frags+1;
					}
	cout<<"There are "<<frags<<" fragment(s).\n";	
	}	
	
void runbestmenu(int input){
	if(input==1){
		string pname;
		int psize;
		cout<<"Program name:\n";
		cin>>pname;
		//cout<<pname<<"\n";
		cout<<"Program size (KB):\n";
		cin>>psize;
		//cout<<psize<<"\n";	
		linklist->addbestp(pname, psize);	
		}	
	if(input==2){
		string pname;
		cout<<"Program name:\n";
		cin>>pname;
		linklist->remove(pname);
		}
	if(input==3){
		linklist->frag();
		}
	if(input==4){
		linklist->traverse();
		}
	if(input==5){
		exit(0);
		}
	if(input>5 || input<1){
		cout<<"Error! Your menue choice must be 1 through 5\n";
		}
	
	}	
	
void runworstmenu(int input){

	if(input==1){
		string pname;
		int psize;
		cout<<"Program name:\n";
		cin>>pname;
		//cout<<pname<<"\n";
		cout<<"Program size (KB):\n";
		cin>>psize;
		//cout<<psize<<"\n";
		linklist->addworstp(pname, psize);	
		}	
	if(input==2){
		string pname;
		cout<<"Program name:\n";
		cin>>pname;
		linklist->remove(pname);
		}
	if(input==3){
		linklist->frag();
		}
	if(input==4){
		
		linklist->traverse();
		}
	if(input==5){
		exit(0);
		}
	if(input>5 || input<1){
		cout<<"Error! Your menue choice must be 1 through 5\n";
		}
	}	



int main(int argc, char *argv[]){
	

for(int i=0;i<32;i++){			
			linklist->initialize(0, "Free");				
}
int x=1;

do{	
if(strcmp(argv[1], "worst")==0){
	int num;
	cout<<"This is a worst fit case.\n";
	menuprint();
	cout<<"Menu Choice:\n";
	cin>>num;
	runworstmenu(num);
	}
// This code checks the argument to see if it should run the best fit algorith		
if(strcmp(argv[1], "best")==0){
	int num;
	cout<<"This is a best fit case.\n";
	menuprint();
	cout<<"Menu Choice:\n";
	cin>>num;
	runbestmenu(num);
	}
// This code checks the argument to see if it is an invalid argument(not one of the above)	
else if((strcmp(argv[1], "best")!=0)&&(strcmp(argv[1], "worst")!=0)){
	cout<<"That was not a valid argument, please input best or worst\n";
}
}while(x==1);

}
