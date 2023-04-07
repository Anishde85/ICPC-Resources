// vector<point> P;
// P.push_back(point(1, 1)); // P0
// P.push_back(point(3, 3)); // P1
// P.push_back(P[0]); // important: loop back
bool isConvex(const vector<point> &P) { // returns true if all three
    int sz = (int)P.size();             // consecutive vertices of P form the same turns
    if (sz <= 3)
        return false;                    // a point/sz=2 or a line/sz=3 is not convex
    bool isLeft = ccw(P[0], P[1], P[2]); // remember one result
    for (int i = 1; i < sz - 1; i++)     // then compare with the others
        if (ccw(P[i], P[i + 1], P[(i + 2) == sz ? 1 : i + 2]) != isLeft)
            return false; // different sign -> this polygon is concave
    return true;
}