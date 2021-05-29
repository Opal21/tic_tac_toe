#pragma once

#include <fstream>
#include <cassert>
#define assertm(exp, msg) assert(((void)msg, exp))

void save_header(std::ofstream& stream, const char* header, int length);
bool check_header(std::istream& stream, const char* header, int length);