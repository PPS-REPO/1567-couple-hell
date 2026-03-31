#include <iostream>
#include <vector>
#include <algorithm>

struct SegmentTree
{
  int size;
  std::vector<int> tree;
  SegmentTree(int n)
  {
    size = n;
    tree.assign(n * 2, 0);
  }
  void update(int index, int adder)
  {
    tree[index += size] += adder;
    for (; index > 1; index >>= 1)
    {
      tree[index >> 1] = tree[index] + tree[index ^ 1];
    }
  }
  int query(int left, int right)
  {
    left += size;
    right += size;
    int result = 0;
    for (; left <= right; left >>= 1, right >>= 1)
    {
      if (left & 1)
        result += tree[left++];
      if (!(right & 1))
        result += tree[right--];
    }
    return result;
  }
};

struct Couple
{
  int x, y, a;
};
std::vector<Couple> couples;

struct Query
{
  int i, l, r;
};
std::vector<Query> queries;

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
    queries.push_back({i, l, r});
  }
  std::sort(couples.begin(), couples.end(), [](const Couple &a, const Couple &b) { return a.y > b.y; });
  std::sort(queries.begin(), queries.end(), [](const Query &a, const Query &b) { return a.r > b.r; });
  int next = 0;
  SegmentTree tree(200001);
  std::vector<int> answer(q);
  for (int i = 0; i < q; i++)
  {
    while (next < n && couples[next].y > queries[i].r)
    {
      tree.update(couples[next].x, couples[next].a);
      next++;
    }
    answer[queries[i].i] += tree.query(queries[i].l, queries[i].r);
  }
  std::sort(couples.begin(), couples.end(), [](const Couple &a, const Couple &b) { return a.x < b.x; });
  std::sort(queries.begin(), queries.end(), [](const Query &a, const Query &b) { return a.l < b.l; });
  next = 0;
  std::fill(tree.tree.begin(), tree.tree.end(), 0);
  for (int i = 0; i < q; i++)
  {
    while (next < n && couples[next].x < queries[i].l)
    {
      tree.update(couples[next].y, couples[next].a);
      next++;
    }
    answer[queries[i].i] += tree.query(queries[i].l, queries[i].r);
  }
  for (int i = 0; i < q; i++)
  {
    std::cout << answer[i] << '\n';
  }
}