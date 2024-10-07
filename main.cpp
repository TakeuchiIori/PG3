#include <iostream>
#include <cstdlib>   // rand() �֐��p
#include <ctime>     // time() �֐��p
#include <thread>    // sleep_for �֐��p
#include <chrono>    // chrono::seconds �p

/// <summary>
/// �����_���ȃT�C�R���̖ڂ𐶐����A���[�U�[�Ɋ���������𓖂Ă�����Q�[��
/// </summary>
void diceGame() {
    // �����̎��ݒ�
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // �T�C�R���̖ڂ������_���ɐ����i1����6�̊ԁj
    int dice = std::rand() % 6 + 1;

    // ���[�U�[�ɓ��͂𑣂�
    int userGuess;
    std::cout << "�T�C�R���̖ڂ͊�����������ĂĂ������� (�: 1, ����: 2): ";
    std::cin >> userGuess;

    // ��������𔻒肷�郉���_��
    auto isEven = [](int num) { return num % 2 == 0; };

    // 3�b�ҋ@
    std::cout << "���ʂ��v�Z���ł�...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // �T�C�R���̖ڂ�����������𔻒肵�A���ʂ��o��
    if ((isEven(dice) && userGuess == 2) || (!isEven(dice) && userGuess == 1)) {
        std::cout << "�����I�T�C�R���̖ڂ� " << dice << " �ł��B\n";
    }
    else {
        std::cout << "�c�O�I�T�C�R���̖ڂ� " << dice << " �ł����B\n";
    }
}

int main() {
    diceGame();
    return 0;
}
