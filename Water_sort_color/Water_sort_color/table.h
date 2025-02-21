#pragma once
#include <iostream>
#define ROWS 3
#define COLS 1
#include <vector>

char rand_liquid();
void print_table(const std::vector<std::vector<char>>& bottles);
void instantiate_bottles(std::vector<std::vector<char>>& bottles);

