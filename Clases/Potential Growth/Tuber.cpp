#ifndef TuberH
#define TuberH
#include "Tuber.h"
using namespace modeling;
Tuber::Tuber()
{
 CleanVariables();
}
Tuber::~Tuber()
{
}
void Tuber::CleanVariables()
{
  M      = 0.0;
  A      = 0.0;
  b      = 0.0;
  DMCont = 0.0;
}
#endif
