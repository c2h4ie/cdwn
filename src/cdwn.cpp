#include "timers.hpp"
#include <boost/process.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <string>

namespace bp = boost::process;
namespace po = boost::program_options;

int main(int argc, char *argv[]) {
  po::options_description desc("Options");

  // clang-format off
  desc.add_options()
    ("help,h", "Print help messages")
    ("command,c", po::value<std::string>(), "Command to execute")
    ("time,t", po::value<std::string>(),"Time for countdown")
    ("stopwatch,s", "Start stopwatch");
  // clang-format on
  try {
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.empty() || vm.count("help")) {
      std::cout << desc << '\n';
    }

    if (vm.count("time")) {
      start_countdown(vm["time"].as<std::string>());
    }

    if (vm.count("stopwatch")) {
      start_timer();
    }

    if (vm.count("command")) {
      std::cout << '\n';
      bp::system(vm["command"].as<std::string>(), bp::std_out > stdout);
    }

  } catch (const po::error &e) {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
  }

  return 0;
}
