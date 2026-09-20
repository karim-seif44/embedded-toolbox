#pragma once
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <string>
#include <utility>

namespace toolbox {

class ScopedTimer {
public:
    using Report = std::function<void(std::int64_t)>;   // like a C typedef for a callback

    // If no callback is given, just print the time.
    explicit ScopedTimer(std::string label, Report report = {})
        : label_(std::move(label)),
          report_(std::move(report)),
          start_(std::chrono::steady_clock::now()) {}

    ~ScopedTimer() {
        const std::int64_t us = elapsed_us();
        if (report_) {
            report_(us);                                  // call the callback
        } else {
            std::printf("%s: %lld us\n", label_.c_str(), static_cast<long long>(us));
        }
    }

    ScopedTimer(const ScopedTimer&) = delete;             // one timer = one measurement
    ScopedTimer& operator=(const ScopedTimer&) = delete;

    std::int64_t elapsed_us() const {
        using namespace std::chrono;
        return duration_cast<microseconds>(steady_clock::now() - start_).count();
    }

    const std::string& label() const { return label_; }

private:
    std::string label_;
    Report report_;
    std::chrono::steady_clock::time_point start_;
};

}  // namespace toolbox
