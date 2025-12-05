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
            if ((n & 1) == 1) continue;
            std::string_view s0(s.begin(), s.begin()+n/2);
            std::string_view s1(s.begin()+n/2, s.end());
            if (s0 == s1) ans += i;
        }

        std::cin >> dummy;
        if (std::cin.eof()) break;
    }

    cout << "Answer: " << ans << '\n';
    return 0;
}
