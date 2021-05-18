//--------------------------------------------------------------------//
//  Laboratory 11, In-lab Exercise 1                     database.cpp//
//  (Shell) Indexed accounts database program//
//--------------------------------------------------------------------
// Builds a binary search tree index for the account records in the
// text file accounts.dat.# include <iostream>

# include <iostream>

# include <fstream>

using namespace std;

//Person account holds information about

//record number, account ID, First name , last name and balance of the person

struct PersonAccount

{
    int RecNum=0;

    int AccountID=0;

    string FirstName;

    string LastName;

    double Balance=0;

}personAccount[15];

//Index entry contains account ID and recNum

struct IndexEntry

{

    int acctID; // (key) Account identifier   

    long recNum; // Record number

};

//Create Node of the Binary search tree to hold the index

struct node

{

    struct IndexEntry* index;

    struct node* left;

    struct node* right;

}*root;

//Class Binary searchtree

class BST

{

public:

    BST()

    {

        //root initially NULL

        root = NULL;

    }

    //function to insert the index in BST

    void insert(node*, node*);

    //function to search accountID

    void search(node*, int);

};

int main()

{

    BST bst; // create object for Class BST

    //open the accounts.dat file for reading

    ifstream infile("accountInfo.txt");

    if (!infile)

    {

        cout << endl << "Create the input file accounts.dat";

        exit(0);

    }

    //Reading the file into node and create binary search tree

    int n = 0; // number of entries

    while (!infile.eof())

    {

        //read person details from file into PersonAccount structure

        infile >> personAccount[n].RecNum >> personAccount[n].AccountID >> 
            personAccount[n].FirstName >> personAccount[n].LastName >> 
            personAccount[n].Balance;

        //Create index

        struct IndexEntry* index = new IndexEntry;

        index->acctID = personAccount[n].AccountID;

        index->recNum = personAccount[n].RecNum;

        //Create tree node to hold the index

        node* temp = new node;

        temp->index = index;

        temp->left = NULL;

        temp->right = NULL;

        //create root node

        if (root == NULL)

            root = temp;

        else // inserting and create the rest of the tree

            bst.insert(root, temp);

        n++;

    }

    //Read account ID from user as input

    int accountID;

    cout << endl << "Enter account ID: ";

    cin >> accountID;

    //Search the account ID in BST

    bst.search(root, accountID);

}

//Insert index in into BST

void BST::insert(node* r, node* temp)

{

    //if node is not available, create it

    if (r == NULL)

    {

        r = new node;

        r->index = temp->index;

        r->left = NULL;

        r->right = NULL;

    }



    if (temp->index->acctID < r->index->acctID)

    { //adding to left subtree

        if (r->left != NULL)

            insert(r->left, temp);

        else

        {

            r->left = new node;

            r->left->index = temp->index;

            (r->left)->left = NULL;

            (r->left)->right = NULL;

            return;

        }

    }



    else // temp->index->acctID > r->index->acctID

    {

        //adding to right subtree

        if (r->right != NULL)

        {

            insert(r->right, temp);

        }

        else

        {

            r->right = temp;

            (r->right)->left = NULL;

            (r->right)->right = NULL;

            return;

        }

    }

}

//search account number and return record number

void BST::search(node* root, int accountID)

{

    if (root == NULL) return;

    if (root->index->acctID > accountID)

    { //searching in left subtree

        if (root->left != NULL)

            search(root->left, accountID);

    }



    else if (root->index->acctID < accountID)

    {

        //searching in right subtree

        if (root->right != NULL)

            search(root->right, accountID);

    }

    else if (root->index->acctID == accountID) //match found

    {

        //Results

        cout << endl << "matched record number is " << root->index->recNum;

        cout << endl << "Corresponding account record from the database file: ";



        cout << endl << "Record # Account ID First Name Last Name Balance";

        cout << endl << personAccount[root->index->recNum].RecNum << "\t " <<
            personAccount[root->index->recNum].AccountID << "\t " <<
            personAccount[root->index->recNum].FirstName << "\t" <<
            personAccount[root->index->recNum].LastName << "\t" <<
            personAccount[root->index->recNum].Balance;

        return;

    }

}