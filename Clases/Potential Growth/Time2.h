namespace modeling
{
  class Time
  {
   public:
     Time();
     ~Time();
     int DayStart;
     int MonthStart;
     int duration;
     char* Month;
     char *location;
     void CleanVariables();
  };
}
