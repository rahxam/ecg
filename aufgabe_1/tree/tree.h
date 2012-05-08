#pragma once
#include <string>
#include <vector>
using namespace std;

/*
* ECG SS12, Gruppe 02, Tutor Paul Völker
** Autoren: 
** -Brugger, Marlene
** -Gyapjas, Balint
** -Hartig, Maximilian
*/


class node
{
private:
	static unsigned int node_id;
	string mName;
	vector<node*> children;
	bool trav_flag;

public:
	static unsigned int spaces;

	node(void);
	node(string const &name);
	virtual ~node(void);

	
	string const & node::get_name(void) const;
	bool node::get_trav_flag();
	void node::set_name(string new_name);
	int const node::get_nr_children(void) const;
	node* const node::get_child(unsigned int i) const;
	void node::add_child(node* n);
	void node::mega_print(node* n);
	
	
};

extern node* create_complete_tree(unsigned int nr_child_nodes, int tree_depth);
extern std::ostream& operator<<(std::ostream&, node* n);