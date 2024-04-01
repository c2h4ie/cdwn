#include "timers.hpp"
#include "convert.hpp"
#include <chrono>
#include <string_view>
#include <thread>

using namespace std::string_view_literals;

void start_countdown(const std::string_view seconds) {
  for (auto remaining{input_to_sec(seconds)}; remaining > 0; --remaining) {
    display_time("Counting down:"sv, remaining);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

void start_timer() {
  for (auto seconds_passed{0};; ++seconds_passed) {
    display_time("Time Elapsed:"sv, seconds_passed);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
