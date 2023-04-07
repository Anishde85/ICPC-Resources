// If we are given a line segment instead (defined by two end points a and b), then the
// minimum distance from point p to line segment ab must also consider two special
// cases, the end points a and b of that line segment (see Figure 7.2—middle). The
// implementation is very similar to distToLine function above.
// // returns the distance from p to the line segment ab defined by
// // two points a and b (still OK if a == b)
// // the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) {
        c = point(a.x, a.y); // closer to a
        return dist(p, a);
    } // Euclidean distance between p and a
    if (u > 1.0) {
        c = point(b.x, b.y); // closer to b
        return dist(p, b);
    } // Euclidean distance between p and b
    return distToLine(p, a, b, c);
} // run distToLine as above