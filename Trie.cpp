#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	char data;
	pair<bool,string> is_last;
	unordered_map<char,Node*>children;
	Node(char d)
	{
		data = d;
		is_last.first=0;

	}
};


class Trie{
public:
	Node *root;
	Trie(){
		root=new Node('\0');
}



	Node* temp = root;
	void insert(string word,string number)
	{
		Node* temp = root;
		for(int i=0;i<word.length();i++)
		{
			char ch = word[i];
			if(temp->children.count(ch))
				temp = temp->children[ch];
			else
			{
				Node *n = new Node(ch);
				temp->children[ch]=n;
				temp = temp->children[ch];
			}
		}
		temp->is_last.first = 1;
		temp->is_last.second = number;
	}

	bool search(string word)
	{
		Node *temp= root;
		for(int i=0;i<word.length();i++)
		{
			char ch = word[i];
			if(!temp->children.count(ch))
				return false;
			else
			{
				temp = temp->children[ch];
			}
		}
		if(temp->is_last.first==1)
			return true;
		return false;
	}
	void build_words(Node *temp,string curr)
	{
		for(char c='a';c<='z';c++)
		{
			if(temp->children.count(c))
				build_words(temp->children[c],curr+temp->data);

			else
			{
				if(temp->is_last.first){
					cout<<curr+temp->data<<endl;
					return;
					}
			}
		}

	}

	void remove(string word)
	{
		Node *temp= root;
		bool ok=1;
		for(int i=0;i<word.length();i++)
		{
			char ch = word[i];
			if(!temp->children.count(ch))
				{
					ok=0;
				}
			else
			{
				temp = temp->children[ch];
			}
		}
		if(ok)
		{
			temp->is_last.first=0;
			return;
		}
		else
		{
			cout<<"Please enter a Valid Name\n";
		}
	}

	void show_recommendations(string incom_word)
	{
		bool found = 1;
		Node *temp = root;
		for(int i=0;i<incom_word.length();i++)
		{
			char ch = incom_word[i];
			if(!temp->children.count(ch))
				{
					found = 0;
				}
			else
			{
				temp = temp->children[ch];
			}
		}
		if(!found)
		{
			cout<<"Sorry person we could not find a word for you";
			return ;
		}
		else
		{
			string cpy = incom_word;
			cpy.pop_back();

			build_words(temp,cpy);
		}
	}
};
