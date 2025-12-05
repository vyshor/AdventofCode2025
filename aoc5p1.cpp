int main() {
    int64_t start;
    int64_t end;
    int n{0};
    char comma;
    int range_input{1};
    std::vector<std::pair<int64_t, int64_t>> fresh;
    int ans;

    while (true) {
        char p = std::cin.peek();
        if (std::cin.eof()) break;
        if (p == '\n') {
            std::cin.ignore(1, '\n');
            range_input = 0;

            // Transition
            // Process all the ranges
            n = fresh.size();
            // std::sort(fresh.begin(), fresh.end());
            continue;
        }

        if (range_input) {
            std::cin >> start;
            std::cin >> comma;
            std::cin >> end;
            std::cin.ignore(1, '\n');

            fresh.emplace_back(start, end);
            // std::cout << start << ',' << end << '\n';
        } else {
            std::cin >> start;
            std::cin.ignore(1, '\n');

            // Lets use bruteforce and not do range resolution,
            // range overlap simplification is overkill in this situation
            for (int i{0}; i < n; ++i) {
                if (fresh[i].first <= start && start <= fresh[i].second) {
                    ++ans;
                    break;
                }
            }
//             std::pair<int64_t, int64_t> item{start, start};
//             int idx = std::lower_bound(fresh.begin(), fresh.end(), item) - fresh.begin();

//             int found = 0;
//             if (idx > 0) {
//                 found |= start <= fresh[idx-1].second;
//             }
//             if (idx < n) {
//                 found |= start >= fresh[idx].first;
//             }
//             ans += found;
            // std::cout << start << '\n';
        }
    }

    std::cout << "Answer:" << ans << '\n';
    return 0;
}
