#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<int, ll> accounts;
    for (int i = 0; i < n; i++) {
        int id, balance;
        cin >> id >> balance;
        accounts[id] = balance;
    }
    int t;
    cin >> t;
    while (t--) {
        int sender, receiver, amount;
        cin >> sender >> receiver >> amount;
        if (accounts[sender] < amount) {
            cout << "Failure\n";
        } else {
            accounts[sender] -= amount;
            accounts[receiver] += amount;
            cout << "Success\n";
        }
    }
    vector<pair<int, ll>> sortedAccounts(accounts.begin(), accounts.end());
    sort(sortedAccounts.begin(), sortedAccounts.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) {
            return a.second<b.second; 
        } else {
            return a.first < b.first; 
        }
    });
    cout << endl ;
    for (const auto& account : sortedAccounts) {
        cout << account.first << " " << account.second << endl;
    }
    return 0;
}
