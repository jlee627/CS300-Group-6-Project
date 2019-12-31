/* 
Class for the Binary Search Tree data structure


||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
   --    CHANGE LOG    --

Josh Lee - Initial bst.h creation
Lee Hoang - Added more comments and cleaned up formatting.
Josh - Fixed case issues due to name changes
Changed the BST class to be a template class
Lee Hoang - Cleaned up formatting and added more comments.
*/

#include <iostream>


// Template class for a binary search tree. It requires the 
// operators << and < be overloaded for T in order for the 
// insertion and display functions to work correctly.
template <class T>
class Tree
{
    public:
        Tree();                         // Constructor.
        ~Tree();                        // Destructor.

        void insert(T * toAdd);         // Inserts member into a BST.

        bool retrieve(T * & toRet, long toFind);     // Uses ID number to search BST for Member/Provider.
        void displayAll();              // Displays contents of the BST.
        int remove(long toRemove);     // Uses ID number to remove Member/Provider.

    private:
        //Internal node struct for storing data
        struct tNode
        {
            T * data;
            tNode * left;               // Left pointer to left child.
            tNode * right;              // Right pointer to right child.
            tNode(T * toAdd): data(toAdd), left(NULL), right(NULL) // What is this function?
            {} // Why are there empty brackets here?
	    ~tNode() { if(data) { delete data;}}
        };

        tNode * root; // Root of the BST.
        void insert(tNode * & root, T * toAdd); // Recursive add function.
        bool retrieve(tNode * root, T * & toRet, long toFind); // Recursive retrieve function.
        void displayAll(tNode * root); // Recursive display function.
        int remove(tNode * & root, long toRemove); // Recursive remove (one node) function.
        void removeAll(tNode * & root); // Recursive remove all function.
	T * inOrderSuccessor(tNode * & root);	//find in order successor. 
};



// Constructor
template <class T>
Tree<T>::Tree()
{
    root = NULL;
}



// Deconstructor
template <class T>
Tree<T>::~Tree()
{
    removeAll(root);
}



// Wrapper function for insert
template <class T>
void Tree<T>::insert(T * toAdd)
{
    insert(root, toAdd);
}



// Recursive insert function
template <class T>
void Tree<T>::insert(tNode * & root, T * toAdd)
{    
    if (!root)
    {                    // Case: No tree
        root = new tNode(toAdd);     
        return;    
    }    

    //Case: id < root's 
    if(*toAdd < *root -> data)
    {                
        insert(root -> left, toAdd);    // Traverse down left leaf
    }

    //Case: id >= root's
    else
        insert(root -> right, toAdd);            //Traverse down right leaf
}



// Wrapper function for retrieve
template <class T>
bool Tree<T>::retrieve(T * & toRet, long toFind)
{
    return retrieve(root, toRet, toFind);
}


// Recursive retrieve function.
template <class T>
bool Tree<T>::retrieve(tNode * root, T * & toRet, long toFind)
{
   	// Base case: There is no tree or the item wasn't found.
	if (!root)
	   return false;
	
	// We get a matching ID.
	if (toFind == *root -> data)
	{
		toRet = root -> data;
		return true;

	}

	// Traverse the tree.
	if (toFind < *root -> data)
	   return retrieve(root -> left, toRet, toFind);
	else
	   return retrieve(root -> right, toRet, toFind);
}



// Wrapper function for displayAll
template <class T>
void Tree<T>::displayAll()
{
    displayAll(root);
}



// Recursive display all function
template <class T>
void Tree<T>::displayAll(tNode * root)
{
    // Base case: No tree.
    if (!root)
        return;

    // Display in sorted order.
    displayAll(root -> left);
    std::cout << (*(root -> data));
    displayAll(root -> right);
}



// Wrapper function for remove
template <class T>
int Tree<T>::remove(long toRemove)
{
    return remove(root,toRemove);
}



// Recursive function to remove a node. 
template <class T>
int Tree<T>::remove(tNode *& root, long toRemove)
{

	if(!root)	//no BST.
		return 0;

	if(*root -> data == toRemove)	// if we found the data to remove. 
	{
		if (root -> left == NULL && root -> right == NULL)	// we are at a leaf. 
        	{
			delete root;
            		root = NULL;
        	}


		else if (root -> left != NULL && root -> right == NULL) 	// we have left but no right. 
		{
			tNode * temp = root;
			root = root -> left;
			delete temp;
            		temp = NULL;
		}
		else if (root -> left == NULL && root -> right != NULL)	// we have a right but no left. 
		{
			tNode * temp = root;
			root = root -> right;
			delete temp;
            		temp = NULL;
		}

		else if (root -> left != NULL && root -> right != NULL)	// we have a left and right child. 
		{
            		delete root->data;
			root->data = inOrderSuccessor(root->right);
		}
        
		return 1;
	}

	return remove(root->left, toRemove) || remove(root->right,toRemove);
}

// find the inOrderSuccessor. 
template <class T>
T* Tree<T>::inOrderSuccessor(tNode *& root){

	if (!root)	// No BST.
		return 0;
	if(!root->left)	//end of left height.
    	{
        	T * iosData = root->data;
        	tNode * ios = root;
        	root->data = NULL;
        	root = root->right;
        	delete ios;
		return iosData;
    	}	
	else
		return inOrderSuccessor(root->left);	//keep traversing left. 
}

// Remove all fuction used to deallocate all memory.
template <class T>
void Tree<T>::removeAll(tNode * & root)
{
    if (!root)
        return;

    removeAll(root->left);
    removeAll(root->right);
    delete root;
}

