#include <Plant.cpp>
#include <Tuber.cpp>
namespace modeling
{
  class Crop
  {
   public:
     Crop();
     ~Crop();
     char* CropList[10];
     int CropNumber;
     int SelectedCrop;
     Plant* plant;
     Tuber* tuber;
     void CleanVariables();
     void DefaultValuesForKindOfCrop(int);
  };
}

