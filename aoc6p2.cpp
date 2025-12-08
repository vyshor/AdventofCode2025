int main() {
    string line;
    vector<string> lines;

    while (true) {
        std::getline(std::cin, line);
        if (std::cin.eof()) break;

        lines.push_back(line);
    }

    string ops_line = std::move(lines.back());
    lines.pop_back();
    int rows = lines.size();
    int cols = ops_line.size();
    function<int64_t(int64_t, int64_t)> op = std::plus<int64_t>();
    int64_t total = 0;
    int64_t cumulative = 0;
    for (int i{0}; i < cols; ++i) {
        if (ops_line[i] == '+') {
            op = std::plus<int64_t>();
            total += cumulative;
            cumulative = 0;
        } else if (ops_line[i] == '*') {
            op = std::multiplies<int64_t>();
            total += cumulative;
            cumulative = 1;
        }

        int64_t val = 0;
        for (int j{0}; j < rows; ++j) {
            if (lines[j][i] != ' ') {
                val = val * 10 + (lines[j][i] - 48);
            }
        }
        // cout << val << '\n';
        if (val == 0) continue;
        cumulative = op(cumulative, val);
    }
    total += cumulative;
    std::cout << "Total: " << total << '\n';

    return 0;
}
