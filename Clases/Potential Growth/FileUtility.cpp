#ifndef FileUtilityH
#define FileUtilityH
#include "FileUtility.h"
#include <fstream>
#include "vector.h"
#include "sstream.h"
using namespace modeling;
//------------------------------------------------------------------------------
FileData::FileData()
{
}
//------------------------------------------------------------------------------
FileData::~FileData()
{
}
//------------------------------------------------------------------------------
int FileData::GetFieldsName(char *FieldsList[],char *FileName)
{
  ifstream in(FileName);
  string line;
  vector<string> v;
  string buffer;
  getline(in,line,'\n');
  stringstream aStream;
  aStream << line;
  const char* valor;
  int z=0;
  int num;
  while(!aStream.eof())
  {
    z++;
    aStream >> buffer;
    v.push_back(buffer);
    num=strlen(v[z-1].c_str());
    char* dato = new char[ num + 1 ];
    strcpy(dato, v[z-1].c_str());
    FieldsList[z-1]=dato;
  }
  in.close();
  return z;
}
//------------------------------------------------------------------------------
#endif
