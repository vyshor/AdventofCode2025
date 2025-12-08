int main() {
    string line;
    int n{0};
    int init{0};
    int64_t count{0};
    vector<int64_t> channels;
    while (true) {
        std::getline(std::cin, line);
        if (std::cin.eof()) break;
        if (!init) {
            init = 1;
            n = line.size();
            channels = vector<int64_t>(n, 0);
            for (int i{0}; i < n; ++i) {
                if (line[i] == 'S') channels[i] = 1;
            }
            continue;
        }

        vector<int64_t> new_channels(n, 0);
        for (int i{0}; i < n; ++i) {
            if (line[i] == '.' && channels[i] > 0) new_channels[i] += channels[i];
            if (line[i] == '^' && channels[i] > 0) {
                new_channels[i-1] += channels[i];
                new_channels[i+1] += channels[i];
            }
        }
        channels.swap(new_channels);
    }

    for (int i{0}; i < n; ++i) {
        count += channels[i];
    }

    std::cout << "Paths: " << count << '\n';
    return 0;
}