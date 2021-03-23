// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "sorted.h"

using namespace std;
void PrintList(SortedType& list);
SortedType Intersection (SortedType & list1, SortedType & list2);
SortedType Union (SortedType & list1, SortedType &list2);
int main()
{

  string command;        // operation to be executed
  
  int number;
  Appointment appt;
  SortedType apptBook, apptBook2, apptBook3;
  bool found;
  int numCommands;

  //apptBook2 = {"2019/02/16:birthday"};
  cout <<"Appointment book application!\n";

  cout <<"Enter Command: Add, Delete, Search (by date), GetLength, MakeEmpty, Print, Quit:\n";
  cin >> command;

  numCommands = 0;
  while (command != "Quit")
  { 
    if (command == "Add")
    {
	cout <<"Enter an appointment to be added:";
    	appt.Input();
        apptBook.PutItem(appt);
        appt.Output();
        cout << " is in the book." << endl;
    }
    else if (command == "Delete")
    {
	cout <<"Enter an appointment to be deleted:";
	appt.Input();
      	apptBook.DeleteItem(appt);
      	appt.Output();
      	cout << " is deleted from the book." << endl;
    }
    else if (command == "Search")
    {
	cout <<"Enter an appointment to be deleted:";
	appt.Input();
        appt = apptBook.GetItem(appt, found);
        appt.Output(); 
        if (found)
          	cout << " found in list." << endl;
        else 
		cout <<  " not in list."  << endl;  
    } 
    else if (command == "GetLength")  
      cout << "Length is " << apptBook.GetLength() << endl;
    else if (command == "IsFull")
      if (apptBook.IsFull())
        cout << "List is full." << endl;
      else 
	cout << "List is not full."  << endl;  
    else if (command == "MakeEmpty")
	  apptBook.MakeEmpty();
    else if (command == "Print")
      PrintList(apptBook);
    else if (command == "Intersection")
      {
	cout << endl;
	cout << "Finding intersection between current book and other book";
	cout << endl;
	cout << "Please make second book: enter four dates!";
	cout << endl;
	cout << "Appointment 1:";
	appt.Input();
	apptBook2.PutItem(appt);
	appt.Output();
	cout << endl;
	cout << "Appointment 2:";
	appt.Input();
	apptBook2.PutItem(appt);
	appt.Output();
	cout <<	endl;
        cout <<	"Appointment 3:";
	appt.Input();
        apptBook2.PutItem(appt);
        appt.Output();
	cout <<	endl;
        cout <<	"Appointment 4:";
	appt.Input();
        apptBook2.PutItem(appt);
        appt.Output();
	SortedType intersectionBook;
	intersectionBook = Intersection(apptBook,apptBook2);
	cout << "Intersection Book:" << endl;
	PrintList(intersectionBook);
      }
    else if (command == "Union") {
      cout << endl;
        cout << "Finding intersection between current book and other book";
        cout << endl;
        cout << "Please make second book: enter four dates!";
        cout << endl;
        cout << "Appointment 1:";
        appt.Input();
        apptBook3.PutItem(appt);
        appt.Output();
        cout << endl;
        cout << "Appointment 2:";
        appt.Input();
        apptBook3.PutItem(appt);
        appt.Output();
        cout << endl;
        cout << "Appointment 3:";
        appt.Input();
        apptBook3.PutItem(appt);
        appt.Output();
        cout << endl;
        cout << "Appointment 4:";
        appt.Input();
        apptBook3.PutItem(appt);
        appt.Output();
	SortedType unionBook;
        unionBook = Union(apptBook,apptBook3);
        cout << "Union Book:" << endl;
        PrintList(unionBook);
    }
    else
      cout << command << " is not a valid command." << endl;
    numCommands++;
    cout <<  " Command number " << numCommands << " completed." 
         << endl;
    cin >> command;
  };

  
  

  return 0;
}

  
void PrintList(SortedType& list)
// Pre:  list has been initialized.      
//       dataFile is open for writing.   
// Post: Each component in list has been written to dataFile.
//       dataFile is still open.         
{
  int length;
  ItemType item;

  list.ResetList();
  length = list.GetLength();
  for (int counter = 1; counter <= length; counter++)
  {
    item = list.GetNextItem();
    item.Output();
    cout<<endl;
  }
}

// return the sorted list making up common items from list1 and list2

SortedType Intersection (SortedType & list1, SortedType & list2)
{
  SortedType tempList;
  int i = 0, j = 0;
  bool found;
  int length1 = list1.GetLength();
  int length2 = list2.GetLength();
  list1.ResetList();
  list2.ResetList();
  ItemType temp1 = list1.GetNextItem();
  ItemType temp2 = list2.GetNextItem();
  while (i < length1 && j < length2) { // i traverses through list1, j traverses through list2
    if (temp1.ComparedTo(temp2) == LESS) {
      i++;
      temp1 = list1.GetNextItem();
    }
    else if (temp1.ComparedTo(temp2) == GREATER){
      j++;
      temp2 = list2.GetNextItem();
    }
    else if (temp1.ComparedTo(temp2) == EQUAL){
      tempList.PutItem(temp1);
      cout << "Item Placed" << endl;
      temp1 = list1.GetNextItem();
      temp2 = list2.GetNextItem();
      i++;
      j++;
    }
  }
  return tempList;

}

SortedType Union(SortedType & list1, SortedType & list2)
{
  SortedType tempList;
  int i = 0, j = 0;
  int length1 = list1.GetLength();
  int length2 = list2.GetLength();
  bool found = false;
  list1.ResetList();
  list2.ResetList();
  ItemType temp1 = list1.GetNextItem();
  ItemType temp2 = list2.GetNextItem();
  while (i < length1 || j < length2) {
    if (temp1.ComparedTo(temp2) == LESS) {
      temp1 = tempList.GetItem(temp1,found); //see if number is already in union list 
      if (found){ // if number is found, do not place
	i++;
	temp1 = list1.GetNextItem();
      }
      else { // else if number is not already in list, place
	tempList.PutItem(temp1);
	i++;
	temp1 = list1.GetNextItem();
      }
    }
    else if (temp1.ComparedTo(temp2) == GREATER) {
      temp2 = tempList.GetItem(temp2,found); // see if number is already in union list
      if (found){ // if number is found, do not place and go next in index
	j++;
	temp2 = list2.GetNextItem();
      }
      else { // else if number is not already in list, place
	tempList.PutItem(temp2);
	j++;
	temp2 = list2.GetNextItem();
      }
    }
    else if (temp1.ComparedTo(temp2) == EQUAL) { // if numbers in both lists are equal
      temp1 = tempList.GetItem(temp1,found); // check if number is already in union list
      if (found) { // if number is found, do not place and go to next index in both lists
	j++;
	i++;
	temp1 = list1.GetNextItem();
	temp2 = list2.GetNextItem();
      }
      else { // else if number is not found, place in list
	tempList.PutItem(temp1);
	j++;
	temp1 = list1.GetNextItem();
	i++;
	temp2 = list2.GetNextItem();
      }
      
    }
  }
  return tempList;
}
