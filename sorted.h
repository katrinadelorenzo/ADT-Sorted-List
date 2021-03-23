/*********************************************************************
// File ItemType.h must be provided by the user of this class. 
//  ItemType.h must contain the following definitions: 
//  ItemType:      the definition of the objects on the list 
//  RelationType:  {LESS, GREATER, EQUAL}
//  Member function ComparedTo(ItemType item) which returns 
//       LESS, if self "comes before" item 
//       GREATER, if self "comes after" item 
//       EQUAL, if self and item are the same 
********************************************************/
#include "ItemType.h" 

class SortedType 
{
public:
  SortedType(); // Constructor
  SortedType(int size); // Constructor

  ~SortedType(); //destructor 
  
  void MakeEmpty();
  // Function: Returns the list to the empty state.
  // Post:  List is empty.
  
  bool IsFull() const;
  // Function:  Determines whether list is full.
  // Pre:  List has been initialized.
  // Post: Function value = (list is full)

  int GetLength() const;
  // Function: Determines the number of elements in list.
  // Pre:  List has been initialized.
  // Post: Function value = number of elements in list

  ItemType GetItem(ItemType, bool&);
  // Function: Retrieves list element whose key matches item's key (if
  //           present).
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  // Post: If there is an element someItem whose key matches
  //       item's key, then found = true and someItem is returned.
  // 	 otherwise found = false and item is returned.
  //       List is unchanged.

  void PutItem(ItemType item);
  // Function: Adds item to list.
  // Pre:  List has been initialized.
  //       List is not full.
  //       item is not in list.
  // Post: item is in list.

  void DeleteItem(ItemType item);
  // Function: Deletes the element whose key matches item's key.
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  //       One and only one element in list has a key matching item's key.
  // Post: No element in list has a key matching item's key.

  void ResetList();
  // Function: Initializes current position for an iteration through the list.
  // Pre:  List has been initialized.
  // Post: Current position is prior to list.

  ItemType GetNextItem();
  // Function: Gets the next element in list.
  // Pre:  List has been initialized and has not been changed since last call.
  //       Current position is defined.
  //       Element at current position is not last in list.
  //	     
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

  SortedType(const SortedType & that); // copy Constructor
  SortedType & operator= (const SortedType &that);
private:
  int length; //the number of elements stored ...

  const static int DEF_SIZE=10;
  /****************************************************************
   *  info: a pointer variable, together with length, size, currentPos make
   *     up the in-object memory used by this class
   ***************************************************************/
  ItemType * info; 
  /****************************************************************/
  // Cannot say info = new ITEMTYPE[size]; in here
  // The allocation of dynamic variable for object of this type
  // can only happen later when object of the type has existed (at the constructor, e.g.
  /****************************************************************/


  int size; //size of array that info points to. 

  int currentPos;

  bool IsSorted();
  //Function: check if items are stored in sorted order                                                                           
  //pre: list has been initialized                                                                                                
  //post: if list is not properly sorted, return false; else return true                                                          


};

