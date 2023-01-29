#pragma once

#include <string>

std::string get_name();

int write_to_file(const std::string &high_scores_filename, const std::string &user_name, const int &attempts_count);

int read_from_file(const std::string &high_scores_filename);