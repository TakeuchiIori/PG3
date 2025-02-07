#include <iostream>
#include <string>
#include <chrono>
#include <iomanip> // std::fixed, std::setprecision

int main() {
    std::string a(100000, 'a');
    std::cout << "100,000文字を移動とコピーで比較しました。\n";

    auto start_copy = std::chrono::high_resolution_clock::now();
    std::string b = a;
    auto end_copy = std::chrono::high_resolution_clock::now();

    auto copy_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();
    std::cout << std::fixed << std::setprecision(0);
    std::cout << "コピー: " << static_cast<double>(copy_duration) << "us\n";

  
    auto start_move = std::chrono::high_resolution_clock::now();
    std::string c = std::move(a); // ムーブ
    auto end_move = std::chrono::high_resolution_clock::now();

    auto move_duration = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();
    std::cout << "移動: " << static_cast<double>(move_duration) << "us\n";

    std::cout << "続行するには何かキーを押してください・・・";
    std::cin.get(); // キー入力を待つ

    return 0;
}
