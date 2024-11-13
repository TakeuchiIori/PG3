#include "Enemy.h"

// メンバ関数ポインタテーブルの実体の定義
void (Enemy::* Enemy::spStateTable[])() = {
	&Enemy::Approach,
	&Enemy::Fire,
	&Enemy::Leave
};

void Enemy::Update()
{
	// メンバ関数ポインタテーブルから現在の状態を実行
	(this->*spStateTable[currentStateIndex])();
	// 次の状態に遷移
	currentStateIndex = (currentStateIndex + 1) % 3;
}

void Enemy::Approach()
{
	std::cout << "接近フェーズ" << std::endl;
}

void Enemy::Fire()
{
	std::cout << "射撃フェーズ" << std::endl;
}

void Enemy::Leave()
{
	std::cout << "離脱フェーズ" << std::endl;

}
