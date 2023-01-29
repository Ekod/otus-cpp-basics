#include "argument.h"
#include "random_value.h"
#include "check_guess.h"
#include "high_scores.h"

int main(int argc, char **argv) {

    int exit_code = parse_cmd_arguments(argc, argv);
    if (exit_code != 0) {
        return exit_code;
    }

    std::string user_name = get_name();

    int computer_value = get_random_value();

    int attempts_count = check_guess(computer_value);

    const std::string high_scores_filename = "high_scores.txt";

    exit_code = write_to_file(high_scores_filename, user_name, attempts_count);
    if (exit_code != 0) {
        return exit_code;
    }

    exit_code = read_from_file(high_scores_filename);
    if (exit_code != 0) {
        return exit_code;
    }

    return 0;
}