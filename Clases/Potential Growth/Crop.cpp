#ifndef CropH
#define CropH
#include "Crop.h"
using namespace modeling;
Crop::Crop()
{
  plant=NULL;
  plant=new Plant();
  tuber=NULL;
  tuber=new Tuber();
  CropList[0]="Jonathan";
  CropList[1]="Naveto";
  CropList[2]="Tanzania";
  CropList[3]="Jewel";
  CropList[4]="Zapallo";
  CropNumber=5;
  CleanVariables();
}
Crop::~Crop()
{
 if (plant != NULL)
 {
  delete plant;
  plant=NULL;
 }
 if (tuber != NULL)
 {
  delete tuber;
  tuber=NULL;
 }
}
void Crop::CleanVariables()
{
  SelectedCrop=-1;
  plant->CleanVariables();
  tuber->CleanVariables();
}
void Crop::DefaultValuesForKindOfCrop(int key)
{
// Kind of crops:
// 0 : Jonathan
// 1 : Naveto
// 2 : Tanzania
  if(key==0)
  {
     SelectedCrop=0;
     plant->fcl=1.0055;
     plant->F0=0.0042;
     plant->R0=0.00757;
     plant->d=0.0;  // no se usan en camote
     plant->t50=0.0;  // no se usan en camote
     plant->LUE=2.54;
     plant->N=4.44;
     tuber->M=0.6943;
     tuber->A=742;
     tuber->b=-6.3238;
     tuber->DMCont=0.27;
  }
  if(key==1)
  {
     SelectedCrop=1;
     plant->fcl=0.7491;
     plant->F0=0.0098;
     plant->R0=0.00888;
     plant->d=0.0; // no se usan en camote
     plant->t50=0.0; // no se usan en camote
     plant->LUE=3.38;
     plant->N=3;
     tuber->M=0.888;
     tuber->A=745;
     tuber->b=-9.45;
     tuber->DMCont=0.4291;
  }
  if(key==2)
  {
     SelectedCrop=2;
     plant->fcl=0.6275;
     plant->F0=0.0082;
     plant->R0=0.00898;
     plant->d=0.0; // no se usan en camote
     plant->t50=0.0;  // no se usan en camote
     plant->LUE=2.53;
     plant->N=3;
     tuber->M=0.8888;
     tuber->A=624;
     tuber->b=-9.71;
     tuber->DMCont=0.4403;
  }
  if(key==3)
  {
     SelectedCrop=3;
     plant->fcl=0.4158;
     plant->F0=0.0061;
     plant->R0=0.00548;
     plant->d=0.0; // no se usan en camote
     plant->t50=0.0;  // no se usan en camote
     plant->LUE=2.07;
     plant->N=3;
     tuber->M=0.55;
     tuber->A=683;
     tuber->b=-7.52;
     tuber->DMCont=0.3325;
  }
  if(key==4)
  {
     SelectedCrop=4;
     plant->fcl=0.478;
     plant->F0=0.0083;
     plant->R0=0.00764;
     plant->d=0.0; // no se usan en camote
     plant->t50=0.0;  // no se usan en camote
     plant->LUE=2.9;
     plant->N=3;
     tuber->M=0.75;
     tuber->A=778;
     tuber->b=-8.21;
     tuber->DMCont=0.3815;
  }
}
#endif
