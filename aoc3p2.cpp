int main() {
    std::string line;
    int64_t ans{0};
    while (true) {
        std::cin >> line;
        if (std::cin.eof()) break;

        int n = line.size();
        constexpr int target = 12;
        int removals = n - target;
        std::vector<int> stack;

        for (int ch: line) {
            ch -= 48;
            while (removals > 0 && stack.size() > 0 && stack.back() < ch) {
                stack.pop_back();
                --removals;
            }

            stack.push_back(ch);
        }

        for (int i{0}; i < removals; ++i) {
            stack.pop_back();
        }

        int64_t val{0};
        for (int i{0}; i < stack.size(); ++i) {
            val = val*10 + stack[i];
        }

        ans += val;
    }

    std::cout << "Answer: " << ans << '\n';
    return 0;
}
