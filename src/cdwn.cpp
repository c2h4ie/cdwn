#include "timers.hpp"
#include <print>
#include <string>
#include <vector>

constexpr void print_help() {
  std::println(R"(Options:
  --help, -h         Print help messages
  --time, -t         Time for countdown
  --stopwatch, -s    Start stopwatch)");
}

int main(int argc, char *argv[]) {
  std::vector<std::string> args(argv + 1, argv + argc);

  for (size_t i{0}; i < args.size(); ++i) {
    if (args[i] == "-h" || args[i] == "--help") {
      print_help();
    } else if (args[i] == "-t" || args[i] == "--time") {
      if (i + 1 < args.size()) {
        start_countdown(args[++i]);
      }
    } else if (args[i] == "-s" || args[i] == "--stopwatch") {
      start_stopwatch();
    }
  }
}
