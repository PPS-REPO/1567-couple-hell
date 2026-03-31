#include "testlib.h"

using namespace std;

int main(int argc, char** argv)
{
    registerGen(argc, argv, 1);

    int max_n = opt<int>("max_n");
    int max_q = opt<int>("max_q");

    int n = rnd.next(1, max_n);
    int q = rnd.next(1, max_q);
    cout << n << ' ' << q << '\n';

    for (int i = 0; i < n; i++)
    {
      int x = rnd.next(1, 199999);
      int y = rnd.next(x + 1, 200000);
      int a = rnd.next(1, 10000);
      cout << x << ' ' << y << ' ' << a << '\n';
    }

    for (int i = 0; i < q; i++)
    {
      int l = rnd.next(1, 200000);
      int r = rnd.next(l, 200000);
      cout << l << ' ' << r;
      if (i + 1 < q)
        cout << '\n';
    }

    return 0;
}