//--------------------------------------------------------------------//
//  Laboratory 9                                         test9.cpp//
//  Test program for the operations in the Binary Search Tree ADT//
//--------------------------------------------------------------------

#include <iostream>
#include "BSTree.cpp"
#include "config.h"
using namespace std;
void print_help();
//--------------------------------------------------------------------
// Declaration for the binary search tree data item class
//--------------------------------------------------------------------
class TestData{  
public:    
    void setKey ( int newKey )        
    { 
        keyField = newKey; 
    }   
    // Set the key    
    int getKey () const        
    { 
        return keyField; 
    }     // Returns the key  
private:    
    int keyField;                
    // Key for the data item
};
int main(){   
    BSTree<TestData,
        int> testTree;   
    // Test binary search tree    
    TestData testData;               
    // Binary search tree data item    
    int inputKey;                    // User input key    
    char cmd;                        // Input command    
    print_help();    
    do    {        
        testTree.showtreeStructure();                     
        // Output tree        
        cout << endl << "Command: ";                  
        // Read command        
cin >> cmd;        
if ( cmd == '+'  ||  cmd == '?'  ||             
    cmd == '-'  ||  cmd == '<'     )           
cin >> inputKey;        
switch ( cmd )        
{          
    case 'P' : case 'p' :               
    print_help();               
    break; 
          case '+':                                  
              // insert               
          testData.setKey(inputKey);               
          cout << "Insert : key = " << testData.getKey() << endl;              
          testTree.insertnode(testData);               
          break;          
          case '?' :                                  
              // retrieve               
          if ( testTree.retrievekey(inputKey,testData) )                  
          cout << "Retrieved : getKey = "                       
          << testData.getKey() << endl;               
          else                  
          cout << "Not found" << endl;               
          break;          
          case '-' :                                  
              // remove               
          if ( testTree.removenode(inputKey) )                  
          cout << "Removed data item" << endl;               
          else                  
          cout << "Not found" << endl;               
          break;          
          case 'K' : case 'k' :                       
              // writeKeys               
          cout << "Keys:" << endl;               
          testTree.writetreeKeys();               
          break;          
          case 'C' : case 'c' :                       
              // clear               
          cout << "Clear the tree" << endl;               
          testTree.cleartree();               
          break;          
          case 'E' : case 'e' :                       
              // empty               
          if ( testTree.istreeEmpty() )                  
          cout << "Tree is empty" << endl;               
          else                  
          cout << "Tree is NOT empty" << endl;               
          break;
#if   LAB9_TEST1 1         
          case 'G' : case 'g' :                   
              // Programming Exercise 2               
              cout << "Tree nodes count = " << testTree.gettreeCount() << endl;              
              break;
#endif
              // LAB9_TEST1
#if   LAB9_TEST2 1
          case 'H' : case 'h' :                   
              // Programming Exercise 2               
              cout << "Tree height = " << testTree.gettreeHeight() << endl;               
              break;
#endif
              // LAB9_TEST2
#if   LAB9_TEST3 1
          case '<' :                              
              // Programming Exercise 3               
              cout << "Keys < " << inputKey << " : " << endl;               
              testTree.writeLessThan(inputKey);               
              cout << endl;               
              break;
#endif
              // LAB9_TEST3
          case 'Q': case 'q':                   
              // Quit test program              
          break;          
          default :                               
              // Invalid command               
              cout << "Inactive or invalid command. 'P' prints help." << endl;        
}    
    }    
    while ( cin && ( cmd != 'Q' ) && ( cmd != 'q' ) );    
    if ( !cin ) {cerr << "Error in console input. Exiting." << endl;    
    }    
    return 0;
}
//--------------------------------------------------------------------
void print_help() 
{   
    cout << endl << "Commands:" << endl;    
    cout << "  P    : [P]rint Help (displays this message)" << endl;    
    cout << "  +key : Insert (or update) data item (use integers)" << endl;    
    cout << "  ?key : Retrieve data item" << endl;    
    cout << "  -key : Remove data item" << endl;    
    cout << "  K    : Write keys in ascending order" << endl;    
    cout << "  C    : Clear the tree" << endl;    
    cout << "  E    : Empty tree?" << endl;    
    cout << "  G    : Get count of nodes          " 
#if LAB9_TEST1         
        << "(Active   : " 
#else         
        << "(Inactive : " 
#endif         
        << "In-lab Exercise 2)" << endl;    
    cout << "  H    : Height                      "
#if LAB9_TEST2
        << "(Active   : "
#else
        << "(Inactive : "
#endif
        << "In-lab Exercise 2)" << endl;

    cout << " <key : Write keys that are < key   "
#if LAB9_TEST3         
        << "(Active   : " 
#else         
        << "(Inactive : "
#endif         
        << "In-lab Exercise 3)" << endl;    
        cout << "  Q    : Quit the test program" << endl;    
        cout << endl;
}