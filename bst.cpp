/*
 * bst.cpp
 *
 *  Created on: Oct 17, 2022
 *      Author:  Tommy Haskell
 */


#include "bst.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

bst::bst(){ // empty constructor
	root = NULL;
}


bst::bst(string f, string l, int n, string j){ // constructor that forms the root
	root = new bstNode( f,l, n, j);
}

void bst::clearTree() { //clears out an old tree
	if (root == NULL){
		cout << "Tree already empty" << endl;
	}else{
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}

void bst::clearTree(bstNode *tmp) {
	if (tmp == NULL){
		return;
	}else{
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode();
		delete(tmp);
	}
}


bool bst::insert(string f, string l, int n, string j){
	if(root == NULL){
		bstNode *temp = new bstNode(f,l,n,j);
		root = temp;
		return true;
	}else{
		bstNode *temp = root;
		bstNode *newNode = new bstNode(f,l,n,j);
		while(temp != NULL){
			if(l != temp->student->last){ //Branch for if last names are not the same
				if(l < temp->student->last){ //When new node is higher in alphabetical order
					if(temp->left == NULL){
						temp->left = newNode;
						newNode->parent = temp;
						setHeight(newNode->parent);
						return true;

					}else{
						temp = temp->left;
					}
				}else if(l > temp->student->last){ //When new node is lower in alphabetical order
					if(temp->right == NULL){
						temp->right = newNode;
						newNode->parent = temp;
						setHeight(newNode->parent);
						return true;
					}else{
						temp = temp->right;
					}
				}

			}else if(l == temp->student->last){ //Branch for if last names are the same

				if(f < temp->student->first){ //When new node is higher in alphabetical order
					if(temp->left == NULL){
						temp->left = newNode;
						newNode->parent = temp;
						setHeight(newNode->parent);
						return true;

					}else{
						temp = temp->left;
					}
				}else if(f > temp->student->first){ //When new node is lower in alphabetical order
					if(temp->right == NULL){
						temp->right = newNode;
						newNode->parent = temp;
						setHeight(newNode->parent);
						return true;
					}else{
						temp = temp->right;
					}
												//Branch for when last AND first names are the same
				}else if(f == temp->student->first){//if the name is completely the same and it is a leaf of the tree
					cout << "This person has already been entered into the tree." << endl;
					return true;
				}
			}
		}
		return false;
	}
}

bstNode * bst::find(string l, string f){
	if(root==NULL){
		cout << "tree is empty." << endl;
		return NULL;
	}else{
		bstNode *temp = root;
		int depth = 0;
		while(temp != NULL){
			if(temp->student->last == l){ //checks if last name is same
				if(temp->student->first == f){ //checks if first name is same
					temp->printNode();
					cout << "Found in  " << depth << " comparisons" << endl;
					return temp;
				}else if(temp->student->first > f){ //Now compares first names to find which way to go since not same
					temp = temp->left;
				}else{
					temp = temp->right;
				}

			}else if(temp->student->last > l){ //if desired last name is first alphabetically
				temp = temp->left;
			}else{
				temp = temp->right;
			}
			depth++;

		}
		cout << "data not found." << endl;
		return NULL;

	}
}

void bst::printTreeIO(){
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}
void bst::printTreeIO(bstNode *n){
	if(n==NULL){
		return;
	}else{
		printTreeIO(n->left);

		n->printNode();

		printTreeIO(n->right);
	}

}


void bst::printTreePre() {
	if (root == NULL) {
		cout << "Empty Tree" << endl;
	}else{
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}
void bst::printTreePre(bstNode *n){
	if(n==NULL){
		return;
	}else{
		n->printNode();

		printTreePre(n->left);

		printTreePre(n->right);
	}

}


void bst::printTreePost(){
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}else{
		cout << endl<<"Printing Post Order:" <<endl;
		printTreePost(root);
	}
}
void bst::printTreePost(bstNode *n){
	if(n==NULL){
		return;
	}else{

		printTreePost(n->left);

		printTreePost(n->right);

		n->printNode();
	}

}


void bst::setHeight(bstNode *n){
	bstNode *temp = n;
	while(temp->parent!=NULL){
		if(temp->right == NULL && temp->left == NULL){
			temp->height = 1;
		}else if(temp->right == NULL){
			temp->height = temp->left->height + 1;
		}else if(temp->left == NULL){
			temp->height = temp->right->height + 1;
		}else if(temp->left->height > temp->right->height){
			temp->height = temp->left->height + 1;
		}else if(temp->right->height > temp->left->height){
			temp->height = temp->right->height + 1;
		}
		temp = temp->parent;
	}
}

bstNode * bst::removeNoKids(bstNode *tmp){
	//Finds if this node is a left child or a right child
	if(tmp->parent->left==tmp){
		tmp->parent->left = NULL;
	}else{
		tmp->parent->right = NULL;
	}

	//deletes the desired node and saves it to a new temporary node so it can be returned
	bstNode *returnV = tmp;
	delete(tmp);
	return returnV;

}

bstNode * bst::removeOneKid(bstNode * tmp, bool leftFlag){

	//Finds if this node is a left child or a right child AND links parent to tmp node's kid.

	//Node being deleted is a LEFT child
	if(tmp->parent->left==tmp){
		if(leftFlag){
			tmp->parent->left = tmp->left;
			tmp->left->parent = tmp->parent;
		}else{
			tmp->parent->left = tmp->right;
			tmp->right->parent = tmp->parent;
		}
	}else{
		//Node being deleted is a RIGHT child
		if(leftFlag){
			tmp->parent->right = tmp->left;
			tmp->left->parent = tmp->parent;
		}else{
			tmp->parent->right = tmp->right;
			tmp->right->parent = tmp->parent;
		}
	}
	//deletes the desired node and saves it to a new temporary node so it can be returned
	bstNode *returnV = tmp;

	delete(tmp);
	return returnV;
}

bstNode * bst::remove(string f, string l){
	bstNode *nodeRemoving = find(f,l);

	if(nodeRemoving->left == NULL && nodeRemoving->right == NULL){
		//removes and returns the found node which has ZERO children
		bstNode *tmp = nodeRemoving->parent;
		bstNode *ans = removeNoKids(nodeRemoving);
		setHeight(tmp);
		return ans;
	}else if((nodeRemoving->left != NULL && nodeRemoving->right == NULL)||(nodeRemoving->left == NULL && nodeRemoving->right != NULL)){
		//removes and returns the found node which has ONE children
		if(nodeRemoving->left!=NULL){
			//return removeOneKid(nodeRemoving,true);
			bstNode *tmp = nodeRemoving->parent;
			bstNode *ans = removeOneKid(nodeRemoving,true);
			setHeight(tmp);
			return ans;
		}else{
			//return removeOneKid(nodeRemoving,false);
			bstNode *tmp = nodeRemoving->parent;
			bstNode *ans = removeOneKid(nodeRemoving,false);
			setHeight(tmp);
			return ans;
		}
	}else{
		//node being removes has TWO children
		//using the rightmost of the left child of node being removed as replacement
		bstNode *tmp = nodeRemoving->left;


		bstNode *returnV = nodeRemoving;
		while(tmp->right != NULL){
			tmp = tmp->right;
		}
		bstNode *tmp2 = tmp;

		//replaces node being removed with replacement
		nodeRemoving->printNode();
		nodeRemoving->left->printNode();



		nodeRemoving->student = tmp->student;



		//REMOVING REPLACEMENT NODE
		tmp->printNode();
		if(tmp->parent == nodeRemoving){
			tmp2 = tmp->parent;
			removeNoKids(tmp);

		}else if(tmp->left != NULL){
			removeOneKid(tmp,true);
		}else{
			removeNoKids(tmp);
		}
		setHeight(tmp2);
		return returnV;
	}
}
//
