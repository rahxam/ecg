#include "tree.h"
#include <iostream>
#include <sstream>

/*
* ECG SS12, Gruppe 02, Tutor Paul Völker
** Autoren: 
** -Brugger, Marlene
** -Gyapjas, Balint
** -Hartig, Maximilian
*/

unsigned int node::node_id = 0;
unsigned int node::spaces = 0;

//Standardkonstruktor
node::node(void)
{
}


//Konstruktor mit Initialisierungsliste
node::node(string const &name = "") : mName(name)
{
	this->trav_flag = false;
	node_id++;
	if(name=="")
	{
		std::stringstream str_sm;
		str_sm << "node_" << node::node_id;
		this->mName = str_sm.str();
	}
	else this->mName = name;
	//std::cout << "Knoten '" + name + "' erstellt.\n";
}


//rekursiver Destruktor
node::~node(void)
{
	std::cout << "enter ~node() of \"" << this->get_name() <<"\"" << endl;
	for(unsigned int i=0; i < this->children.size(); i++)
	{
		delete (children[i]);
	}
	std::cout << "leave ~node() of \"" << this->get_name() <<"\"" << endl;
}


//get_name
string const & node::get_name(void) const
{
	return mName;
}


//set_name
void node::set_name(string new_name)
{
	mName = new_name;
}


//get_nr_children ?? nur 'true'-children != NULL ??
int const node::get_nr_children(void) const
{
	return this->children.size();
}


//get_child
node* const node::get_child(unsigned int i) const
{
	return children[i-1];
}


//add_child
void node::add_child(node* n)
{
	children.push_back(n);
	//std::cout << "'" + n->get_name() + "' an '" + this->get_name() + "' angefuegt.\n";
}


//create_complete_tree
extern node* create_complete_tree(unsigned int nr_child_nodes, int tree_depth)
 {
	if(nr_child_nodes != 0 && tree_depth > 0)
	{
		node* n = new node("");
		//std::cout << n->get_name() << " erstellt." << std::endl;
		for(unsigned int i=1; i<=nr_child_nodes; i++)
		{
			n->add_child(create_complete_tree(nr_child_nodes, tree_depth-1));
		}	
		return n;
	}
	node* ptr;
	ptr = NULL;
	return ptr;
}

	

//<<stream-operator IMPOSSIBRU! (not anymore)
extern std::ostream& operator<<(std::ostream& Stream, node* n)
{
	for(unsigned int j=0; j<node::spaces; j++)
	{
		Stream << "   ";
	}
	
	if(n->get_child(1)!=NULL)
	{
		Stream << n->get_name() << std::endl;
		node::spaces++;
		for(int i=1; i<=n->get_nr_children(); i++)
		{
			//std::cout << "bin in der FOR-Schleife! (i = " << i << ".)" << std::endl;
			Stream << n->get_child(i);
		}
		node::spaces--;
		return Stream;
	}
	else
	{
		//std::cout << "bin im ELSE-Zweig! (->child == NULL)" << std::endl;
		return Stream << n->get_name() << std::endl;
	}
}


//get_trav_flag
bool node::get_trav_flag()
{
	return trav_flag;
}


//mega_print
void node::mega_print(node* n)
{
	if(n->get_trav_flag() == false)
	{
		std::cout << "shit";
	}
}

