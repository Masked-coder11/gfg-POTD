class Solution {
  public:
    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[]) {
        // code here
        long long area = 0;
        area+=(p[0]*q[1]) - (p[1]*q[0]);
        area+=(q[0]*r[1]) - (q[1]*r[0]);
        area+=(r[0]*p[1]) - (r[1]*p[0]);
        long long pb = 0;
        pb+=__gcd(abs(p[0]-q[0]),abs(p[1]-q[1]));
        pb+=__gcd(abs(r[0]-q[0]),abs(r[1]-q[1]));
        pb+=__gcd(abs(p[0]-r[0]),abs(p[1]-r[1]));
        return abs(area)/2 - pb/2 +1;
    }
};
