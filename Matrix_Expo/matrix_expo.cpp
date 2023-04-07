const int mod = 1e9 + 7;

vector<vector<int>> mult_mat(vector<vector<int>> &a, vector<vector<int>> &b) {
    int x = a.size(), y1 = a[0].size(), y2 = b.size(), z = b[0].size();

    if(y1 != y2) {
        return {};
    }

    vector<vector<int>> ans(x, vector<int>(z, 0));

    for(int i = 0; i < x; ++i) {
        for(int j = 0; j < z; ++j) {
            int val = 0;
            
            for(int k = 0; k < y1; ++k) {
                val = ((long long)val + ((long long)a[i][k] * b[k][j]) % mod) % mod;
            }

            ans[i][j] = val;
        }
    }

    return ans;
}

vector<vector<int>> gen_identity_mat(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));

    for(int i = 0; i < n; ++i) {
        ans[i][i] = 1;
    }

    return ans;
}

vector<vector<int>> matrix_exp(vector<vector<int>> &mat, int p) {

    if(mat.empty() || mat.size() != mat[0].size()) {
        return {};
    }

    vector<vector<int>> ans = gen_identity_mat(mat.size());
    vector<vector<int>> prod = mat;

    while(p) {
        if(p & 1) {
            ans = mult_mat(ans, prod);
        }
        
        prod = mult_mat(prod, prod);        
        
        p = p >> 1;
    }

    return ans;
}

int fibonacciNumber(int n) {

    if(n <= 2) {
        return 1;
    }
    
    vector<vector<int>> mat = {{1, 1}, {1, 0}};
    vector<vector<int>> init_mat = {{1}, {1}};
    
    auto exp_mat = matrix_exp(mat, n - 2);
    
    auto ans = mult_mat(exp_mat, init_mat);

    if(ans.empty()) {
        return -1;
    }

    return ans[0][0];
}
