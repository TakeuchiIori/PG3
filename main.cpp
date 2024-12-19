#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int current_thread = 1;

/// <summary>
/// thread1の処理
/// </summary>
void thread1() {
    std::unique_lock<std::mutex> lock(mtx); // ミューテックスをロックする
    cv.wait(lock, [] { return current_thread == 1; }); // 条件が満たされるまで待機
    std::cout << "thread 1" << std::endl; // メッセージを出力
    current_thread = 2; // 次のスレッドに進む
    cv.notify_all(); // 待機中のスレッドに通知する
}

/// <summary>
/// thread2の処理
/// </summary>
void thread2() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return current_thread == 2; });
    std::cout << "thread 2" << std::endl;
    current_thread = 3;
    cv.notify_all();
}

/// <summary>
/// thread3の処理
/// </summary>
void thread3() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return current_thread == 3; });
    std::cout << "thread 3" << std::endl;
    current_thread = 0;
    cv.notify_all();
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);
    std::thread t3(thread3);

    // 始めの初期化部分
    {
        std::unique_lock<std::mutex> lock(mtx);
        current_thread = 1;
        cv.notify_all();
    }

    // 各スレッドの解放
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
