#include <Climate.cpp>
#include <Time2.cpp>
#include <Crop.cpp>
#include <Report.cpp>
#include <Simulation.cpp>
#include <string>
using namespace std;
namespace modeling
{
  class ManageDataPotato
  {
   private:
     char* workdir;
   public:
     ManageDataPotato();
     ~ManageDataPotato();
     ClimateFile *climate;
     Time *time;
     Crop *crop;
     Report *report;
     Simulation *simulation;
     void CleanCondition();
     void DefaultCondition();
     void GetWorkDir(char*);
     bool SaveCondition(char*);
     bool LoadCondition(char*);
     bool DoSimulation();
  };
}

