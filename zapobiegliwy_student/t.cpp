#include <iostream>
#include <vector>
#include <algorithm>

struct Lecture {
    int start, end, index;
};

bool compareLectures(const Lecture &a, const Lecture &b) {
    return a.end < b.end;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Lecture> lectures(n);

    for (int i = 0; i < n; i++) {
        std::cin >> lectures[i].start >> lectures[i].end;
        lectures[i].index = i + 1;
    }

    std::sort(lectures.begin(), lectures.end(), compareLectures);

    std::vector<int> dp(n, 1);
    std::vector<int> prev(n, -1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (lectures[i].start >= lectures[j].end && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
    }

    int max_lectures = *std::max_element(dp.begin(), dp.end());
    std::cout << max_lectures << std::endl;

    std::vector<int> selected_lectures;
    int current_lecture = std::distance(dp.begin(), std::max_element(dp.begin(), dp.end()));
    while (current_lecture >= 0) {
        selected_lectures.push_back(lectures[current_lecture].index);
        current_lecture = prev[current_lecture];
    }

    std::reverse(selected_lectures.begin(), selected_lectures.end());
    for (int lecture : selected_lectures) {
        std::cout << lecture << " ";
    }

    return 0;
}
