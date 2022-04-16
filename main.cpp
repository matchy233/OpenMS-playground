#include "hdf5/serial/H5Cpp.h"
#include "lib/blosc/src/blosc_filter.h"

#include <filesystem>
#include <iostream>
#include <vector>

using namespace H5;
using namespace std;

std::filesystem::path cwd = std::filesystem::current_path().parent_path();

void readBLOSC()
{
  H5std_string FILE_NAME(cwd.string() + "/test/small.mzMLb");
  H5File file(FILE_NAME, H5F_ACC_RDONLY);

  Group group = file.openGroup("/");

  std::vector<H5std_string> group_names;
  hsize_t num = group.getNumObjs();
  group_names.resize(num);

  for (hsize_t i = 0; i < num; i++)
  {
    group_names[i] = group.getObjnameByIdx(i);
  }

  for (auto name : group_names)
  {
    cout << name << endl;
  }

  for (auto name : group_names)
  {
    DataSet dataset = group.openDataSet(name);
    DataSpace dataspace = dataset.getSpace();
    hsize_t dims_out[dataspace.getSimpleExtentNdims()];
    dataspace.getSimpleExtentDims(dims_out, NULL);

    double data_out[dims_out[0]];

    dataset.read(data_out, PredType::NATIVE_DOUBLE);
    cout << "Data of " << name << ": \n";
    for (int i = 0; i < 10; i++)
    {
      cout << data_out[i] << " ";
    }
    cout << endl;
    if (dims_out[0] > 10)
    {
      for (int i = dims_out[0] - 10; i < dims_out[0]; i++)
      {
        cout << data_out[i] << " ";
      }
    }
    cout << endl;
  }
}


int main()
{
  char* version;
  char* date;
  register_blosc(&version, &date);
  cout << "Blosc version: " << version << endl;
  cout << "Blosc date: " << date << endl;

  readBLOSC();

  return 0;
}
