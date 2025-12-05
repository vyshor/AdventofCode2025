int main() {
    char dummy;
    int64_t start;
    int64_t end;
    int64_t ans{0};
    while (true) {
        std::cin >> start;
        std::cin >> dummy;
        std::cin >> end;

        // Makes more sense to bruteforce in this scenario
        // Than to consider all the edges cases with different digit length

        // std::cout << start << " " << end << '\n';
        for (int64_t i{start}; i < end+1; ++i) {
            auto s = std::to_string(i);
            int n = s.size();
            if (n == 1) continue;
            for (int length{1}; length <= n/2; ++length) {
                if ((n % length) != 0) continue;

                int all_same = 1;
                std::string_view s0(s.begin(), s.begin()+length);
                for (int j{length}; j+length <= n; j += length) {
                    std::string_view s1(s.begin()+j, s.begin()+j+length);
                    // std::cout << "s1=" << s1 << '\n';
                    if (s0 != s1) {
                        all_same = 0;
                        break;
                    }
                }

                if (all_same) {
                    ans += i;
                    // cout << ans << '\n';
                    break;
                }
            }
        }

        std::cin >> dummy;
        if (std::cin.eof()) break;
    }

    cout << "Answer: " << ans << '\n';
    return 0;
}
