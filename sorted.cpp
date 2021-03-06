// Implementation file for sorted.h

#include "sorted.h"

/**************************************************
 *Constructor: initialized in-object variable
              also: allocate out-object memory (the dynamic array)
****************************************************/
SortedType::SortedType()
{
  size = DEF_SIZE;
  info = new ItemType[size];
  length = 0;
}

SortedType::SortedType(int size)
{
  this->size = size;
  info = new ItemType[size];
  length = 0;
}

/**************************************************
 *Destructure: the object itself's memory will be deallocated automatically 
        out-object memory (the dynamic array) needs to be manually deleted
**********************************************/
SortedType::~SortedType()
{
   delete [] info;
}


bool SortedType::IsFull() const
{
  return (length == size);
}

int SortedType::GetLength() const
{
  return length;
}


//a helper function to be used by GetItem 
//search for item in a[left...right]
//if it's found, return the index
//else return -1 
int BinarySearch (ItemType a[ ], int left, int right, ItemType item)
{
  int index = -1;
  int midpoint = (left+right)/2;
  if (right == left) {
    if (item.ComparedTo(a[left]) == EQUAL){ // comparing item with only item in array at index 0
      index = left;// index equal to first and only element
    }
    return index;
  }
  else if (item.ComparedTo(a[midpoint]) == LESS) { // if element in midpoint is larger than target
    index = BinarySearch(a, left, midpoint-1, item);
    return index;
  }
  else if (item.ComparedTo(a[midpoint]) == GREATER) { // if element at the midpoint is smaller than the target
    index = BinarySearch(a,midpoint+1,right, item);
    return index;
  }  
  else
    return midpoint;

}

ItemType SortedType::GetItem(ItemType item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
//       list is sorted in ascending order 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been returned;
//       otherwise, item is returned. 
{
  int first = 0;
  int last = length - 1;
  int position = BinarySearch(info,first, last, item); // Use BinarySearch to find index of item, if found 

  if (position == -1){ //position will be -1 if item is not found
    found = false;
    return item;
  }
  else{ // if item is found
    found = true;
    return info[position]; // returns the item in array at found position
  } 
  return item;
}

void SortedType::MakeEmpty()
// Post: list is empty.
{
  length = 0;
}


//TODO: 
void SortedType::PutItem(ItemType item)
// pre: the list is sorted
// Post: item is in the list. list is sorted 
//1. determine the index for item in info array                                                                                 
//                                                                                                                             
//2. if length==size,  grow the array size                                                                                     
//                     copy elements beofre item into new array                                                                
//                     store item into the index                                                                               
//                     copy remaining elements into new array                                                                  
//                     increase length                                                                                         
//3. else                                                                                                                      
//       follow the code we studied in class                                                                                  

{
  int index = 0; // index is used to determine where item is placed
  int i;
  for (i = 0; i < length; i++) {
    if (info[i].ComparedTo(item) == GREATER)
      {
	break;
      }
  }
  index = i;
  
  if (length == size) { // if array is full, create a new dynamic array
    ItemType *temp;
    temp = new ItemType[size*2];
    for (int i = 0; i < index; i++) // from i[0] to where index was found i[index]
      temp[i] = info[i];
    temp [index] = item; // insert item at index
    for (int i = index; i < length; i++) { // fill in rest of array
      temp[i+1] = info[i];
    }
    delete [] info;
    info = temp;
    length++;
    size *= 2;
  }    
  else { // if array is not full, insert item 
    for (int i = 0; i < length; i++) {
      if (info[i].ComparedTo(item) == GREATER) // item should go into info[i]
	break;
    }
    
    //move info[i...length-1] down by 1
    for (int j = length - 1; j >= i; j--)
      info[j+1] = info[j];
    info [i] = item;
    length++;
    
  }
  
}


void SortedType::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
//       list is sorted
// Post: No element in the list has a key that matches item's.
//        list is sorted 
{
  int i;
  

  for (i = 0; i <= length; i++) { // traverse through array to find item
    if (item.ComparedTo(info[i]) == EQUAL) //if item is found, i will equal index
      break;
  }
  if (i != length) { // if item was found i will be less than length
    for (int j = i; j < length; j++)
      info[j] = info[j+1]; // move info[i...length-1] up by 1 from location of deleted item
    length--;
  }
}

void SortedType::ResetList() 
// Post: currentPos has been initialized.
{
  currentPos = -1;
}

ItemType SortedType::GetNextItem()
// Pre:  ResetList was called to initialized iteration.
//       No transformer has been executed since last call.
//       currentPos is defined.
// Post: item is current item.
//       Current position has been updated.
{
  currentPos++;
  return info[currentPos];
}

bool SortedType:: IsSorted()
{
  for (int i = 0; i < length; i++) {
    if (info[i].ComparedTo(info[i+1]) == GREATER)
      return false;
  }
  return true;
}

SortedType::SortedType(const SortedType & that) // copy Constructor
{
  info = NULL;
  size = 0;  //prepare to use assignment 
  (*this) = that; //call assignment operator to perform deep copy 
}

  // A simplistic implementation of operator= (see better implementation below)
SortedType & SortedType::operator= (const SortedType & that)
{
  if (this==&that) //self assignment, do nothing
    return *this;
  else
    {
      //If size is different, create a new array 
      // and delete the old one (if there is one).
      if (size!=that.size){
	if (info!=NULL)
	  delete [] info;
	size = that.size;
	info = new ItemType[size];
      }
      
      //copy the data from that to calling object
      for (int i=0;i<that.length;i++)
	{
	  info[i] = that.info[i];
	}
      length = that.length;
      return *this;

    }
}
