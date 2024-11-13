#include <iostream>
#include <vector>
#include <iostream>
#include <numbers>
#include <cmath>
#include <iomanip>
// 基底クラス
class IShape {
public:
    
    virtual void Size() = 0;
    virtual void Draw() = 0;

    virtual ~IShape() = default;
};

//===================== 派生クラス =====================//

class Circle : public IShape{
public:

    Circle(float rad) : radius_(rad){}

    // 円の面積
    void Size() override {
         size_ = (radius_ * radius_) * std::numbers::pi;
    }

    // 円の面積を表示
    void Draw() override {
        std::cout << std::fixed << std::setprecision(2); // 小数点第2位まで
        std::cout << "円の面積 : " << size_ << std::endl;
    }
    
private:

    float radius_ = 0.0f;
    float size_ = 0.0f;

};

class Rectangle : public IShape{
public:

    Rectangle(float w,float h) : width_(w),hegiht_(h) {}

    // 矩形の面積
    void Size() override {
        size_ = width_ * hegiht_;
    };

    // 矩形の面積を表示
    void Draw() override {
        std::cout << "矩形の面積 : " << size_ << std::endl;
    };

private:

    float width_ = 0.0f;
    float hegiht_ = 0.0f;

    float size_ = 0.0f;
};

//====================================================//
int main() {

    IShape* shape1 = new Circle(5.0);
    shape1->Size();
    shape1->Draw();

    IShape* shape2 = new Rectangle(4.0, 6.0);
    shape2->Size();
    shape2->Draw();

    delete shape1;
    delete shape2;

    return 0;
}
