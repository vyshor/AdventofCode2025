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

        auto serialize_vec = [] (vector<int>& arr) -> std::string {
            std::stringstream ss;
            for (int num: arr) {
                ss << num << ',';
            }
            return ss.str();
        }

        // Process the Djistra
        unordered_map<std::string, int> costs;
        unordered_map<std::string, vector<int>> all_states;

        q.emplace_back(std::move(serialize_vec(joltages)), joltages);

        for (auto [flip, extra_cost]: paths) {
            unordered_set<std::string> visited;
            vector<std::tuple<std::string, vector<int>, int>> q;

            for (int i{0}; i < n; ++i) {
                if (((flip >> i) & 1) == 1)
            }
            int next_state = new_state ^ flip;
            if (visited.contains(next_state)) continue;
            q.emplace_back(cost-extra_cost, next_state);
            std::push_heap(q.begin(), q.end());
        }


        while (q.size() > 0) {
            auto& [str_state, arr_state, cost] = q.back();
            q.pop_back();

            if (visited.contains(str_state)) continue;
            visited.insert(str_state);

        }
    }

    std::cout << "Total cost:" << count << '\n';
    std::cout << "Total lines:" << lines_processed << '\n';
}
