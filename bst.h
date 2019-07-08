#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#ifndef BST_H
#define BST_H

class treenode  //node in a BST
{
public:
	string info;
	double population;
	treenode  *lchild, *rchild;   //left and right children pointers
};
struct county_pop
{
public:
	string name;
	double pop;
};

class bst
{
public:
	bst(); //store the data file (“county_data.txt”) into initial bst
	~bst();//de-allocates dynamic memory allocate for tree
	bool empty(); // checks to see if the tree is empty
	void insert(const string & item, const double & number); //inserts a county record into bst based on 
	//county_name.
	void insert(treenode * &, string item, const double & number); //see insert description above
	void del_name(string item); //deletes a county record based on county name.
	void del_name(treenode * & loc_ptr, string item); //see del description above
	treenode * search_tree(treenode *, string item);//returns pointer to node  with county name
	treenode * search_tree(string item); //see search_tree description above
	treenode * inorder_succ(treenode *);//return pointer to inorder successor (based on population 
	//size;
	void population_ranges(const double&  min_size, const double & max_size); //prints all county names 
	//o the screen with a  population size between min_size and max_size.
	void sorted_info();//prints each county record to a file called “county_info.txt” sorted by county 
	//name”.
	void sorted_info(treenode * ptr);
	void print_tree(); //prints the node in the bst in numerical order based on the population size
	void print_tree(treenode *);//see description above

private:
	treenode *root;
};

#endif