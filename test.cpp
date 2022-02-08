#include "src/custom_queue.h"
#include <thread>

void thr1(Lutz::Queue<int>& queue){
    queue.push(2);
    queue.push(8);
    queue.push(13);
    queue.push(8);
    std::cout << "First: " << queue.first() << "\n" << "Last: " << queue.back() << "\n" << queue.empty() << "\n";
    queue.pop();
    queue.pop();

}


void thr2(Lutz::Queue<int>& queue){
    queue.push(9);
    queue.pop();
    std::cout << queue.first() << "\n";
}

int main(){
    Lutz::Queue<int> queue;
    
    std::thread thread1(thr1, std::ref(queue));
    std::thread thread2(thr2, std::ref(queue));

    thread1.join();
    thread2.join();
    std::cout << "First: "  <<  queue.first()  << "\n" << "Last: " << queue.back() << "\n" << queue.empty() << "\n";
    return 0;
}