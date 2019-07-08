#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class BTree;

template <typename T>
class Node {
  public:
		typedef vector<Node<T>*> kvector;
		typedef typename kvector::iterator kiterator;

			Node(unsigned int size, bool isLeaf = true) : size(size), isLeaf(isLeaf) {}

			Node(T data, bool isLeaf = true) : data(data), isLeaf(isLeaf)	{}
			
			int	getKeysSize() { return keys.size(); }

			void sort() {
				std::sort(keys.begin(), keys.end(), [](Node<T> *a, Node *b) {
					return a->data < b->data;
					}
				)	;
			}


			bool insertKey(Node<T> *node) {
				//if (find_node(node->data) != nullptr) return false;
				if (keys.size() == 0) {
					keys.push_back(node);
					return true;
				}

				if (keys.size() > size) {
					Node<T> *tmp = this;
					int i = keys.size() - 1;
				
					if (tmp->isLeaf) {
						while (i >= 0 && keys[i]->data > node->data) {
							keys[i + 1] = keys[i];
							i--;
						}
					}

					keys[i+1] = node;

				}

				keys.push_back(node);
				
				if (keys.size() == size) sort();

				return true;
			}


			Node<T>* find(int pos) {
				int counter = 0;

				for (kiterator it = keys.begin(); it < keys.end(); it++) {
					if (counter == pos) return *it;
					counter++;
				}

				return nullptr;
			}


			Node<T>* find_node(T value) {
				Node<T> *tmp = this;
				int i = keys.size() - 1;
				
				if (tmp->isLeaf) {
					while (i >= 0 && keys[i] > value) {
						keys[i + 1] = keys[i];
						i--;
					}
					
				}

				return nullptr;

			}



			Node<T>* split() {
				int split_size = size / 2;
				
				Node<T> *tmp = find(split_size);
				tmp->isLeaf = false;
				
				int counter = 0;

				for(kiterator it = keys.begin(); it < keys.end(); it++) {
					if (counter < split_size) tmp->left_childs.push_back(*it);

					if (counter > split_size) tmp->right_childs.push_back(*it);

					counter++;
				}

				return tmp;
			}



			void print() {
				for (kiterator it = keys.begin(); it < keys.end(); it++) 
					std::cout << (*it)->data << '\n';
			}


			
    friend class BTree<T>; 

	private:
	  unsigned int size;
		T data;
    kvector keys;
		kiterator ik;
    kvector left_childs;
		kvector right_childs;
    bool isLeaf;


};

#endif
