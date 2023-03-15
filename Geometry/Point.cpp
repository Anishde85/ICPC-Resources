struct point {
    int x, y;
    point() : x(0), y(0) {}
    point(int _x, int _y) : x(_x), y(_y) {}
};
/**
 * @brief Get the orientation of 3 points when looked from p1 to p2
 * @return 0 - > same
 *         1 -> anticlockwise
 *         -1 -> clockwise
 */
int get_orientation(point p1, point p2, point p3) {
    long long val = 1ll * (p2.x - p1.x) * (p3.y - p2.y) - 1ll * (p2.y - p1.y) * (p3.x - p2.x);
    if (val == 0)
        return 0;
    if (val > 0)
        return 1;
    return -1;
}
bool is_colinear(point p1, point p2, point p3) {
    return get_orientation(p1, p2, p3) == 0 and p3.x >= min(p1.x, p2.x) and p3.x <= max(p1.x, p2.x) and p3.y >= min(p1.y, p2.y) and p3.y <= max(p1.y, p2.y);
}