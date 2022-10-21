cmake_minimum_required(VERSION 3.5)

project(03.homework)

add_executable(
	guessing_game

	main.cpp
	argument.cpp
	check_guess.cpp
	random_value.cpp
	high_scores.cpp

	argument.h
	check_guess.h
	random_value.h
	high_scores.h
)

set_target_properties(
	guessing_game

	PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)