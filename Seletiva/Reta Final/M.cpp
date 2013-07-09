#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define PB push_back

#define REP(i,n) for(int i=0;i<(n);i++)
#define SIZE(a) ((int)((a).size()))

struct Node {
	Node* edges[26];
	bool fim;
	Node() : fim(0) {
		REP(i,26) this->edges[i] = NULL;
	}
};

/*void initialize(Node* vertex) {
	vertex->fim=0;
	REP(i,26) vertex->edges[i] = NULL;
}*/

void addWord(Node* vertex, const string& word) {
	//cout << word << endl;
	Node* current = vertex;
	for(int i = 0; i < SIZE(word); ++i) {
		int k = word[i]-'a';
		//cout << word[i] << endl;
		if(current->edges[k] == NULL) {
			current->edges[k] = new Node();
			//initialize(current->edges[k]);
			//cout << (word[i]) << endl;
		}
		current = current->edges[k];
		if(i == SIZE(word)-1){
			current->fim=1;
		}
	}
}

char S[30];
char str[30];

void dfs (Node* vertex, int pos) {
	REP(i,26) {
		if(vertex->edges[i]!=NULL) {
			S[pos]=i+'a';
			//cout << S[pos] << endl;
			//cout << vertex->fim << endl;
			if(vertex->edges[i]->fim) {
				printf("%s",str);
				S[pos+1]='\0';
				printf("%s\n",S);
			}
			dfs(vertex->edges[i],pos+1);
		}
	}
}

void searchAndPrint (Node* vertex, const string& prefix) {
	Node* current = vertex;
	REP(i,SIZE(prefix)) {
		int x = prefix[i]-'a';
		current = current->edges[x];
		//printf("%c",x+'a');
		if(current == NULL) {
			printf("No match.\n");
			return;
		}
	}
	//cout << current->fim << endl;
	dfs(current,0);
}

Node* root;

int main () {
	int n;
	while(scanf("%d",&n)==1) {
		root = new Node();
		//initialize(root);
		REP(i,n) {
			scanf("%s",str);
			addWord(root,str);
		}
		int k;
		scanf("%d",&k);
		for(int i = 1; k--; ++i) {
			printf("Case #%d:\n",i);
			scanf("%s",str);
			searchAndPrint(root,str);
		}
	}
	return 0;
}

