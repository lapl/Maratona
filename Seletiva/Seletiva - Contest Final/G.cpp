#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <algorithm>
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,a) FOR(i,0,a)

using namespace std;

typedef pair<int,int> PII;

int A[10010];

int last;

struct node {
	int key;
	node* left;
	node* right;
	node(int key = 0, node* left = NULL, node* right = NULL) : key(key),left(left),right(right) {}
};

node* root;

void insert(node* cur, int x) {
	if(x < cur->key) {
		if(cur->left == NULL) cur->left = new node(x);
		else insert(cur->left,x);
	}
	if(x > cur->key) {
		if(cur->right == NULL) cur->right = new node(x);
		else insert(cur->right,x);
	}
}

void preorder(node* cur) {
	if(cur == NULL) return;
	preorder(cur->left);
	preorder(cur->right);
	printf("%d\n",cur->key);
}

int main () {
	int x;
	scanf("%d",&x);
	root = new node(x); 
	for(int i = 1; scanf("%d",&x)==1; ++i) {
		insert(root,x);
	}
	preorder(root);
}

