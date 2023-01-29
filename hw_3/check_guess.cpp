#include <iostream>

int check_guess(const int target_value) {

    int current_value = 0;
    bool not_win = true;
    int attempts_count = 1;

    std::cout << "Enter your guess:" << std::endl;

    do {
        std::cin >> current_value;

        if (current_value < target_value) {
            std::cout << "Your number is less than mine" << std::endl;
            attempts_count++;
        } else if (current_value > target_value) {
            std::cout << "Your number is greater than mine" << std::endl;
            attempts_count++;
        } else {
            std::cout << "You are correct! You win! Number of attempts = " << attempts_count << std::endl;
            not_win = false;
        }

    } while (not_win);

    return attempts_count;
}