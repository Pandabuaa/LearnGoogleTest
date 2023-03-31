#include "BigInteger.h"
BigInteger::BigInteger(std::string s) {
    for (int i = s.size() - 1; i >= 0; i--) {
        nums.push_back(s[i] - '0');
    }
}
// C = A + B, A >= 0, B >= 0
BigInteger operator+(const BigInteger& lhs,const BigInteger& rhs)
{
    const std::vector<int>& A = lhs.nums;
    const std::vector<int>& B = rhs.nums;
    if (A.size() < B.size()) return rhs+lhs;
    BigInteger res;
    std::vector<int> C = res.nums;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(t);
    return res;
}

// C = A - B, Âú×ãA >= B, A >= 0, B >= 0
BigInteger operator-(const BigInteger& lhs, const BigInteger& rhs) {
    const std::vector<int>& A = lhs.nums;
    const std::vector<int>& B = rhs.nums;
    BigInteger res;
    std::vector<int> C = res.nums;
    for (int i = 0, t = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return res;
}


// C = A * b, A >= 0, b >= 0
std::vector<int> mul(std::vector<int>& A, int b)
{
    std::vector<int> C;

    int t = 0;
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }

    while (C.size() > 1 && C.back() == 0) C.pop_back();

    return C;
}

// A / b = C ... r, A >= 0, b > 0
std::vector<int> div(std::vector<int>& A, int b, int& r)
{
    std::vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

