#include "testlib.h"

using namespace std;

void case_1()
{
  std::cout << "5 3\n1 4 1\n1 6 10\n2 3 100\n2 5 1000\n3 5 10000\n2 3\n1 5\n3 4";
}

int main(int argc, char** argv)
{
  registerGen(argc, argv, 1);

  int num = opt<int>("num");
  if (num == 1)
  {
    case_1();
  }

  return 0;
}