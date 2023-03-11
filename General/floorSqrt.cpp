long long floorSqrt(long long a) {
  long long b = a, x = 0, y = 0;
  for (int e = (63 - __builtin_clzll(a)) & ~1; e >= 0; e -= 2) {
    x <<= 1;
    y <<= 1;
    if (b >= (y | 1) << e) {
      b -= (y | 1) << e;
      x |= 1;
      y += 2;
    }
  }
  return x;
}