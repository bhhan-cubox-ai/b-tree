#include<iostream>
using namespace std;

#define MaxDegree 3
#define KEY MaxDegree
#define POINTER MaxDegree+1
#define LAST MaxDegree

typedef struct tree
{
	bool leaf;
	int net_key;
	int key_value[KEY];
	struct tree* child_pointer[POINTER];
	struct tree* parent_pointer;
	
}node;
typedef struct btree
{
	node* root;
	int order;
}btree;

void check(node* to_split);
void BPnon_full_insert(int key, node* nodet);
void BPinsert(int key, btree* nodet);

node* get_node();
void split_node(node* parent);
void non_full_insert(int key,node* nodet);
void insert(node* back, int key);

void print_node(node* noode);
void BPprint_node(node* noode);
