#include <string>
#include <Time2.cpp>
#include <fstream>
using namespace std;
namespace modeling
{
  class Report
  {
   public:
     Report();
     ~Report();
     char* Archivo1;
     char* Archivo2;
     char* DMProd;
     char* DMProdResume;
     Time* time;
     char* variety;
     int scenario;
     void CleanVariables();
     void DeleteReports();
     void GenerateTextReport();
     void GenerateDMProd();
     void GenerateDMProdResume();
  };
}

