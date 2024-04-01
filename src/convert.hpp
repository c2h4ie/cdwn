#pragma once

#include <string_view>

void input_error();
int input_to_sec(std::string_view input);
std::string sec_to_display(int input);
void display_time(const std::string_view prefix, int time);
