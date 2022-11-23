/*
 * bstNode.cpp
 *
 *  Created on: Oct 17, 2022
 *      Author: tommyhaskell
 */
#include <stdlib.h>
#include <iostream>
#include "bstNode.hpp"
using namespace std;

bstNode::bstNode(){
	left = NULL;
	right = NULL;
	parent = NULL;
	student = NULL;
	height = 0;

}

bstNode::bstNode(string firstName, string lastName, int favNum, string studJoke){
	Student *newStudent = new Student(firstName, lastName, favNum, studJoke);
	student = newStudent;
	left = NULL;
	right = NULL;
	parent = NULL;
	height = 1;

}

bstNode::~bstNode(){
	cout << student->first<< " is being deleted." << endl;
	left = NULL;
	//delete left;
	right = NULL;
	//delete right;

}

void bstNode::printNode(){
	cout << "************************************" << endl;
	cout << "Height of node:" << height << ", Name: " << this->student->first << " " << this->student->last << endl;
	cout << student->joke << endl;

}


