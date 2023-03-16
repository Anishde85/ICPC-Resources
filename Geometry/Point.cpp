struct point {
    long long int x, y;
    point() : x(0), y(0) {}
    point(long long int _x, long long int _y) : x(_x), y(_y) {}
};
istream &operator>>(istream &istream, point &p) {
    cin >> p.x >> p.y;
    return istream;
}
/**
 * @brief Get the orientation of 3 points when looked from p1 to p2
 * @return 0 - > same
 *         1 -> anticlockwise
 *        -1 -> clockwise
 */
int get_orientation(point p1, point p2, point p3) {
    long long int val1 = 1ll * (p2.x - p1.x) * (p3.y - p2.y);
    long long int val2 = 1ll * (p2.y - p1.y) * (p3.x - p2.x);
    long long int val = val1 - val2;
    if (val == 0)
        return 0;
    if (val > 0)
        return 1;
    return -1;
}
