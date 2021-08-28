#include <bits/stdc++.h>

using namespace std;

bool impossible(vector<int>& rows, vector<int>& cols) {
    for (int i=0; i<rows.size(); i++)
        if (rows[i]!=-1 || cols[i]!=-1)
            return false;
    return true;
}

int posmin_vector(vector<int>& vec) {
    int mn = vec.size();
    for (int& x: vec)
        if (x > 0)
            mn = min(mn, x);
    return mn;
}

int main() {
    //freopen("./input.txt", "r", stdin);
    //freopen("./output.txt", "w", stdout);

    int t, n;
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        vector<string> grid(n);
        for (string& row: grid)
            cin >> row;


        vector<int> rows(n, 0), cols(n, 0);
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                if (grid[j][k] == 'O') {
                    rows[j] = -1;
                    cols[k] = -1;
                } else if (grid[j][k] == '.') {
                    if (rows[j] != -1) ++rows[j];
                    if (cols[j] != -1) ++cols[j];
                }
            }
        }

        if (impossible(rows, cols)) {
            cout << "Case #" << i << ": Impossible\n";
            continue;
        }

        int min_rows = posmin_vector(rows);
        int min_cols = posmin_vector(cols);
        int min_to_win = min(min_cols, min_rows);
        int count = 0;
        for (int j=0; j<n; j++) {
            if (rows[j] == min_to_win) {
                grid[j] = string('X', n);
                ++count;
            }
        }

        for (int j=0; j<n; j++) {
            if (cols[j] == min_to_win) {
                ++count;
                for (int k=0; k<n; k++) {
                    if (grid[k][j] == '.')
                        break;
                    if (k == n-1)
                        --count;
                }
            }
        }

        cout << "Case #" << i << ": " << min_to_win << ' ' << count << endl;
    }
    return 0;
}
