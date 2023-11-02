#include "btree.hpp"


int main()
{
	btree* Root = (btree*)malloc(sizeof(btree));
	Root->root = get_node();

    while(true)
	{
	  cout << "1.insert \n3.print \n7.BPprint \n0.exit \n";
	  int choice = -1;
    //   while(choice <= 0 && choice >= 5)
	  cin >> choice;

	  if(choice == 1)
	  {
         int in ;
		 cin >> in;
		 BPinsert(in,Root);
	  }
	  else if(choice == 3)
	  {
		  cout << "your tree\n" << " --------------------------- \n";
          print_node(Root->root);
		  cout << " --------------------------- \n";
	  }
	  else if (choice == 7)
	  {
		  cout << "your tree\n" << " --------------------------- \n";
		  BPprint_node(Root->root);
		  cout << " \n--------------------------- \n";
	  }

	  
	  else if (choice == 0) {
		  return 0;
	  }
	}

}


