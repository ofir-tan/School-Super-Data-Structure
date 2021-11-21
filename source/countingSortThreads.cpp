#include <iostream>
#include "vector"
#include <thread>
#include "algorithm"
#include "Timer.h"
using namespace std;

void countingSort(const vector<int> &nums, vector<int> &histogram, int start, int end) {
    for (int i = start; i < end && i < nums.size(); i++)
        histogram[nums[i]]++;
}

int countingSortThreaded(int argc, char *argv[]) {
    int size = 10000000;
    int NUM_OF_THREADS = 4;
    vector<int> nums;
    nums.reserve(size);
    for(int i = 0; i < size; i++) nums.push_back(rand() % size);
    Timer timer("counting sort");
    // create "histograms":
    vector<vector<int>> histograms(NUM_OF_THREADS);
    for (auto &hist: histograms)
        hist = vector<int>(size, 0);

    int n = nums.size();
    std::thread threads[NUM_OF_THREADS];
    for (int i = 0, j = 0; i < n; i += n / NUM_OF_THREADS)
        threads[j++] = thread(countingSort, ref(nums), ref(histograms[j]), i, i + n / NUM_OF_THREADS);

    // join threads:
    for (auto &t: threads)
        if(t.joinable())
            t.join();

    for (int i = 0; i < size; i++)
        for(int j = 1; j < NUM_OF_THREADS; ++j)
            histograms[0][i] += histograms[j][i];

    vector<int> res;
    res.reserve(size);
    for (int i = 0; i < size; i++)
        while(histograms[0][i]--) res.push_back(i);

    //for_each(res.begin(), res.end(), [](int i ) { cout << i << " ";});

    return 0;
}