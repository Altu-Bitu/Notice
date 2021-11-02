int main() {
    vector<vector<int>> fares = {{4, 1, 10},
                                 {3, 5, 24},
                                 {5, 6, 2},
                                 {3, 1, 41},
                                 {5, 1, 24},
                                 {4, 6, 50},
                                 {2, 4, 66},
                                 {2, 3, 22},
                                 {1, 6, 25}};
    int ans = solution(6, 4, 6, 2, fares);
    cout << ans;
}