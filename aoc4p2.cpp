int main() {
    std::string line;
    int m{0}, n{0};
    std::vector<std::vector<int>> grid;
    while (true) {
        std::cin >> line;
        if (std::cin.eof()) break;

        n = line.size();
        std::vector<int> row;
        row.reserve(n);
        for (char ch: line) {
            if (ch == '@') {
                row.push_back(1);
            } else {
                row.push_back(0);
            }
        }

        grid.push_back(std::move(row));
    }

    m = grid.size();
    std::vector<std::vector<int>> count(m, std::vector<int>(n, 0));
    std::vector<std::pair<int, int>> dirs{{-1, -1}, {-1,0}, {0, -1}, {0, 1}, {1, 0},{1,1}, {1, -1}, {-1, 1}};

    for (int i{0}; i < m; ++i) {
        for (int j{0}; j < n; ++j) {
            if (grid[i][j]) {
                for (auto [x, y]: dirs) {
                    x += i;
                    y += j;
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;

                    ++count[x][y];
                }
            }
        }
    }

    std::vector<std::pair<int, int>> q;
    for (int i{0}; i < m; ++i) {
        for (int j{0}; j < n; ++j) {
            if (grid[i][j] & (count[i][j] < 4)) {
                q.emplace_back(i, j);
            }
        }
    }

    int ans{0};
    while (q.size() > 0) {
        auto [i, j] = q.back();
        q.pop_back();
        ++ans;

        for (auto [x, y]: dirs) {
            x += i;
            y += j;
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) continue;

            --count[x][y];
            if (count[x][y] == 3) {
                q.emplace_back(x, y);
            }
        }
    }

    std::cout << "Answer: " << ans << '\n';
    return 0;
}
