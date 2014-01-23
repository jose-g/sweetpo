#include <Climate.cpp>
#include <Time2.cpp>
#include <Crop.cpp>
#include <Report.cpp>
#include <math.h>
namespace modeling
{
  class Simulation
  {
   public:
     Simulation();
     ~Simulation();
     ClimateFile *climate;
     Crop *crop;
     Time    *time;
     Report  *report;
     int NumberScenario;
     bool simulate();
     int Month(int);
     double Random();
     void CleanVariables();
     double dWtot_mat[100][365];
     double dWtb_mat[100][365];
     double dWtbf_mat[100][365];
  };
}

