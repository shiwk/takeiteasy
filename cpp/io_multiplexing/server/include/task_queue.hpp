//
// Created by shiwk on 2021/4/9.
//

#ifndef CPP_TASK_QUEUE_HPP
#define CPP_TASK_QUEUE_HPP

#include <queue>
template <typename T>
class TaskQueue {
private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
public:
    TaskQueue() =default;
    ~TaskQueue() =default;


    bool empty() {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.empty();
    }

    int size() {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.size();
    }

    void enqueue(T t) {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.push(std::move(t));
    }

    bool dequeue(T& t) {
        std::unique_lock<std::mutex> lock(m_mutex);

        if (m_queue.empty()) {
            return false;
        }
        t = std::move(m_queue.front());

        m_queue.pop();
        return true;
    }

};
#endif //CPP_TASK_QUEUE_HPP
