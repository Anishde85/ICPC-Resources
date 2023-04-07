/**
    @brief use code of Point.cpp
*/
struct line_segment {
    point p1, p2;
    line_segment() {}
    line_segment(point _p1, point _p2) : p1(_p1), p2(_p2) {}
};
istream &operator>>(istream &istream, line_segment &l) {
    cin >> l.p1 >> l.p2;
    return istream;
}
bool is_colinear(point p1, point p2, point p3) {
    return get_orientation(p1, p2, p3) == 0 
    and p3.x >= min(p1.x, p2.x) and p3.x <= max(p1.x, p2.x) 
    and p3.y >= min(p1.y, p2.y) and p3.y <= max(p1.y, p2.y);
}
bool do_intersect(line_segment &l1, line_segment &l2) {
    int ori1 = get_orientation(l1.p1, l1.p2, l2.p1);
    int ori2 = get_orientation(l1.p1, l1.p2, l2.p2);
    int ori3 = get_orientation(l2.p1, l2.p2, l1.p1);
    int ori4 = get_orientation(l2.p1, l2.p2, l1.p2);
    if (ori1 != ori2 and ori3 != ori4)
        return true;
    bool case1 = is_colinear(l1.p1, l1.p2, l2.p1) or is_colinear(l1.p1, l1.p2, l2.p2);
    bool case2 = is_colinear(l2.p1, l2.p2, l1.p1) or is_colinear(l2.p1, l2.p2, l1.p2);
    return (case1 or case2);
}