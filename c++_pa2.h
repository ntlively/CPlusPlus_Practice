// use a header guard?
#ifndef PA2_H
#define PA2_H


struct Node{
//look up how to make constructor so you can pass data directly into the node
int kbsize;
std::string pname;
//////////////////////
//public: Node * header;
public: Node * next;	   //
////////////////////
public: void insert(int data, std::string name);

};



class LinkedList{
// do one public statement for all of the spots

////////////////////
public: Node *header;
//////////////////
public: void initialize(int data, std::string name);
//public: void insert(int data, std::string name);
public: void remove(std::string name);
public: void frag();
public: void traverse();
public: int search(std::string name);
public: void addbestp(std::string name, int size);
public: void addworstp(std::string name, int size);
};

#endif
