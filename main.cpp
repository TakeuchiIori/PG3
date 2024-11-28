#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>
using namespace std;

int main() {

	////////////////////////////////////////////////////////////////
	//				正規表現のビルド時間（01.856秒）
	//              文字列読み取りのビルド時間（01,554）
	////////////////////////////////////////////////////////////////

	// ファイル名
	std::string filename = "ASCII./PG3_2024_03_02.txt";

	// ファイルを開く
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "ファイルが開けません: " << filename << std::endl;
		return 1;
	}

	// メールアドレスを格納するベクター
	std::vector<std::string> emails;

	// ファイル内容を1行ずつ読み取る
	std::string line;
	while (std::getline(file, line)) {
		// いらんもん削除
		line.erase(std::remove(line.begin(), line.end(), '['), line.end());
		line.erase(std::remove(line.begin(), line.end(), ']'), line.end());

		// カンマで区切られた文字列を分割
		std::stringstream ss(line);
		std::string email;
		while (std::getline(ss, email, ',')) {
			// 余計な空白や引用符を取り除く
			email.erase(std::remove(email.begin(), email.end(), '\"'), email.end());
			emails.push_back(email);
		}
	}

	// ファイルを閉じる
	file.close();

	// ソート処理
	std::sort(emails.begin(), emails.end());

	std::cout << "メールアドレス一覧:" << std::endl;
	for (const auto& email : emails) {
		std::cout << email << std::endl;
	}

	return 0;
}



//// ファイル名
//std::string filename = "ASCII./PG3_2024_03_02.txt";

//// ファイルを開く
//std::ifstream file(filename);
//if (!file.is_open()) {
//	std::cerr << "ファイルが開けません: " << filename << std::endl;
//	return 1;
//}

//// ファイル内容全体を1つの文字列に格納
//std::string fileContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

//// ファイルを閉じる
//file.close();

//// 正規表現でメールアドレスを抽出
//std::regex emailRegex(R"(([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}))");
//std::smatch match;
//std::vector<std::string> emails;

//// std::sregex_iteratorで繰り返す
//auto begin = std::sregex_iterator(fileContent.begin(), fileContent.end(), emailRegex);
//auto end = std::sregex_iterator();

//for (auto it = begin; it != end; ++it) {
//	emails.push_back(it->str()); // マッチしたメールアドレスをベクターに追加
//}

//std::sort(emails.begin(), emails.end());

//std::cout << "メールアドレス一覧:" << std::endl;
//for (const auto& email : emails) {
//	std::cout << email << std::endl;
//}


//return 0;