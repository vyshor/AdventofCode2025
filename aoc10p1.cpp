int main() {
    char ch;
    string line;
    int count{0};
    int lines_processed{0};
    while (true) {
        std::getline(std::cin, line);
        if (std::cin.fail()) break;
        std::istringstream iss(line);

        int n{0};
        int state{0};
        int target{0};
        iss >> ch;
        while (true) {
            iss >> ch;
            if (ch == ']') break;
            target |= ((ch == '#') << n);
            ++n;
        }
        // std::cout << "n=" << n << '\n';

        vector<std::pair<int, int>> paths;
        vector<int> joltages;
        joltages.reserve(n);

        while (true) {
            iss >> ch;
            if (ch == ' ') continue;

            if (ch == '(') {
                int flip{0};
                int pos;
                while (true) {
                    iss >> pos;
                    // std::cout << "Pos:" << pos << '\n';
                    flip |= (1 << pos);
                    iss >> ch;
                    if (ch == ')') break;
                }
                paths.emplace_back(flip, 1);
            } else if (ch == '{') {
                int joltage;
                while (true) {
                    iss >> joltage;
                    joltages.push_back(joltage);
                    iss >> ch;
                    if (ch == '}') break;
                }
                break;
            }
        }

        // Process the Djistra
        unordered_set<int> visited;
        vector<std::pair<int, int>> q;
        q.emplace_back(0, state);

        while (q.size() > 0) {
            // std::cout << "Q size:" << q.size() << '\n';
            std::pop_heap(q.begin(), q.end());
            auto [cost, new_state] = q.back();
            q.pop_back();

            if (new_state == target) {
                count -= cost;
                // std::cout << "Added cost:" << cost << '\n';
                ++lines_processed;
                break;
            }

            if (visited.contains(new_state)) continue;
            visited.insert(new_state);

            for (auto [flip, extra_cost]: paths) {
                int next_state = new_state ^ flip;
                if (visited.contains(next_state)) continue;
                q.emplace_back(cost-extra_cost, next_state);
                std::push_heap(q.begin(), q.end());
            }
        }
    }

    std::cout << "Total cost:" << count << '\n';
    std::cout << "Total lines:" << lines_processed << '\n';
}
