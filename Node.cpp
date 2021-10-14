#include"Node.h"
void Node::setnval(int v)
{
	nval = v;
}

void Node::setcval(char c)
{
	cval = c;
}

int Node::getnval()
{
	return nval;
}

char Node::getcval()
{
	return cval;
}

Node* Node::getrchild()
{
	return rchild;
}

Node* Node::getlchild()
{
	return lchild;
}

void Node::setlchild(Node* l)
{
	lchild = l;
}

void Node::setrchild(Node* r)
{
	rchild = r;
}

Node::Node()
{
	nval = 0;
	cval = 0;
	lchild = nullptr;
	rchild = nullptr;
}

void Node::remove()
{
	if (lchild)
		lchild->remove();
	else
		delete lchild;
	if (rchild)
		rchild->remove();
	else
		delete rchild;
	return;
}
