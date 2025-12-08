int main() {
    string line;
    int n{0};
    int init{0};
    int count{0};
    vector<int> channels;
    while (true) {
        std::getline(std::cin, line);
        if (std::cin.eof()) break;
        if (!init) {
            init = 1;
            n = line.size();
            channels = vector<int>(n, 0);
            for (int i{0}; i < n; ++i) {
                if (line[i] == 'S') channels[i] = 1;
            }
            continue;
        }

        vector<int> new_channels(n, 0);
        for (int i{0}; i < n; ++i) {
            if (line[i] == '.' && channels[i]) new_channels[i] = 1;
            if (line[i] == '^' && channels[i]) {
                ++count;
                new_channels[i-1] = 1;
                new_channels[i+1] = 1;
            }
        }
        channels.swap(new_channels);
    }

    std::cout << "Splits: " << count << '\n';
    return 0;
}
