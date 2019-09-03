#include<bits/stdc++.h>
using namespace std;

class trienode{
public:
	bool isword;
	trienode *child[26];
	string meaning;

	trienode(){
		this->isword = false;
		for(int i = 0; i < 26; i++)
			this->child[i] = NULL;
	}

	void insert(string, string);
	bool search(string, string&);
	void takeinput();
	void print_meaning(string);
};

void trienode::insert(string key, string meaning){
	trienode *node = this;
	for(int i = 0; i < key.size(); i++){
		int ind = key[i] - 'A';
		if(node->child[ind] == NULL)
			node->child[ind] = new trienode();
		node = node->child[ind];
	}
	node->meaning = meaning;
	node->isword = true;
}

bool trienode::search(string key, string &meaning){
	trienode *node = this;
	if(!node)
		return false;

	for(int i = 0; i < key.size(); i++){
		int ind = key[i]-'A';
		node = node->child[ind];
		if(!node)
			return false;
	}

	meaning = node->meaning;
	return node->isword;
}

void trienode::print_meaning(string meaning){
	cout<<"Meaning is:\n"<<meaning<<"\n";
}

void trienode::takeinput(){
	trienode *node = this;
	string word, meaning;
	cin >> word;
	if(this->search(word, meaning)){
		this->print_meaning(meaning);
	}
	else{
		meaning = "INVALID ENTRY";
		this->print_meaning(meaning);
	}
}

int main(){
	ifstream file ("L4_P1_input1.txt");
	string line;
	trienode *head = new trienode();
	while(getline(file, line)){
		int pos = line.find(";");
		string key = line.substr(0, pos);
		string meaning = line.substr(pos+1);
		head->insert(key, meaning);
	}
	cout<<"Enter any keyword\n";
	while(1){
		head->takeinput();
		cout<<"INPUT AGAIN\n";
	}
}