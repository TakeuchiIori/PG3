#include <iostream>
#include <vector>

// 基底クラス
class PaymentMethod {
public:
  
    // デストラクタ
    virtual ~PaymentMethod() {}

    //　純粋仮想関数
    virtual void pay(int amount) const = 0;
};

//===================== 派生クラス =====================//
/// <summary>
/// クレジットカードクラス
/// </summary>
class CreditCard : public PaymentMethod {
public:
    void pay(int amount) const override {
        std::cout << "クレジットカードで " << amount << " 円を支払いました。" << std::endl;
    }
};

/// <summary>
/// 現金クラス
/// </summary>
class Cash : public PaymentMethod {
public:
    void pay(int amount) const override {
        std::cout << "現金で " << amount << " 円を支払いました。" << std::endl;
    }
};

/// <summary>
/// 電子マネークラス
/// </summary>
class DigitalWallet : public PaymentMethod {
public:
    void pay(int amount) const override {
        std::cout << "電子マネーで " << amount << " 円を支払いました。" << std::endl;
    }
};

//====================================================//
int main() {

    std::vector<PaymentMethod*> payments;
    payments.push_back(new CreditCard());
    payments.push_back(new Cash());
    payments.push_back(new DigitalWallet());

    int amount = 5000;  // 支払金額
    for (const auto& payment : payments) {
        payment->pay(amount);
    }

    // 解放
    for (auto& payment : payments) {
        delete payment;
    }

    return 0;
}
