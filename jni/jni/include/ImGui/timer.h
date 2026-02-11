#ifndef TIMER_H
#define TIMER_H

#include <chrono>

// timer - Simple frame rate limiting and elapsed time tracking utility
class timer {
public:
    timer() : m_start(std::chrono::steady_clock::now()) {}

    // Reset the timer
    void reset() {
        m_start = std::chrono::steady_clock::now();
    }

    // Get elapsed time in milliseconds since last reset
    float elapsed_ms() const {
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration<float, std::milli>(now - m_start).count();
    }

    // Get elapsed time in seconds since last reset
    float elapsed() const {
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration<float>(now - m_start).count();
    }

    // Check if the specified interval (in ms) has passed, and reset if so
    bool tick(float interval_ms) {
        if (elapsed_ms() >= interval_ms) {
            reset();
            return true;
        }
        return false;
    }

private:
    std::chrono::steady_clock::time_point m_start;
};

#endif // TIMER_H
