#pragma once
#include <list>
#include <iostream>
#include <mutex>
#include <algorithm>

namespace Lutz{
    template<typename Key>
    class Queue {
        protected:
            std::list<Key> queue;
            std::mutex queue_mutex;
            
            bool contains(Key key){
                return (std::find(queue.begin(), this->queue.end(), key) != this->queue.end());
            }
            
        public:
            Queue(){}

            void pop(){
                const std::lock_guard<std::mutex> lock(queue_mutex); 
                queue.pop_front();
            }
            
            void push(Key value){
                const std::lock_guard<std::mutex> lock(queue_mutex);
                if (!this->contains(value)) queue.push_back(value);
            }

            Key first(){
                const std::lock_guard<std::mutex> lock(queue_mutex); 
                return queue.front();
            }

            Key back(){
                const std::lock_guard<std::mutex> lock(queue_mutex); 
                return queue.back();
            }

            int size(){
                const std::lock_guard<std::mutex> lock(queue_mutex); 
                return queue.size();
            }

            bool empty(){
                if (!this->size()) return true;
                return false;
            }
    };
}