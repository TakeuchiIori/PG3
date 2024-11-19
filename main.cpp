#include <iostream>
#include <list>
#include <cstring>

// 駅クラス
class Station {
public:
    char name[50];  
    int year; 

    // コンストラクタ
    Station(const char* stationName, int yearAdd) {
        strncpy_s(name, stationName, sizeof(name));
        name[sizeof(name) - 1] = '\0'; 
        year = yearAdd;
    }
};

// 駅リストを指定した年で表示する関数
void printStations(const std::list<Station>& stations, int year) {
    std::cout << "Stations in " << year << ":\n";
    for (const auto& station : stations) {
        if (station.year <= year) {
            std::cout << station.name << "\n";
        }
    }
    std::cout << "--------------------\n";
}

int main() {
    // 1970年の山手線駅リストを初期化
    std::list<Station> stations = {
        {"Tokyo", 1970}, {"Kanda", 1970}, {"Akihabara", 1970}, {"Okachimachi", 1970},
        {"Ueno", 1970}, {"Uguisudani", 1970}, {"Nippori", 1970}, {"Tabata", 1970},
        {"Komagome", 1970}, {"Sugamo", 1970}, {"Otsuka", 1970}, {"Ikebukuro", 1970},
        {"Mejiro", 1970}, {"Takadanobaba", 1970}, {"Shin-Okubo", 1970}, {"Shinjuku", 1970},
        {"Yoyogi", 1970}, {"Harajuku", 1970}, {"Shibuya", 1970}, {"Ebisu", 1970},
        {"Meguro", 1970}, {"Gotanda", 1970}, {"Osaki", 1970}, {"Shinbashi", 1970},
        {"Yurakucho", 1970}
    };

    // 西日暮里駅を1971年に追加
    auto it = stations.begin();
    std::advance(it, 7); // 7番目に挿入
    stations.insert(it, Station("Nishi-Nippori", 1971));

    // 高輪ゲートウェイ駅を2020年に追加
    it = stations.begin();
    std::advance(it, 21); // 21番目に挿入
    stations.insert(it, Station("Takanawa Gateway", 2020));

    // 1970年の駅リストを表示
    printStations(stations, 1970);

    // 2019年の駅リストを表示
    printStations(stations, 2019);

    // 2022年の駅リストを表示
    printStations(stations, 2022);

    return 0;
}
