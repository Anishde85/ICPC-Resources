//  Given a point p and a line l (described by two points a and b), we can compute the
// minimum distance from p to l by first computing the location of point c in l that is
// closest to point p (see Figure 7.2—left) and then obtain the Euclidean distance between
// p and c. We can view point c as point a translated by a scaled magnitude u of vector
// ab, or c = a + u × ab. To get u, we do scalar projection of vector ap onto vector ab by
// using dot product (see the dotted vector ac = u × ab in Figure 7.2—left). The short
// implementation of this solution is shown below.

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // translate a to c
    return dist(p, c);
} // Euclidean distance between p and c
