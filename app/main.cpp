#include <chrono>
#include <iostream>

#include "concurrent/thread_pool.h"
#include "core/executor.h"
#include "core/func_register.h"

void kernel1(KernelFrame* frame) {
    auto val1 = frame->GetInput<int>(0);
    std::cout << "Kernel1 val: " << val1 << std::endl;
    frame->SetOutput(static_cast<float>(val1 * 2));
}

void kernel2(KernelFrame* frame) {
    auto val1 = frame->GetInput<int>(0);
    std::cout << "Kernel2 val: " << val1 << std::endl;
    frame->SetOutput(static_cast<float>(val1 * 2));
}

void kernel3(KernelFrame* frame) {
    auto val1 = frame->GetInput<int>(0);
    std::cout << "Kernel3 val: " << val1 << std::endl;
}

int main() {
    Graph graph;
    auto ptr1 = new TaskNode{{}, &kernel1, ""};
    auto ptr2 = new TaskNode{{""}, &kernel2, "kernel2"};
    auto ptr3 = new TaskNode{{"kernel2"}, &kernel3, "kernel3"};
    ptr1->AddSuccessor(ptr2);
    ptr2->AddSuccessor(ptr3);
    graph.AddNode(ptr1);
    graph.AddNode(ptr2);
    graph.AddNode(ptr3);
    graph.Build();

    auto results = graph.Run();
    std::this_thread::sleep_for(std::chrono::seconds(2));
}