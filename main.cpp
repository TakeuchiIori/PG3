#include <stdio.h>
#include <time.h>   
#include <thread>  // 新規
#include <chrono>   

/// <summary>
/// サイコロの結果を生成する関数
/// </summary>
int rollDice() {
    return rand() % 6 + 1;
}
/// <summary>
/// サイコロの目が奇数か偶数かを判定する関数
/// </summary>
int isOdd(int number) {
    return number % 2 != 0 ? 1 : 0; // 奇数なら1、偶数なら0
}
/// <summary>
/// 結果を表示する関数
/// </summary>
void displayResult(bool correct, void (*callback)()) {
    if (correct) {
        printf("正解です！\n"); // 正解の場合
    }
    else {
        printf("残念でした不正解でした...\n"); // 不正解の場合
    }

    // コールバック関数を実行（3秒待機）
    callback();
}
/// <summary>
/// 3秒待機する関数
/// </summary>
void Wait() {
    //　指定した時間だけ停止することができる関数　#include <thread> 必要
    std::this_thread::sleep_for(std::chrono::seconds(3)); // 3秒待機
}

int main() {
    // 乱数を生成
    srand(time(0));

    // サイコロを振って1～6のランダムな数を取得
    int dice = rollDice(); 
    printf("サイコロを振りました。奇数か偶数かを予想してください!!!!（奇数なら1、偶数なら0を入力）：");

    int guess;
    // 入力を取得（奇数なら1、偶数なら0）
    scanf_s("%d", &guess); 

    // サイコロの目が奇数かどうかを判定
    int diceOdd = isOdd(dice); 

    // ユーザーの予想と実際のサイコロの結果を比較
    bool correct = (guess == diceOdd);

    // 結果を表示する前に3秒待機
    displayResult(correct, Wait); 

    // サイコロの結果を表示
    printf("サイコロの目は %d でした。\n", dice); 

    return 0;
}
