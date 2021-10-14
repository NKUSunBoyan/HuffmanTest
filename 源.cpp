#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include"Node.h"
#include"Huffmantree.h"
using namespace std;
int main()
{
	fstream inputfile1;
	inputfile1.open("inputfile1.txt", ios::in);
	Huffmantree tree;
	char a;
	vector<bool> v;
	while (inputfile1.peek()!=EOF)
	{
		inputfile1.get(a);
		tree.count(a);
	}
	tree.build();
	string ss;
	tree.buildchar2codeslist(tree.root,ss);
	tree.buildcodeslist();
	inputfile1.close();
	fstream inputfile2;
	inputfile2.open("inputfile2.txt", ios::in);
	fstream outputfile;
	outputfile.open("outputfile.dat", ios::out | ios::binary);
	while (inputfile2.peek() != EOF)
	{
		char a;
		inputfile2.get(a);
		vector<bool> vi = tree.getcode(a);
		for (int i = 0; i < vi.size(); i++)
		{
			v.push_back(vi[i]);
		}
	}
	int readi = 0;
	int readj = 0;
	for (readi = 0; readi < (v.size()-v.size()%8); readi+=8)
	{
		char a = 0;
		for (readj = 0; readj < 8; readj++)
		{
			a += char(v[readi+readj]) << (7-readj);
		}
		outputfile<<a;
	}
	char tail = 0;
	for (int i = 0; i < 8; i++)
	{
		tail += char(v[i+readi-8]) << (8 - i);
	}
	outputfile << tail;
	vector<bool> voo;
	outputfile.close();
	fstream outputfile3;
	outputfile3.open("outputfile.dat", ios::binary | ios::in);
	int ofend = 0;
	outputfile3.seekg(0, ios::end);
	ofend = outputfile3.tellg();
	outputfile3.seekg(0, ios::beg);
	while (outputfile3.tellg() != ofend)
	{
		char buffer = 0;
		outputfile3.get(buffer);
		for (int i = 7; i >=0; i--)
		{
			voo.push_back((unsigned int(buffer)) & (1 << i));
		}
	}
	outputfile3.close();
	fstream outputfile2; 
	outputfile2.open("outputfile2.txt", ios::out);
	int s = 0;
	while (s < (voo.size() - 8))
	{
		char t=tree.code2char(voo, s);
		outputfile2 << t;
	}
	outputfile2.close();
	fstream outputfile1;
	outputfile1.open("outputfile1.txt", ios::out);
	for (int i = 0; i < 128; i++)
	{
		if (tree.getstringcodes(char(i)) == "")
			continue;
		else
		{
			outputfile1 << char(i) << ": " <<setw(8)<<tree.getnums(char(i)) <<"times. "<< endl;
			outputfile1 << "Huffman code of " <<char(i)<<": "<< tree.getstringcodes(char(i)) << endl;
		}
	}
	outputfile1.close();
	return 0;
}