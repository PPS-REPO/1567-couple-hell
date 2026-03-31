#include <iostream>
#include <vector>

struct Couple
{
  int x, y, a;
};
std::vector<Couple> couples;

struct Query
{
  int i, l, r;
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n, q;
  std::cin >> n >> q;
  int x, y, a;
  for (int i = 0; i < n; i++)
  {
    std::cin >> x >> y >> a;
    couples.push_back({x, y, a});
  }
  int l, r;
  for (int i = 0; i < q; i++)
  {
    std::cin >> l >> r;
    Query query = {i, l, r};
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
      Couple couple = couples[j];
      if (query.l <= couple.x && couple.x <= query.r && query.r < couple.y
        || couple.x < query.l && query.l <= couple.y && couple.y <= query.r)
      {
        sum += couple.a;
      }
    }
    std::cout << sum << '\n';
  }
}