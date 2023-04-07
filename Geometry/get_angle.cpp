// We can compute the angle aob given three points: a, o, and b, using dot product13.
// Since oa · ob = |oa|×|ob| × cos(θ), we have theta = arccos(oa · ob/(|oa|×|ob|)).
double angle(point a, point o, point b) { // returns angle aob in rad
    vec oa = toVector(o, a), ob = toVector(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}