#include <iostream>
#include <vector>

using namespace std;

int parent_node[10]; // 用來找老大的陣列 (Union-Find)
int U[100], V[100];  // 存所有的邊
int E = 0;           // 邊的總數

// Union-Find：尋找這個點的根節點 (老大)
int find_root(int x) {
    if (parent_node[x] == x) return x;
    return parent_node[x] = find_root(parent_node[x]);
}

vector<int> tree_adj[10];     // 只存「樹」的連線
int cycle1[10][10] = {0};     // 紀錄第一個 cycle 走過的邊
int cycle2[10][10] = {0};     // 紀錄第二個 cycle 走過的邊

// 簡單的 DFS 找樹上的路徑，找到終點就把沿路的邊標記為 1
bool find_path(int curr, int target, int p, int cycle_map[10][10]) {
    if (curr == target) return true; // 走到終點了
    
    for (int i = 0; i < tree_adj[curr].size(); i++) {
        int nxt = tree_adj[curr][i];
        if (nxt != p) { // 不要走回頭路
            if (find_path(nxt, target, curr, cycle_map)) {
                // 如果這條路能通往終點，就把這條邊做記號
                cycle_map[curr][nxt] = 1;
                cycle_map[nxt][curr] = 1;
                return true;
            }
        }
    }
    return false;
}

int main() {
    // 提升 I/O 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int u, v;
    while (cin >> u && u != -1) {
        cin >> v;
        U[E] = u;
        V[E] = v;
        E++;
    }

    // 初始化 Union-Find：一開始每個點的老大都是自己
    for (int i = 1; i <= n; i++) {
        parent_node[i] = i;
    }

    int tree_edges_count = 0;
    vector<int> back_u, back_v; // 存多出來的邊

    // 建立 Spanning Tree，並過濾出多出來的邊
    for (int i = 0; i < E; i++) {
        int root_u = find_root(U[i]);
        int root_v = find_root(V[i]);

        if (root_u != root_v) {
            // 老大不同，代表不會形成迴圈，這是一條「樹的邊」
            parent_node[root_u] = root_v; // 認老大 (合併)
            tree_adj[U[i]].push_back(V[i]);
            tree_adj[V[i]].push_back(U[i]);
            tree_edges_count++;
        } else {
            // 老大相同，代表連起來會形成迴圈，這是「多出來的邊」
            back_u.push_back(U[i]);
            back_v.push_back(V[i]);
        }
    }

    // 判斷 1: 如果樹的邊數量少於 n-1，代表有些點沒連在一起 (不連通)
    if (tree_edges_count < n - 1) {
        cout << "n\n";
        return 0;
    }

    // 判斷 2: 算 cycle 數量 (多出來的邊有幾條，就有幾個 fundamental cycle)
    int M = back_u.size();

    if (M < 2) {
        cout << "n\n";
        return 0;
    }

    // 只要連通且 cycle >= 2，第一行必定印 y
    cout << "y\n";

    // 判斷 3: 如果 cycle >= 3 個，直接印出來
    if (M >= 3) {
        cout << "There are at least three cycles.\n";
        return 0;
    }

    // 判斷 4: 剛好 2 個 cycle (M == 2)，檢查有沒有共用邊
    // 在樹上分別找出這兩條多出來的邊能接成的完整迴圈
    find_path(back_u[0], back_v[0], -1, cycle1);
    find_path(back_u[1], back_v[1], -1, cycle2);

    // 掃描二維陣列，檢查有沒有哪一條邊是兩個 cycle 都有標記到 1 的
    bool overlap = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cycle1[i][j] == 1 && cycle2[i][j] == 1) {
                overlap = true;
            }
        }
    }

    // 如果有共用邊，代表可以組合出第三個 cycle
    if (overlap) {
        cout << "There are at least three cycles.\n";
    }

    return 0;
}