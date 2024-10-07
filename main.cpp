
#include <iostream>
#include <cstdlib>   // rand() 関数用
#include <ctime>     // time() 関数用
#include <thread>    // sleep_for 関数用
#include <chrono>    // chrono::seconds 用
#include <stdio.h>
#include <functional>
/// <summary>
/// 3秒待つ関数
/// </summary>
void SetTimeout() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
}
/// <summary>
/// ランダムなサイコロの目を生成し、ユーザーに奇数か偶数かを当てさせるゲーム
/// </summary>
void diceGame() {
    // 乱数を設定
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // サイコロの目をランダムに生成（1から6の間）
    int dice = std::rand() % 6 + 1;

    // 入力
    int userGuess;
    std::cout << "サイコロの目が奇数か偶数か (奇数: 1, 偶数: 2): ";
    scanf_s("%d", &userGuess);

    // 奇数か偶数を判定するラムダ式
    std::function<bool(int)> isEven = [](int num) -> bool { return num % 2 == 0; };

    // 3秒待機
    std::cout << "結果を計算中です...\n";
    SetTimeout();

    // サイコロの目が奇数か偶数かを判定し、結果を出力
    if ((isEven(dice) && userGuess == 2) || (!isEven(dice) && userGuess == 1)) {
        std::cout << "正解です。サイコロの目は : " << dice << " \n";
    }
    else {
        std::cout << "不正解です。サイコロの目は : " << dice << " \n";
    }
}

int main() {
    diceGame();
    return 0;
}
