/*
 * bstNode.hpp
 *
 *  Created on: Oct 17, 2022
 *      Author: tommyhaskell
 */

#ifndef BSTNODE_HPP_
#define BSTNODE_HPP_
#include <iostream>
#include <stdlib.h>
#include "Student.hpp"


class bstNode{
	friend class bst;
	bstNode *left;
	bstNode *right;
	bstNode *parent;
	int height;
	Student *student;

public:
	bstNode();
	bstNode(string first, string last, int favNum, string joke);
	~bstNode();
	void printNode();



};




#endif /* BSTNODE_HPP_ */
