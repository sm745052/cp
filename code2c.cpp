#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <stack>
#include <numeric>
#include <array>
#include <set>

using namespace std;

void solve() {
  int n, k; cin >> n >> k;

  // first = power, second = health
  vector<pair<int, int>> m(n);

  for (int i = 0; i < n; ++i) {
    cin >> m[i].second;
  }
  for (int i = 0; i < n; ++i) {
    cin >> m[i].first;
  }

  // sorted by power
  sort(m.begin(), m.end());

  int64_t power = k;
  int64_t damage = 0;

  for (int i = 0; i < n; ++i) {
    const auto& [p, h] = m[i];

    if (h <= damage) continue;

    if (i > 0) {
      power -= p;
    }
    

    if (power > 0) {
      damage += power;

      while (h > damage) {
        power -= p;
        if (power < 0) break;
        damage += power;
      }
    }

    if (h > damage) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

