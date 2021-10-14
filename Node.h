#pragma once
class Node {
private:
	int nval;
	char cval;
	Node* lchild;
	Node* rchild;
public:
	void setnval(int v);
	void setcval(char c);
	int getnval();
	char getcval();
	Node* getrchild();
	Node* getlchild();
	void setlchild(Node* l);
	void setrchild(Node* r);
	Node();
	void remove();

};
class comp{
public:
	bool operator() (Node* a, Node* b)
	{
		return a->getnval() > b->getnval();
	}
};
