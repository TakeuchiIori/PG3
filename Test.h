#pragma once
template <typename T1,typename T2>
class Test
{
public:

	T1 a_;
	T2 b_;

    Test(T1 a, T2 b) : a_(a), b_(b) {}

    auto Min() const {
        return (a_ < b_) ? a_ : b_;
    }


};


