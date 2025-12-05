int main() {
    int count{0};
    int pos{50};
    int val;
    int mod{100};
    char c;
    while (true) {
        std::cin >> c;
        if (std::cin.eof()) break;
        std::cin >> val;

        if (c == 'L') val = -val;
        pos = (pos + val + mod) % mod;
        count += (pos == 0);
    }
    cout << "Password:" << count << '\n';
    return 0;
}
