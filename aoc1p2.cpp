int main() {
    int count{0};
    int pos{50};
    int val;
    int mod{100};
    char c;
    int prev_pos{50};
    while (true) {
        std::cin >> c;
        if (std::cin.eof()) break;
        std::cin >> val;

        count += (val / mod);
        val %= mod;

        if (c == 'L') val = -val;

        pos = pos + val;
        if (pos >= 100 || pos <= 0) {
            ++count;
            count -= (prev_pos == 0);
            pos = (pos + mod) % mod;
        }
        prev_pos = pos;

        // std::cout << count << '\n';
    }
    cout << "Password:" << count << '\n';
    return 0;
}
