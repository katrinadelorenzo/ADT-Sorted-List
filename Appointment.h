#include <string>
#include <fstream>
using namespace std;


enum RelationType {LESS, EQUAL, GREATER};

class Appointment
{
public:
  
  void Initialize(int newMonth, int newDay, int newYear, string desc);
  int GetMonth() const;							// returns year
  int GetYear() const;							// returns month
  int GetDay() const;							// returns day
  string GetMonthAsString() const;					// returns month as a string

  void Input();
  void Output();

  /***************************************************************
   * Compare keys (here it's the year/month/day) of calling object with other object 
   * This is used by UnsortedType's methods: GetItem(), DeleteItem() 
   * to search for the Appointment using the date as the key fields 
   ***************************************************************/
  RelationType ComparedTo(Appointment someAppt) const;

private:
  int  year;
  int  month;
  int  day;				

  string description; 
};


