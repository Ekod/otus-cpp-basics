// Read files and prints top k word by frequency

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>

const size_t TOPK = 10;

using Counter = std::map<std::string, std::size_t>;

std::string tolower(const std::string &str);

void count_words(std::istream& stream, Counter&);

void print_topk(std::ostream& stream, const Counter&, const size_t k);

std::mutex mutex{};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: topk_words [FILES...]\n";
        return EXIT_FAILURE;
    }

    auto start = std::chrono::high_resolution_clock::now();
    Counter freq_dict;
    std::vector<std::thread> threadVec;
    for (int i = 1; i < argc; ++i) {
        std::ifstream input{argv[i]};
        if (!input.is_open()) {
            std::cerr << "Failed to open file " << argv[i] << '\n';
            return EXIT_FAILURE;
        }
        threadVec.emplace_back([input = std::move(input), &freq_dict]() mutable {
            count_words(input, freq_dict);
        });
    }

    for(auto &thread : threadVec){
        thread.join();
    }

    print_topk(std::cout, freq_dict, TOPK);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed time is " << elapsed_ms.count() << " us\n";
}

std::string tolower(const std::string &str) {
    std::string lower_str;
    std::transform(std::cbegin(str), std::cend(str),
                   std::back_inserter(lower_str),
                   [](unsigned char ch) { return std::tolower(ch); });
    return lower_str;
};

void count_words(std::istream& stream, Counter& counter) {
    std::map<std::string, std::size_t> local;
    std::for_each(std::istream_iterator<std::string>(stream),
                  std::istream_iterator<std::string>(),
                  [&local](const std::string &s) {
        ++local[tolower(s)];
    });

    mutex.lock();
    for(const auto &item : local){
        counter[item.first] += item.second;
    }
    mutex.unlock();
}

void print_topk(std::ostream& stream, const Counter& counter, const size_t k) {
    std::vector<Counter::const_iterator> words;
    words.reserve(counter.size());
    for (auto it = std::cbegin(counter); it != std::cend(counter); ++it) {
        words.push_back(it);
    }

    std::partial_sort(
            std::begin(words), std::begin(words) + k, std::end(words),
            [](auto lhs, auto &rhs) { return lhs->second > rhs->second; });

    std::for_each(
            std::begin(words), std::begin(words) + k,
            [&stream](const Counter::const_iterator &pair) {
                stream << std::setw(4) << pair->second << " " << pair->first
                       << '\n';
            });
}