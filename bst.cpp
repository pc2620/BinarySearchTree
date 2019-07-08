#include "bst.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bst::bst(){
	
	root = 0;

	ifstream in;
	in.open("county_data.txt"); //opens file
	string myString;
	string check;
	double myNumber;

	
	while (!in.eof()){		
		in >> myString >> myNumber; // taking in data

		insert(root, myString, myNumber); //function call
	}
	in.close(); //closes file
	
}

bool bst::empty() {
	return (root == 0); //return true for empty root
}

void bst::insert(const string & item, const double & population){

	insert(root, item, population); //function call
}

void bst::insert(treenode * & cur_ptr, string item, const double & number){
	
	if (cur_ptr == 0)
	{
		cur_ptr = new treenode;
		cur_ptr->lchild = cur_ptr->rchild = 0;
		cur_ptr->info = item;
		cur_ptr->population = number;
	}
	else if (cur_ptr->info>item)
		insert(cur_ptr->lchild, item, number);
	else if (cur_ptr->info<item)
		insert(cur_ptr->rchild, item, number);
	/*else
		cout << "the item is already in the tree\n";*/
	
}

void bst::del_name(string item){

	del_name(root, item);


}; //deletes a info record based on info name.



void bst::del_name(treenode * & cur_ptr, string item){

	if (cur_ptr == 0)
		cout << "item not in tree\n";

	else if (cur_ptr->info > item)
		del_name(cur_ptr->lchild, item);

	else if (cur_ptr->info < item)
		del_name(cur_ptr->rchild, item);

	else
	{
		treenode * ptr;

		if (cur_ptr->lchild == 0)
		{
			ptr = cur_ptr->rchild;
			delete cur_ptr;
			cur_ptr = ptr;
		}
		else if (cur_ptr->rchild == 0)
		{
			ptr = cur_ptr->lchild;
			delete cur_ptr;
			cur_ptr = ptr;
		}
		else
		{
			ptr = inorder_succ(cur_ptr);
			cur_ptr->info = ptr->info;
			del_name(cur_ptr->rchild, ptr->info);
		}
	}
}
treenode * bst::inorder_succ(treenode * cur_ptr)
{

	treenode *ptr = cur_ptr->rchild;

	while (ptr->lchild != 0)
	{
		ptr = ptr->lchild;
	}
	return ptr;
}

void bst::print_tree(){
	  
	print_tree(root);
}

void bst::print_tree(treenode * cur_ptr){

	if (cur_ptr != 0){
		print_tree(cur_ptr->lchild);
		cout << cur_ptr->info;
		cout << " ";
		cout << cur_ptr->population << endl;
		print_tree(cur_ptr->rchild);
	}
	
}

treenode * bst::search_tree(string item)
{
	return search_tree(root, item);
}

void bst::population_ranges(const double & min_size, const double & max_size)
{
	county_pop countyPop[67];
	ifstream in;

	in.open("county_data.txt");
	string myString;
	for (int i = 0; i<67; i++) { //reading same data into an array of structs
		in >> countyPop[i].name >> countyPop[i].pop;
	}
	in.close();

	for (int i = 0; i < 67; i++) {
		if (countyPop[i].pop < max_size && countyPop[i].pop > min_size) {
			cout << countyPop[i].name << " " << countyPop[i].pop << endl;
		}
	}
}


treenode * bst::search_tree(treenode * cur_ptr, string item)
{
	if (cur_ptr != 0)
	{
		if (cur_ptr->info == item)
			return cur_ptr;
		else if (cur_ptr->info>item)
			return search_tree(cur_ptr->lchild, item);
		else
			return search_tree(cur_ptr->rchild, item);
	}
	else
		return cur_ptr;
}
void bst::sorted_info()
{
	sorted_info(root);
}

void bst::sorted_info(treenode * ptr)
{
	ofstream out;
	out.open("county_info.txt");
	if (ptr != 0) {
		sorted_info(ptr->lchild);
		out << ptr->info << " " << ptr->population << endl;
		sorted_info(ptr->rchild);
	}
	out.close();
}

bst::~bst()
{

	while (root != 0){
		del_name(root->info);
	}
}