#include <fstream>
#include <iostream>
#include "msg.pb.h"
using namespace std;

void ListMsg(const lm::helloworld& msg) {
  cout << msg.uuid() << endl;
  cout << msg.str_license() << endl;
}

int main(int argc, char* argv[]) {
  lm::helloworld msg1;

  {
    fstream input("./log", ios::in | ios::binary);
    if (!msg1.ParseFromIstream(&input)) {
      cerr << "Failed to parse address book." << endl;
      return -1;
    }
  }

  ListMsg(msg1);
}