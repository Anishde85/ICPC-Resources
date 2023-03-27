#include<bits/stdc++.h>

using namespace std;
 
typedef long long ll;
//**************************************************

// For finding maximum in (1, r)..we can change "+=" to "max()".
// But in update operation value will never decrease.
// It is not easy to calculate maximum of (l, r) using BIT 
// as there is no inverse operation of maximum.
struct BIT {
    ll n;
    vector<ll> a;

    // Need to access 1 to n_p.
    BIT(ll n_p) : n(n_p + 1) {
        a.assign(n, 0);
    }

    // i should not be 0.
    void add(ll i, ll x) {
        for(; i < n; i += (i & -i)) {
            a[i] += x;
        }
    }

    // summation of 1...i
    // i should not be 0
    ll query(ll i) {
        ll sum = 0;
        for(; i > 0; i -= (i & -i)) {
            sum += a[i];
        }
        return sum;
    }
};

int main() {

	return 0;
}
