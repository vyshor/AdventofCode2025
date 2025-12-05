int main() {
    int64_t start;
    int64_t end;
    int n{0};
    char comma;
    std::vector<std::pair<int64_t, int64_t>> fresh;

    while (true) {
        char p = std::cin.peek();
        if (std::cin.eof()) break;
        if (p == '\n') {
            break;
        }

        std::cin >> start;
        std::cin >> comma;
        std::cin >> end;
        std::cin.ignore(1, '\n');

        fresh.emplace_back(start, end);
    }

    // Overlapping range simplification
    std::sort(fresh.begin(), fresh.end());
    n = fresh.size();
    int64_t ans{0};
    start = fresh[0].first;
    end = fresh[0].second;
    for (int i{1}; i < n; ++i) {
        if (fresh[i].first <= end) {
            end = std::max(end, fresh[i].second);
        } else {
            ans += end-start+1;
            start = fresh[i].first;
            end = fresh[i].second;
        }
    }
    ans += end-start+1;

    std::cout << "Answer:" << ans << '\n';
    return 0;
}
