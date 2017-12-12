#include <fstream>
#include <iostream>
#include "msg.pb.h"
using namespace std;

int main(void) {
  lm::helloworld msg1;
  msg1.set_uuid(101);
  msg1.set_str_license("hello");
  fstream output("./log", ios::out | ios::trunc | ios::binary);

  if (!msg1.SerializeToOstream(&output)) {
    cerr << "Failed to write msg." << endl;
    return -1;
  }
  return 0;
}