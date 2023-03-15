/**
    @brief use code of Point.cpp
*/
struct line_segment {
    point p1, p2;
    line_segment() {}
    line_segment(point _p1, point _p2) : p1(_p1), p2(_p2) {}
};

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