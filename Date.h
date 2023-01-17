// Final Project Milestone 1
// Date Module
// File  Date.h
// Version 1.0
// Author   Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
/**************************************************

Name : Samarth Shaileshkumar Patel
Email: sspatel74@myseneca.ca
student ID:143147213
section:NKK
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my project milestones.
-----------------------------------------------------------

***********************************************/
#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>
namespace sdds
{
   const int NO_ERROR = 0;
   const int CIN_FAILED = 1;
   const int YEAR_ERROR = 2;
   const int MON_ERROR = 3;
   const int DAY_ERROR = 4;
   const char DATE_ERROR[5][16] = {
       "No Error",
       "cin Failed",
       "Bad Year Value",
       "Bad Month Value",
       "Bad Day Value"};
   const int MIN_YEAR = 1500;
   class Date
   {
   private:
      int m_year;
      int m_mon;
      int m_day;
      int m_ErrorCode;
      int m_CUR_YEAR;
      bool validate();                                   // validates the date setting error code and
      void errCode(int); // sets the error code
      int systemYear() const;                            // returns the current system year
      bool bad() const;                                  // return true if
      int mdays() const;                                 // returns the number of days in current month
   public:
      Date();                                                                                                                      // creates a date with current date
      Date(int year, int mon, int day);                                                                                            // create a date with assigned values,
       void setToToday();                                                                 // sets the date to the current date
       int daysSince0001_1_1() const;                                                                                 // returns number of days passed since the
       int errCode() const;                                                                                       // returns the error code or zero if date is
       const char *dateStatus() const;                                                                                        // returns a string corresponding the
       int currentYear() const;                                                                          // returns the m_CUR_YEAR value;
      std::istream &read(std::istream &is = std::cin);
      std::ostream &write(std::ostream &os = std::cout) const;
      operator bool() const;
   };
   std::ostream &operator<<(std::ostream &os, const Date &RO);
   std::istream &operator>>(std::istream &is, Date &RO);
   bool operator==(const Date &lo, const Date &ro);
   bool operator!=(const Date &lo, const Date &ro);
   bool operator>=(const Date &lo, const Date &ro);
   bool operator<=(const Date &lo, const Date &ro);
   bool operator<(const Date &lo, const Date &ro);
   bool operator>(const Date &lo, const Date &ro);
   int operator-(const Date &lo, const Date &ro);
   extern bool sdds_test;
   extern int sdds_year;
   extern int sdds_mon;
   extern int sdds_day;
}
#endif // !SDDS_DATE_H__
