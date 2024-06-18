#include "convert.hpp"
#include <cstdlib>
#include <format>
#include <iostream>

using namespace std::string_view_literals;

namespace colors {
constexpr std::string_view RED_BOLD = "\033[1;31m"sv;
constexpr std::string_view WHITE_BOLD = "\033[1;37m"sv;
constexpr std::string_view RESET = "\033[0m"sv;
} // namespace colors

void input_error() {
  std::cerr << "Options:\n"sv
            << "  cdwn -t 1h2m30s - count down specified time.\n"sv;
  std::exit(EXIT_FAILURE);
}

int input_to_sec(std::string_view input) {
  int seconds{};
  int curr{};

  for (const auto &c : input) {
    if (std::isdigit(c) != 0) {
      curr = curr * 10 + (c - '0');
    } else {
      switch (c) {
      case 'h':
        seconds += curr * 3600;
        break;
      case 'm':
        seconds += curr * 60;
        break;
      case 's':
        seconds += curr;
        break;
      default:
        input_error();
      }
      curr = 0;
    }
  }
  return seconds;
}

std::string sec_to_display(int input) {
  int hours{input / 3600};
  int minutes{(input % 3600) / 60};
  int seconds{input % 60};

  return std::format("{:02}:{:02}:{:02}"sv, hours, minutes, seconds);
}

void display_time(const std::string_view prefix, int time) {
  std::cout << std::format("{}{} {}{}{}"sv, colors::RED_BOLD, prefix,
                           colors::WHITE_BOLD, sec_to_display(time),
                           colors::RESET)
            << std::flush << '\r';
}
