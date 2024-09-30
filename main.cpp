#include <stdio.h>

/// <summary>
/// 再帰関数
/// </summary>
float Recursive(int hours, float wage) {
    // もし時間が0なら、賃金は0
    if (hours == 0) {
        return 0.0;
    }
    // 次の時間の賃金を計算し、再帰的に次の時間の賃金を計算する
    return wage + Recursive(hours - 1, (wage * 2) - 50);
}

/// <summary>
/// 一般的な賃金体系の計算を行う関数
/// </summary>
float General(int hours) {
    const float hourly_wage = 1072.0;
    return hourly_wage * hours;
}

int main() {
    
    printf("時間  | 一般賃金      | 再帰賃金      | 結果\n");
    printf("-----------------------------------------------\n");

    for (int hours = 1; hours <= 10; hours++) {
        float generalWages = General(hours);
        float recursiveWages = Recursive(hours, 100.0);
        printf("%-4d | %-12.0f | %-12.0f | ", hours, generalWages, recursiveWages);
        if (recursiveWages > generalWages) {
            printf("再帰賃金が高い\n");
        }
        else {
            printf("一般賃金が高い\n");
        }
    }

    return 0;
}