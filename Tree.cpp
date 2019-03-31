/**
 
 * exercise on binary trees
 *
 * @author Ortal and Tomer
 *
 * http://www.cplusplus.com/forum/beginner/118562/
 * https://stackoverflow.com/questions/31715769/c-delete-a-node-from-binary-search-tree
 */
#include <iostream>
#include <stdexcept>
#include "Tree.hpp"
using namespace ariel;
using namespace std;
//construcrtor
Tree::Tree() {
    treeRoot=nullptr;
    sizeOf=0;
}
//destrucrtor
Tree::~Tree() {
    deleteTree(treeRoot);
}
//destrucrtor extension
void Tree::deleteTree(Node *n){
    if(n!=NULL){
        deleteTree(n->getLeft());
        deleteTree(n->getRight());
        delete n;
    }
}
//insert a new node to the tree

void Tree::insert(int i) {
	
    if (contains(i)){ //preventig duplication
	 throw runtime_error("the value already exist");
	}
	 Node *n = new Node(i);
	 
	 if(treeRoot==nullptr){ //the tree is empty then the node become the root
	    treeRoot=n;
	}
	else{	//there is a root
	    Node *cur =treeRoot;
        int data;
		bool flag=true; 
	    while(flag){ //while we haven't reached a null pointer
	    
			if(i>cur->getKey()){	 //checks is i belongs to the right subtree
				if(cur->getRight()!=nullptr){	            
				cur=cur->getRight();
				}
	        
	    	else { //we reached a null pointer
	        		cur->setRight(n);
				flag=false;
	    	}
		}
	    	else{ //i belongs to the left subtree
	        		if(cur->getLeft()!=nullptr){
					cur=cur->getLeft();
	    		}
				else{//we reached a null pointer
			 		cur->setLeft(n);
			 		flag=false;
				}

	    	}
	  	}
	}
	sizeOf++; //after inserting a node update its size
}

/* this function helps to find the maximum node
 * the param n is the root of a left subtree
 */
Node* Tree::maxNodeValue(Node *n){
    if(n==nullptr)
    return NULL;
	
    while(n->getRight() != NULL)
    {
        n = n->getRight();
    }
    return n;
}
// this function removes a node using _remove
void Tree::remove(int i) {
	// if tree is empty - throw exeption
    if (!treeRoot) {
        throw runtime_error("Tree is empty");
    }
    // if tree doesn't contains value - throw exeption
    else if(!contains(i)){
        throw invalid_argument(" not found");
    }
    // else call recursive remove method
    else {
        _remove(treeRoot, i);
        if(sizeOf>0)sizeOf--; //checks memory leak
    }
}
//this function removes a node	
Node* Tree::_remove(Node* n ,int data){

<<<<<<< HEAD
//Node *temp=new Node(data);	//temporary node 
if(n==NULL){
	  throw runtime_error("There is not i such data to remove");
	return n;
}
=======
Node *temp=new Node(data);	//temporary node 
if(n==NULL){
 	throw runtime_error("thers is no data to remove");
	return n;
	 }
>>>>>>> 74798a083c60324fdc859c9ba2291d8fb1366231
    else if(data<n->getKey())                     //searching the node in the left subtree
        n->setLeft( _remove(n->getLeft(), data)); 
    else if (data> n->getKey())					  //searching the node in the right subtree
        n->setRight( _remove(n->getRight(), data));
    else 
    {
        //No child
        if(n-getKey()==data){
        if(n->getRight() == NULL && n->getLeft() == NULL)
        {
            delete n;
            n = nullptr;   
        }
        }
        //One child (left) 
        else if(n->getRight() == NULL)
        {
             
	        Node *temp=n->getLeft();
            //n= n->getLeft();
            delete n;
            n=temp;
        }
		//one child (right)
        else if(n->getLeft() == NULL)
        {
             
	    Node *temp=n->getRight();
            //n= n->getRight();
            delete n;
            n=temp;
        }
        //two childs
        else
        {
		//getting the maximum node from left subtree
	    Node *Maxtempdata=maxNodeValue(n->getLeft());
            temp = new Node (Maxtempdata->getKey());
            n->setKey(temp->getKey()) ;
            n->setLeft(_remove(n->getLeft(), temp->getKey()));
        }
    }
    return n;
}
    
//returns the size of tree
int Tree::size() {
	return sizeOf;
}
//checks if i found in this tree
bool Tree::contains(int i) {
    if(treeRoot==nullptr){
        return false;
    }
    Node *n=treeRoot;
    while (n!=nullptr){ //keep going till we get to null pointer
      if(i>n->getKey()){
	            n=n->getRight();
	        }
	    else if(i<n->getKey()){
	        n=n->getLeft();
	    }
	    else { //found the requested node return true
	        return true;
	    }  
    }
    return false;
}
//return tree root
int Tree::root() {
    if(treeRoot!=nullptr){
    return treeRoot->getKey();
    }
    throw runtime_error("the tree is empty");
}

//check if the tree is empty
bool Tree::isempty(){
    if(treeRoot==nullptr){
        return true;
    }
    return false;
}
//returns the parent of node i
int Tree::parent(int i) {
	if((!contains(i)) && (i==treeRoot->getKey())){ //checks of the node is even in the tree
	    throw runtime_error("there no such key");
	}
	
	else{
	    Node *n=treeRoot;
	    while(1){
	    if(i>n->getKey()){ //see if i is the right child
	        if(n->getRight()->getKey()==i){
	            return n->getKey();
	        }
	        else n=n->getRight();
	    }
	    else {  //see if i is the left child
	        if(n->getLeft()->getKey()==i){
	            return n->getKey();
	        }
	        else n=n->getLeft();
	    }
	}
  }
  return 0;
}

//returns the left child
int Tree::left(int i) {
	if(!contains(i)){	//checks of the node is even in the tree
	   throw runtime_error("there no such key");
	}
	
	else {
		Node *n=treeRoot;

	    while(n!=nullptr){
	        if(i==n->getKey()){
	            if(n->getLeft()==nullptr){ //the node dosen't have left child
	                throw runtime_error("there no such key");
	            }
	            else return n->getLeft()->getKey();  //found the node we looked for return his left child
	        }
	        else if(i>n->getKey()){ //i is bigger than the current node look in sub right tree
	            n=n->getRight();
	        }
	        else{ //i is smaller than the current node look in sub left tree
	        		n=n->getLeft();
			}
        }
    }
    return 0;
}

//returns the right child
int Tree::right(int i) {
	if(!contains(i)){	//checks of the node is even in the tree
	   throw runtime_error("there no such key");
	}
	else{
		Node *n=treeRoot;

	    while(n!=nullptr){
	        if(i==n->getKey()){
	            if(n->getRight()==nullptr){	//the node dosen't have right child
	                throw runtime_error("there no such key");
	            }
	            else return n->getRight()->getKey();  	//found the node we looked for return his right child
	        }
	        else if(i>n->getKey()){ //i is bigger than the current node look in sub right tree
	            n=n->getRight();
	        }
	        else  //i is smaller than the current node look in sub left tree
	       	 	n=n->getLeft();
        }
    }
    return 0;
}
//Inorder print LVR
void Tree::printInOrder(Node *n) {
    if(n==nullptr) return;

	printInOrder(n->getLeft());
	cout<<n->getKey()<<" ";
	printInOrder(n->getRight());

}

void Tree::print() {
   printInOrder(treeRoot);
	
}