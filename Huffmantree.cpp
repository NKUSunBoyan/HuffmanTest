#include "Huffmantree.h"

vector<bool> Huffmantree::getcode(char a)
{
	return codeslist[int(a)];
}

char Huffmantree::code2char(vector<bool> file,int&s)
{
	char output;
	Node* ptr = root;
	while (s < file.size())
	{
		if (ptr->getcval() != 0)
		{
			output = ptr->getcval();
			return output;
		}
		else
		{
			if (file[s])
			{
				ptr = ptr->getrchild();
				s++;
			}
			else
			{
				ptr = ptr->getlchild();
				s++;
			}
		}
	}
	return 0;
}

void Huffmantree::count(char a)
{
	charnums[a]++;
}

void Huffmantree::build()
{
	priority_queue<Node*, vector<Node*>, comp> q;
	for (int i = 0; i < 128; i++)
	{
		if (charnums[i] != 0)
		{
			Node* nnode = new Node();
			nnode->setcval(char(i));
			nnode->setnval(charnums[i]);
			q.push(nnode);
		}
	}
	while (!q.empty())
	{
		Node* nnode = new Node();
		nnode->setlchild(q.top());
		q.pop();
		nnode->setrchild(q.top());
		q.pop();
		nnode->setnval(nnode->getlchild()->getnval() + nnode->getrchild()->getnval());
		if (q.empty())
		{
			root = nnode;
			break;
		}
		else
			q.push(nnode);
	}
	
}


void Huffmantree::buildchar2codeslist(Node*ptr,string code)
{
	if (ptr->getlchild() != nullptr)
	{
		buildchar2codeslist(ptr->getlchild(), code+"0");
	}
	if (ptr->getrchild() != nullptr)
	{
		buildchar2codeslist(ptr->getrchild(), code+"1" );
	}
	if (ptr->getrchild() == nullptr && ptr->getlchild() == nullptr)
	{
		char2codeslist[ptr->getcval()] = code;
		return;
	}	
}

void Huffmantree::buildcodeslist()
{
	for (int i = 0; i < 128; i++)
	{
		for (int j = 0; j < char2codeslist[i].size(); j++)
		{
			codeslist[i].push_back(char2codeslist[i][j] - '0');
		}
	}
}

string Huffmantree::getstringcodes(char a)
{
	string s = "";
	for (int i = 0; i < char2codeslist[int(a)].size(); i++)
	{
		s+=char2codeslist[int(a)][i];
	}
	return s;
}

int Huffmantree::getnums(char a)
{
	return charnums[int(a)];
}

Huffmantree::Huffmantree()
{
	root = new Node();
	charnums = new int[128];
	for (int i = 0; i < 128; i++)
	{
		charnums[i] = 0;
	}
	char2codeslist = new string[128];
	for (int i = 0; i < 128; i++)
	{
		vector<bool> v;
		codeslist.push_back(v);
	}
}

Huffmantree::~Huffmantree()
{
	delete[] char2codeslist;
	root->remove();
}
