namespace modeling
{
  class Climate
  {
   public:
     Climate(int);
     ~Climate();
     double* MinTemp;
     double* MaxTemp;
     double* Precipit;
     double* Radiation;
     void CleanVariables();
   private:
     int RecNum;
  };
  class ClimateFile : public Climate
  {
    public:
      ClimateFile(int);
      ~ClimateFile();
      char* FileName;
      char* TitTMin;
      char* TitTMax;
      char* TitPrec;
      char* TitRad;
      void  CleanVariables();
      int   DeterminePosition(char*,char*);
      int   GetColumnData(char*,char*,double*);
      void  LoadClimateInformation();
  };
}
