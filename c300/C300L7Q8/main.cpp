#include <vector>
#include <iostream>

using namespace std;
using ll=long long;

ll sq(ll i) { return i*i; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll g, n;
    cin >> g >> n;
    vector<pair<ll, pair<ll, ll>>> grazings(g);
    vector<pair<ll, pair<ll, ll>>> alibis(n);
    for (ll i = 0; i < g; i++) cin >> grazings[i].second.first >> grazings[i].second.second >> grazings[i].first;
    for (ll i = 0; i < n; i++) cin >> alibis[i].second.first >> alibis[i].second.second >> alibis[i].first;
    sort(grazings.begin(), grazings.end());

    ll numInnocent = 0;
    for (ll i = 0; i < n; i++) {
        auto after = *upper_bound(grazings.begin(), grazings.end(), alibis[i]);
        auto before = *(lower_bound(grazings.begin(), grazings.end(), alibis[i])-1);
        auto at = *(upper_bound(grazings.begin(), grazings.end(), alibis[i])-1);

        if (at.first == alibis[i].first && at.second.first == alibis[i].second.first && at.second.second == alibis[i].second.second) continue;
        if ((grazings[g-1].first <= alibis[i].first || sq(alibis[i].second.first-after.second.first) + sq(alibis[i].second.second-after.second.second) <= sq(after.first-alibis[i].first)) && (grazings[0].first >= alibis[i].first || sq(alibis[i].second.first-before.second.first) + sq(alibis[i].second.second-before.second.second) <= sq(alibis[i].first-before.first))) continue;

        numInnocent++;
    }
    cout << numInnocent << endl;
    return 0;
}
