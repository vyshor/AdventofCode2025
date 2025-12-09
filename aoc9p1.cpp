int main() {
    int64_t x, y;
    char comma;

    vector<pair<int64_t, int64_t>> points;
    while (true) {
        std::cin >> x;
        if (std::cin.eof()) break;
        std::cin >> comma >> y;
        points.emplace_back(x, y);
    }

    int n = points.size();
    int64_t maxx{0};
    for (int i{0}; i < n-1; ++i) {
        for (int j{i+1}; j < n; ++j) {
            auto [x1, y1] = points[i];
            auto [x2, y2] = points[j];

            maxx = max(maxx, (abs(x1-x2)+1)*(abs(y1-y2)+1));
        }
    }
    std::cout << "Max area:" << maxx << '\n';
    return 0;
}
