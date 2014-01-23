#ifndef TimeH
#define TimeH
#include "Time2.h"
using namespace modeling;
Time::Time()
{
 location = NULL;
 location = new char[50];
 Month = NULL;
 Month = new char[20];
 CleanVariables();
}
Time::~Time()
{
 if (location != NULL)
 {
  delete [ ]location;
  location=NULL;
 }
 if (Month != NULL)
 {
  delete [ ]Month;
  Month=NULL;
 }
}
void Time::CleanVariables()
{
  DayStart   = 0;
  MonthStart = 0;
  duration   = 0;
  strcpy(location,"");
  strcpy(Month,"");
  repetitions = 20;
}
#endif
