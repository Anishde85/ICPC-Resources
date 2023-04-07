// returns true if point p is in either convex/concave polygon P
bool inPolygon(point pt, const vector<point> &P) {
if ((int)P.size() == 0) return false;
double sum = 0; // assume the first vertex is equal to the last vertex
for (int i = 0; i < (int)P.size()-1; i++) {
if (ccw(pt, P[i], P[i+1]))
sum += angle(P[i], pt, P[i+1]); // left turn/ccw
else sum -= angle(P[i], pt, P[i+1]); } // right turn/cw
return fabs(fabs(sum) - 2*PI) < EPS; }