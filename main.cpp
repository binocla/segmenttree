
#include<bits/stdc++.h>
#include <chrono>
using namespace std;

#define MAX 100010

int tree[MAX];
vector<int> ar;

void showSegTree(int n) {
    int i, j, h = ceil(log2(n));
    for(i=0 ; i<=h ; ++i) {
        for(j=0 ; j<pow(2, i) ; ++j)
            cout<<tree[int(pow(2, i)-1 + j)]<<' ';
        cout<<endl;
    }
}

/* Рекурсивный конструктор дерева.
   На каждой ноде, если это не лист - создаются два дочерних узла. Иначе нода равна элементу. strt и end - начало и конец,
   idx - индекс дерева */
int constSegTree(int strt, int end, int idx) {
    if(strt == end)
        return tree[idx] = ar[strt];

    int mid = (strt + end) / 2;
    return tree[idx] = constSegTree(strt, mid, 2*idx+1) +
                       constSegTree(mid+1, end, 2*idx+2);
}
void constSegTree(int n) {
    constSegTree(0, n-1, 0);
}

/* Сумма от strt до end */
int getSum(int strt, int end, int l, int r, int idx) {
    if(strt <= l && r <= end)
        return tree[idx];

    if(end < l || r < strt || l > r)
        return 0;

    int mid = (l + r) / 2;
    return getSum(strt, end, l, mid, 2*idx+1) +
           getSum(strt, end, mid+1, r, 2*idx+2);
}
int getSum(int n, int strt, int end) {
    return getSum(strt, end, 0, n-1, 0);
}

/* Апдейт ноды после изменения */
void updtNode(int pos, int val, int l, int r, int idx) {
    // Если позиция не в пределах нодов
    if(pos < l || r < pos)
        return;

    // Все обновляем
    tree[idx] += val;

    // Если лист?
    if(l == r)  return;    // Выходим

    int mid = (l + r) / 2;
    updtNode(pos, val, l, mid, 2*idx+1);
    updtNode(pos, val, mid+1, r, 2*idx+2);
}
void updtNode(int n, int pos, int val) {
    updtNode(pos, val, 0, n-1, 0);
}
int func(int a, int b, int cnt) {
    for (int j = 0; j < ar.size(); ++j) {
        if (j >= a && j <= b) {
            cnt = cnt + ar[j];
        }
    }
    return cnt;
}

int main() {
    clock_t start1, end1;
    ofstream myfile;
    for (int i = 0; i < 1000; ++i) {

        int n = 145;
        ar = {rand() % 223 + 100000, rand() % 15 + 300, rand() % 100 + 50000, rand() % 111 + 42001, rand() % 123 + 440044,
              rand() % 521 + 100000, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 213000, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 125, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 9999, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 223 + 100000, rand() % 15 + 300, rand() % 100 + 50000, rand() % 111 + 42001, rand() % 123 + 440044,
              rand() % 521 + 100000, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 213000, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 125, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 9999, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 223 + 100000, rand() % 15 + 300, rand() % 100 + 50000, rand() % 111 + 42001, rand() % 123 + 440044,
              rand() % 521 + 100000, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 213000, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 125, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 9999, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 223 + 100000, rand() % 15 + 300, rand() % 100 + 50000, rand() % 111 + 42001, rand() % 123 + 440044,
              rand() % 521 + 100000, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 213000, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 125, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 9999, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 223 + 100000, rand() % 15 + 300, rand() % 100 + 50000, rand() % 111 + 42001, rand() % 123 + 440044,
              rand() % 521 + 100000, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 213000, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 125, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 9999, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 223 + 100000, rand() % 15 + 300, rand() % 100 + 50000, rand() % 111 + 42001, rand() % 123 + 440044,
              rand() % 521 + 100000, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 213000, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 125, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002,
              rand() % 521 + 9999, rand() % 17 + 320013, rand() % 202 + 12003, rand() % 4 + 5000, rand() % 22 + 5100002};
        myfile.open("data.txt", ios::app);
        for (int j : ar) {
            myfile << j << " ";
        }
        myfile.close();

        constSegTree(n);

        showSegTree(n);
        int v1 = rand() % 145;
        int v2 = rand() % 145;
        int min = std::min(v1, v2);
        int max = std::max(v1, v1);
        if (min == max) {
            max++;
        }
        auto start = std::chrono::high_resolution_clock::now();
        cout << "Сумма от [" << min << ".." << max << "] " << getSum(n, min, max) << endl;
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = duration_cast<std::chrono::microseconds>(stop - start);
        cout << "Микросекунды на выполнение суммирования деревом отрезков: " << duration.count() << endl;
        int a = min;
        int b = max;
        int cnt = 0;
        start1 = clock();
        cnt = func(a, b, cnt);
        end1 = clock();
        double x = double (end1 - start1) / double (CLOCKS_PER_SEC);
        cout << cnt << endl;
        cout << "Микросекунды на выполнение обычного суммирования циклом: " << x << setprecision(9) << endl;
    }

    return 0;
}