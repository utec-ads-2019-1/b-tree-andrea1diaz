#ifndef BTREE_H
#define BTREE_H

#include "node.h"
#include <assert.h>
#include <stdexcept>

using namespace std;

#ifndef NDEBUG
#   define ASSERT(condition, message) \
    do { \
        if (! (condition)) { \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": " << message << std::endl; \
            std::terminate(); \
        } \
    } while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif


template <typename T>
class BTree {
    private:
        Node<T>* root;
        unsigned int degree;
				unsigned int keys;

    public:
        BTree(unsigned int degree) : degree(degree), root(nullptr) {
					ASSERT (degree % 3 == 0, "ERROR: degree not valid");

					keys = 2 * degree - 1;

					Node<T> *node = new Node<T>(keys);
					root = node;
				}


        bool search(T k) { 
          if (root->find_node(k)) return true;

					else return false;
        } 


        bool insert(T k) {
					Node<T> *node = new Node<T>(k);

						Node<T> *tmp = root;

						if (tmp->getKeysSize() < keys) {
							tmp->insertKey(node);
							return true;
						}

						else {
							tmp->split();
							root = tmp;
							tmp->insertKey(node);
						}


					return false;
        }

        bool remove(int k) {
					
        }

        void print() {
            // TODO
        }

        ~BTree();
};

#endif
