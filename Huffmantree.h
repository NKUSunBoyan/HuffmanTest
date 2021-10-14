#pragma once
#include"Node.h"
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
class Huffmantree {
private:
	
	
	int* charnums;
	string* char2codeslist;
	vector<vector<bool>> codeslist;
public:
	
	Node* root;
	vector<bool> getcode(char a);
	char code2char(vector<bool> files,int&s);
	void count(char a);
	void build();
	void buildchar2codeslist(Node*ptr,string code);
	void buildcodeslist();
	string getstringcodes(char a);
	int getnums(char a);
	Huffmantree();
	~Huffmantree();
};