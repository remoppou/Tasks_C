#include <iostream>
#include <cmath>
using namespace std;

//Написать функцию вычисления обратной матрицы. Размер
//        матрицы задается с клавиатуры (не менее 4×4).

void input (double **array, int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            printf("\n Enter a[%d][%d]: ", r, c);
            cin >> array[r][c];
        }
    }
}

void output(double **array, int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            cout << array[r][c];
            cout << " ";
        }
        printf("\n");
    }
}

// Получение матрицы без i-й строки и j-го столбца
void getMatr(double **arr, double **p, int i, int j, int m) {
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki < m - 1; ki++) { // проверка индекса строки
         if (ki == i) di = 1;
         dj = 0;
         for (kj = 0; kj < m - 1; kj++) { // проверка индекса столбца
              if (kj == j) dj = 1;
              p[ki][kj] = arr[ki + di][kj + dj];
         }
    }
}

// Рекурсивное вычисление определителя
int determinant(double **arr, int m) {
    int i, j, d, k, n;
    double **p;
    p = new double *[m];
    for (i = 0; i<m; i++)
        p[i] = new double [m];
    j = 0; d = 0;
    k = 1; //(-1) в степени i
     n = m - 1;
     if (m < 1) cout << "Определитель вычислить невозможно!";
     if (m == 1) {
         d = arr[0][0];
         return d;
     }
     if (m == 2) {
         d = arr[0][0] * arr[1][1] - (arr[1][0] * arr[0][1]);
         return d;
     }
     if (m > 2) {
         for (i = 0; i < m; i++) {
             getMatr(arr, p, i, 0, m);
             d = d + k * arr[i][0] * determinant(p, n);
             k = -k;
         }
     }
     return d;
}

void algDop(double  **arr, int m) {
    int i, j, d, k, n;
    double **p, **z;
    p = new double *[m];
    z = new double *[m];
    for (i = 0; i < m; i++) {
        p[i] = new double [m];
        z[i] = new double [m];
    }
    if (m >= 2) {
        if (m == 2) {
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < m; c++) {
                    z[r][c] = pow(-1, r + c) * arr[m - r - 1][m - c - 1];
                }
            }
        }
        if (m > 2) {
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < m; c++) {
                    getMatr(arr, p, r, c, m);
                    int det = determinant(p, m - 1);
                    z[r][c] = pow(-1, r + c) * det;
                    if (z[r][c] == -0) {
                        z[r][c] =0;
                    }
                }
            }
        }
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < m; c++) {
                arr[r][c] = z[r][c];
            }
        }
    }
}

void transpose(double **arr, int size) {
    double t;
    for(int i = 0; i < size; ++i) {
        for(int j = i; j < size; ++j) {
            t = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = t;
        }
    }
}

void inverceMatrix (double **arr, int size, int det) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            arr[r][c] = arr[r][c] / det;
        }
    }
}

int main() {
    int size;
    // Размер
    cout << "Enter size: " << '\n';
    cin >> size;
    //Создание матрицы
    double **array;
    array = new double *[size];
    for (int r = 0; r < size; r++) {
        array[r] = new double [size];
    }
    //Ввод матрицы
    input(array, size);
    //Подсчет определителя
    int det = determinant(array, size);
    //Проверка определителя на 0
    if (det != 0) {
        cout << "det = " << det << "\n";
        if (size > 1) {
            algDop(array, size);
            transpose(array, size);
            inverceMatrix(array, size, det);
        }
        output(array, size);
    } else {
        cout << "det = 0, => there is no inverse matrix" << "\n";
        return 0;
    }
    return 0;
}