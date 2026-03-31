#include "testlib.h"

using namespace std;

int main(int argc, char** argv)
{
  registerGen(argc, argv, 1);

  int max_n = opt<int>("max_n");
  int max_q = opt<int>("max_q");
  string weighted = opt("weighted");

  ensure(1 <= max_n && max_n <= 200000);
  ensure(1 <= max_q && max_q <= 200000);

  bool wflag = weighted == "yes";

  int n = wflag ? rnd.wnext(1, max_n, max_n / 1000 + 1) : rnd.next(1, max_n);
  int q = wflag ? rnd.wnext(1, max_q, max_q / 1000 + 1) : rnd.next(1, max_q);
  cout << n << ' ' << q << '\n';
  
  for (int i = 0; i < n; i++)
  {
    int x = wflag ? rnd.wnext(1, 199999, -100) : rnd.next(1, 199999);
    int y = wflag ? rnd.wnext(x + 1, 200000, 100) : rnd.next(x + 1, 200000);
    int a = rnd.next(1, 10000);
    cout << x << ' ' << y << ' ' << a << '\n';
  }

  for (int i = 0; i < q; i++)
  {
    int l = wflag ? rnd.wnext(1, 200000, -100) : rnd.next(1, 200000);
    int r = wflag ? rnd.wnext(l, 200000, 100) : rnd.next(l, 200000);
    cout << l << ' ' << r;
    if (i + 1 < q)
      cout << '\n';
  }

  return 0;
}