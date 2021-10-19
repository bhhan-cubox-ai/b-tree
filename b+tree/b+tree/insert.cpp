#include "btree.hpp"


node* get_node()
{
	node* neww = (node*)malloc(sizeof(node));
	neww->net_key = 0;
	neww->leaf = true;
	for(int i = 0 ; i< POINTER; i++)
		neww->child_pointer[i] = NULL;
	for (int i = 0; i < KEY; i++)
		neww->key_value[i] = 0;
	neww->parent_pointer = NULL;
	return neww;
}



void  split_node(node* target)
{
	int mid = KEY / 2;
	node* right = get_node();
	right->leaf = false;
	node* parent;
	int key = target->key_value[mid];
	if (target->parent_pointer == NULL) {
		parent = get_node();
		parent->leaf = false;
	}
	else { parent = target->parent_pointer; }

	int i = parent->net_key;
	while (parent->key_value[i - 1] > target->key_value[mid] && i > 0)
	{
		parent->key_value[i] = parent->key_value[i - 1];
		parent->child_pointer[i + 1] = parent->child_pointer[i];
		i--;
	}
	parent->key_value[i] = key;
	target->net_key--;
	parent->net_key++;

	parent->child_pointer[i] = target;
	target->parent_pointer = parent;
	parent->child_pointer[i+1] = right;
	right->parent_pointer = parent;
	int j;
	for (j = mid + 1; j < KEY; j++) //나눠담기
	{
		right->key_value[j - (mid + 1)] = target->key_value[j];
		target->net_key--;
		right->net_key++;
		right->child_pointer[j - (mid + 1)] = target->child_pointer[j];
		target->child_pointer[j]->parent_pointer = right;
	}
	right->child_pointer[j - (mid + 1)] = target->child_pointer[j];
	target->child_pointer[j]->parent_pointer = right;
}

void non_full_insert(int key,node* parent)
{
	//insert in right place
	int i = parent->net_key;
	while (parent->key_value[i-1] > key && i > 0)//부모노드에 입력
	{
		parent->key_value[i] = parent->key_value[i-1];
		parent->child_pointer[i + 1] = parent->child_pointer[i];
		i--;
	}
	parent->key_value[i] = key;//포인터 관리
	parent->child_pointer[i + 1] = parent->child_pointer[i]->child_pointer[0];
	parent->child_pointer[i]->child_pointer[0]->parent_pointer = parent;
	parent->net_key++;

	while (parent->net_key == KEY){
		split_node(parent);
		parent = parent->parent_pointer;
	}
   
}


void insert(node* left, int key)
{
	if (left->parent_pointer == NULL) {//처음 부모노드가 없는 상황
		node* right= left->child_pointer[0];
		node* parent = get_node();
		parent->leaf = false;
		left->parent_pointer = parent;
		right->parent_pointer = parent;

		parent->key_value[0] = key;
		parent->net_key++;
		parent->child_pointer[0] = left;
		parent->child_pointer[1] = right;
		
	}
	else 
	{
		non_full_insert(key, left->parent_pointer);
	}
} 
