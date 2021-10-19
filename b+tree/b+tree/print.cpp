#include "btree.hpp"
#include<queue>



void print_node(node* noode)
{
	queue <node*> qu;
	qu.push(noode);
	while (!qu.empty())
	{
		int count = qu.size();
		 cout <<"|| ";

		while (count > 0)
		{
			node* top = qu.front();

			for(int i = 0;i<top->net_key;i++)
			{
				cout << top->key_value[i] << " ";
			}
            
			if(!top->leaf)
			for(int i = 0;i<=top->net_key;i++)
			{
				qu.push(top->child_pointer[i]);
			}

			qu.pop();
			cout << "||" ;
			count--;
		}
		cout << endl;
	}
	return;
}

void BPprint_node(node* nodet)
{
	while (nodet->leaf==false)
	{
		nodet = nodet->child_pointer[0];
	}
	while (true){
		for (int i = 0; i < nodet->net_key; i++) {
			cout << nodet->key_value[i] <<" ";
		}

		if (nodet->child_pointer[0] != NULL)
			nodet = nodet->child_pointer[0];
		else {return;	}
	} 
}