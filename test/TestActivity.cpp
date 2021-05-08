//
// Created by djnic on 03.05.2021.
//

#include "TestActivity.h"
#include <chrono>
#include <thread>

void TestActivity::perform() {
    int id = registerTask();
    std::this_thread::sleep_for(std::chrono::seconds(2));//rand() % 5));
    closeTask(id);
}
