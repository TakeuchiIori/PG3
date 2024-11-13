#pragma once
#include <iostream>
/// <summary>
/// 敵の状態を表すクラス
/// </summary>
class Enemy {
public:
    // コンストラクタ
    Enemy() : currentStateIndex(0) {}

    /// <summary>
    /// 状態遷移の更新
    /// </summary>
    void Update();

private:
  
    static void (Enemy::* spStateTable[])();

    // 現在の状態インデックス
    int currentStateIndex;

    /// <summary>
    /// 接近状態の処理
    /// </summary>
    void Approach();

    /// <summary>
    /// 射撃状態の処理
    /// </summary>
    void Fire();

    /// <summary>
    /// 離脱状態の処理
    /// </summary>
    void Leave();
};

