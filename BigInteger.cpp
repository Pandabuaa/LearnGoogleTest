#include "BigInteger.h"
bool absless(const BigInteger& lhs, const BigInteger& rhs) {
    if (lhs.nums.size() == rhs.nums.size()) {
        for (int i = lhs.nums.size() - 1; i >= 0; i--) {
            if (lhs.nums[i] < rhs.nums[i]) {
                return true;
            }
        }
        return false;
    }
    else {
        return lhs.nums.size() < rhs.nums.size();
    }
}

// C = A + B, A >= 0, B >= 0
std::vector<int> add(const std::vector<int>& A, const std::vector<int>& B)
{
    if (A.size() < B.size()) return add(B, A);

    std::vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);
    return C;
}

// C = A - B, Âú×ãA >= B, A >= 0, B >= 0
std::vector<int> sub(const std::vector<int>& A, const std::vector<int>& B)
{
    std::vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);
        if (t < 0) t = 1;
        else t = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

// C = A * b, A >= 0, b >= 0
std::vector<int> mul(const std::vector<int>& A, int b)
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

BigInteger::BigInteger(std::string s) {
    int end = 0;
    if (s[0] == '-') {
        f = NEG;
        end = 1;
    }
    else {
        f = POS;
    }
    for (int i = s.size() - 1; i >= end; i--) {
        nums.push_back(s[i] - '0');
    }
}
// C = A + B, A >= 0, B >= 0
BigInteger operator+(const BigInteger& lhs,const BigInteger& rhs)
{
    BigInteger res;
    if (lhs.f == rhs.f) {
        res.f = lhs.f;
        res.nums = add(lhs.nums, rhs.nums);
        return res;
    }
    if (absless(lhs, rhs)) {
        res.f = rhs.f;
        res.nums = sub(rhs.nums, lhs.nums);
    }
    else {
        res.f = lhs.f;
        res.nums = sub(lhs.nums, rhs.nums);
    }
    return res;
}

BigInteger operator-(const BigInteger& lhs, const BigInteger& rhs) {
    BigInteger temp = rhs;
    if (temp.f == POS) {
        temp.f = NEG;
    }
    else {
        temp.f = POS;
    }
    return lhs + temp;
}

BigInteger operator*(const BigInteger& lhs, const BigInteger& rhs) {
    BigInteger res;
    if (lhs.f == rhs.f) {
        res.f = POS;
    }
    else {
        res.f = NEG;
    }
    for (int i = 0; i < rhs.nums.size(); i++) {
        std::vector<int> temp = mul(lhs.nums, rhs.nums[i]);
        temp.insert(temp.begin(), i, 0);
        res.nums = add(res.nums, temp);
    }
    return res;
}

std::ostream& operator<<(std::ostream& os, const BigInteger& x) {
    if (x.f == NEG) {
        os << "-";
    }
    else {
        os << "+";
    }
    for (int i = x.nums.size() - 1; i >= 0; i--) {
        os << x.nums[i];
    }
    return os;
}


