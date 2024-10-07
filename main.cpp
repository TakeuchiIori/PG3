
#include <iostream>
#include <cstdlib>   // rand() �֐��p
#include <ctime>     // time() �֐��p
#include <thread>    // sleep_for �֐��p
#include <chrono>    // chrono::seconds �p
#include <stdio.h>
#include <functional>
/// <summary>
/// 3�b�҂֐�
/// </summary>
void SetTimeout() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
}
/// <summary>
/// �����_���ȃT�C�R���̖ڂ𐶐����A���[�U�[�Ɋ���������𓖂Ă�����Q�[��
/// </summary>
void diceGame() {
    // ������ݒ�
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // �T�C�R���̖ڂ������_���ɐ����i1����6�̊ԁj
    int dice = std::rand() % 6 + 1;

    // ����
    int userGuess;
    std::cout << "�T�C�R���̖ڂ���������� (�: 1, ����: 2): ";
    scanf_s("%d", &userGuess);

    // ��������𔻒肷�郉���_��
    std::function<bool(int)> isEven = [](int num) -> bool { return num % 2 == 0; };

    // 3�b�ҋ@
    std::cout << "���ʂ��v�Z���ł�...\n";
    SetTimeout();

    // �T�C�R���̖ڂ�����������𔻒肵�A���ʂ��o��
    if ((isEven(dice) && userGuess == 2) || (!isEven(dice) && userGuess == 1)) {
        std::cout << "�����ł��B�T�C�R���̖ڂ� : " << dice << " \n";
    }
    else {
        std::cout << "�s�����ł��B�T�C�R���̖ڂ� : " << dice << " \n";
    }
}

int main() {
    diceGame();
    return 0;
}
