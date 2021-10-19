#include "btree.hpp"

void check(node* to_split)
{
	int mid = KEY / 2;

	node* right = get_node();
	right->leaf = true;

	for (int i = mid; i < KEY; i++)
	{
		right->key_value[i - mid] = to_split->key_value[i];
		to_split->net_key--;
		right->net_key++;
	}
	right->child_pointer[0] = to_split->child_pointer[0];
	to_split->child_pointer[0] = right;//split finish

	insert(to_split, right->key_value[0]);
}

void BPnon_full_insert(int key, node* root)
{
	if (root->leaf == true)
	{
		int i = root->net_key;
		while (root->key_value[i - 1] > key && i > 0)//compare value for finding right palce
		{
			root->key_value[i] = root->key_value[i - 1];
			i--;
		}
		root->key_value[i] = key;
		root->net_key++;

		if (root->net_key == KEY) {
			check(root);
		}
	}
	else
	{
		int i = root->net_key - 1;
		while (root->key_value[i] > key && i >= 0) { i--; }
		BPnon_full_insert(key, root->child_pointer[i + 1]);
	}
}


void BPinsert(int key, btree* nodet) 
{
	BPnon_full_insert(key, nodet->root);

	while (nodet->root->parent_pointer != NULL) {
		nodet->root = nodet->root->parent_pointer;
	}
}