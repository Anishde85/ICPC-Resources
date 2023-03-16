long long int cross_product(point a, point b) {
    long long int v1 = 1ll * a.x * b.y;
    long long int v2 = 1ll * b.x * a.y;
    return v1 - v2;
}
long double get_area_of_polygon(vector<point> &vc) {
    int n = vc.size();
    long long int ans = 0;
    FOR(i, 0, n) {
        ans += cross_product(vc[i], vc[(i + 1) % n]);
    }
    return abs(ans) * 1.0 / 2;
}