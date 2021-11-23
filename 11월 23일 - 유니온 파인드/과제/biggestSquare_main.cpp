int main() {
    vector<vector<int>> board = {{0, 1, 1, 1},
                                 {1, 1, 1, 1},
                                 {1, 1, 1, 1},
                                 {0, 0, 1, 0}};
    int ans = solution(board);
    cout << ans;
} 