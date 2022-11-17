class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int A1=(C-A)*(D-B);
        int A2=(G-E)*(H-F);
        int left = max(A,E), right = max(min(C,G), left);
        int bottom = max(B,F), top = max(min(D,H), bottom);
        return A1+A2-(right-left)*(top-bottom);
    }
};