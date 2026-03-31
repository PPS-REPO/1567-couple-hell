#include "testlib.h"
using namespace std;

const int MAX_N = 200000;
const int MAX_Q = 200000;
const int MAX_COORD = 200000;
const int MAX_A = 10000;

int main(int argc, char *argv[])
{
  registerValidation(argc, argv);

  int n = inf.readInt(1, MAX_N, "n");
  inf.readSpace();
  int q = inf.readInt(1, MAX_Q, "q");
  inf.readEoln();

  for (int i = 0; i < n; i++)
  {
    int x = inf.readInt(1, MAX_COORD, "x");
    inf.readSpace();
    int y = inf.readInt(1, MAX_COORD, "y");
    inf.readSpace();
    int a = inf.readInt(1, MAX_A, "a");
    ensure(x < y);
    inf.readEoln();
  }

  for (int i = 0; i < q; i++)
  {
    int l = inf.readInt(1, MAX_COORD, "l");
    inf.readSpace();
    int r = inf.readInt(1, MAX_COORD, "r");
    ensure(l <= r);
    if (i + 1 < q)
      inf.readEoln();
  }
  
  inf.readEof();
}