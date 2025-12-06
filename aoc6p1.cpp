int main() {
    
    int seek_num{1};
    int64_t num;
    char op;
    vector<int64_t> nums;
    vector<char> ops;
    
    while (true) {
        if (seek_num) {        
            std::cin >> num;
        } else {
            std::cin >> op;
        }
        
        if (std::cin.eof()) break;
        
        if (std::cin.fail()) {
            std::cin.clear();
            
            seek_num = 0;
            continue;
        }
        
        if (seek_num) {
            nums.push_back(num);
        } else {
            ops.push_back(op);
        }
    }
    
    cout << "Nums size: " << nums.size() << '\n';
    cout << "Ops size: "  << ops.size() << '\n';
    int cols = ops.size();
    int rows = nums.size() / ops.size();
    
    vector<int64_t> results(cols);
    for (int i{0}; i < cols; ++i) {
        results[i] = nums[i];
    }
    
    for (int i{0}; i < cols; ++i) {
        std::function<int64_t(int64_t, int64_t)> opt;
        if (ops[i] == '*') {
            opt = std::multiplies<int64_t>(); 
        } else if (ops[i] == '+') {
            opt = std::plus<int64_t>(); 
        } else {
            std::cout << "Invalid op:" << ops[i];
        }
        
        for (int j{1}; j < rows; ++j) {
            results[i] = opt(results[i], nums[j*cols+i]);
        }
    }
    
    int64_t summ{0};
    for (int i{0}; i < cols; ++i) {
        summ += results[i];
    }
    
    std::cout << "Ans: " << summ << '\n';
    return 0;
}
