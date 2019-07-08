#include <iostream>

#include "btree.h"

using namespace std;

int main(int argc, char *argv[]) {
  BTree<int> *tree = new BTree<int>(3); 

	tree->insert(10);
	tree->insert(20);
	tree->insert(40);
	tree->insert(50);
	tree->insert(30);
	tree->insert(60);

	return EXIT_SUCCESS;
}
