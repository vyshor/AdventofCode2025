struct Point {
    int64_t x;
    int64_t y;
    int64_t z;

    Point(string& line) {
        char comma;
        std::istringstream iss(line);
        iss >> x >> comma >> y >> comma >> z;
    }

    int64_t dist(Point& other) {
        return (x-other.x)*(x-other.x) + (y-other.y)*(y-other.y) + (z-other.z)*(z-other.z);
    }
};

int main() {
    string line;
    int n{0};
    vector<Point> points;
    vector<tuple<int64_t, int, int>> dists;

    constexpr int topN = 1000;

    while (true) {
        std::getline(std::cin, line);
        if (std::cin.eof()) break;

        points.emplace_back(line);
    }

    n = points.size();
    for (int i{0}; i < n-1; ++i) {
        for (int j{i+1}; j < n; ++j) {
            dists.emplace_back(points[i].dist(points[j]), i, j);
        }
    }

    vector<int> parents(n);
    vector<int> count(n, 1);

    std::iota(parents.begin(), parents.end(), 0);
    function<int(int)> find;
    find = [&parents, &find] (int i) -> int {
        if (parents[i] == i) return i;
        int new_parent = find(parents[i]);
        parents[i] = new_parent;
        return new_parent;
    };

    auto uni = [&parents, &count, &find] (int i, int j) {
        int parent_i = find(i);
        int parent_j = find(j);
        if (parent_i != parent_j) {
            parents[parent_j] = parent_i;
            count[parent_i] += count[parent_j];
            count[parent_j] = 0;
        }
    };

    std::partial_sort(dists.begin(), dists.end(), dists.begin()+topN);
    for (int i{0}; i < topN; ++i) {
        uni(std::get<1>(dists[i]), std::get<2>(dists[i]));
    }

    std::sort(count.begin(), count.end());

    int64_t ans = count[n-1]*count[n-2]*count[n-3];

    std::cout << "n: " << n << '\n';
    std::cout << "ans: " << ans << '\n';
    return 0;
}
