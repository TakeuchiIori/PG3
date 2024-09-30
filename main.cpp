#include <stdio.h>

// 関数テンプレート
template<typename T>
T min(T a, T b) {
   if (a < b) {
       return a;
   }
   else {
       return b;
   }
}
// テンプレートの特殊化（オーバーライド）
template <>
char min<char>(char a, char b) {

   printf("数字以外は入力できません");
   return '\0';
}

int main() {

    printf("%d\n", min<int>(115, 112));              // int
    printf("%f\n", min<float>(1.2f, 1.19f));         // float
    printf("%lf\n", min<double>(5.2f, 5.1999f));     // double
    printf("%c\n", min<char>('a','あ'));             // char

    return 0;
}
