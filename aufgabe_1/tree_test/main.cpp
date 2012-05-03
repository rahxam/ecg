#include "tree.h"
#include <iostream>
#include <vector>
extern node* create_complete_tree(unsigned int nr_child_nodes, int tree_depth);


/*
* ECG SS12, Gruppe 02, Tutor Paul Völker
** Autoren: 
** -Brugger, Marlene
** -Gyapjas, Balint
** -Hartig, Maximilian
*/

int main(int argc, char* argv[])
{
	
//AUFGABE 1.1
	/*
	node* root = new node("root");
	node* left_child = new node("left_child");
	node* right_child = new node("right_child");

	root->add_child(left_child);
	root->add_child(right_child);
	
	delete root;
	*/

//AUFGABE 1.2.
	/*
	node* root = create_complete_tree(2,4);
	std::cout << root << std::endl;
	*/

//TEST
	
	/*
	node* root = new node("");
	std::cout << root->get_name() << std::endl;

	
	node* lc = new node("lc");
	node* rc = new node("rc");

	root->add_child(lc);
	root->add_child(rc);

	rc->add_child(root);

	std::cout << root->get_nr_children() << std::endl;
	std::cout << lc->get_nr_children() << std::endl;
	std::cout << rc->get_nr_children() << std::endl;
	*/


	system("pause");
	
	return 0;
	

}