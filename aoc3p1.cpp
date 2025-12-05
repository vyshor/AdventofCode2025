int main() {
    std::string line;
    int ans{0};
    while (true) {
        std::cin >> line;
        if (std::cin.eof()) break;

        int maxx{0};
        int cur_max{0};
        for (int ch: line) {
            ch -= 48;
            maxx = std::max(maxx, cur_max * 10 + ch);
            cur_max = std::max(cur_max, ch);
        }

        ans += maxx;
    }

    cout << "Answer: " << ans << '\n';
    return 0;
}

