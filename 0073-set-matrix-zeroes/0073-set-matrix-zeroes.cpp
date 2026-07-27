class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        // extra space ;
        //     int m = matrix.size();
        //     int n = matrix[0].size();
        //     vector<int> row(m, 0);
        //     vector<int> col(n, 0);
        //     for (int i = 0; i < m; i++) {
        //         for (int j = 0; j < n; j++) {
        //             if (matrix[i][j] == 0) {
        //                 row[i] = 1;
        //                 col[j] = 1;
        //             }
        //         }
        //     }
        //    for(int i = 0; i < row.size(); i++){
        //       if(row[i]==1){
        //        int j = 0;
        //        while(j < n){
        //          matrix[i][j] = 0;
        //           j++;
        //        }
        //       }
        //    }
        //     for(int i = 0; i < col.size(); i++){
        //       if(col[i]==1){
        //        int j = 0;
        //        while(j < m){
        //          matrix[j][i] = 0;
        //           j++;
        //        }
        //       }
        //    }

        int m = matrix.size();
        int n = matrix[0].size();
        bool firstCol = false;

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0)
                firstCol = true;
        }
        bool isFirstIndexAffected = false;
        if(matrix[0][0] == 0) isFirstIndexAffected = true;
 
        // vector<int> row(m, 0);
        // vector<int> col(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                int j = 1;
                while (j < n) {
                    matrix[i][j] = 0;
                    j++;
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (matrix[0][i] == 0) {
                int j = 1;
                while (j < m) {
                    matrix[j][i] = 0;
                    j++;
                }
            }
        }
if (matrix[0][0] == 0) {
    for (int j = 0; j < n; j++) {
        matrix[0][j] = 0;
    }
}
        if (firstCol) {
    for (int i = 0; i < m; i++) {
        matrix[i][0] = 0;
    }
}
    }
};