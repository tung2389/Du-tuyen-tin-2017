struct Node {
    int lazy; // gi� tr? T trong ph�n t�ch tr�n
    int val; // gi� tr? l?n nh?t.
} nodes[MAXN * 4];

void down(int id) {
    int t = nodes[id].lazy;
    nodes[id*2].lazy += t;
    nodes[id*2].val += t;

    nodes[id*2+1].lazy += t;
    nodes[id*2+1].val += t;

    nodes[id].lazy = 0;
}
H�m c?p nh?t:

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) {
        return ;
    }
    if (u <= l && r <= v) {
        // Khi c�i d?t, ta LU�N �?M B?O gi� tr? c?a n�t du?c c?p nh?t �?NG TH?I v?i
        // gi� tr? lazy propagation. Nhu v?y s? tr�nh sai s�t.
        nodes[id].val += val;
        nodes[id].lazy += val;
        return ;
    }
    int mid = (l + r) / 2;

    down(id); // d?y gi� tr? lazy propagation xu?ng c�c con

    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);

    nodes[id].val = max(nodes[id*2].val, nodes[id*2+1].val);
}
H�m l?y gi� tr? l?n nh?t:

int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return -INFINITY;
    }
    if (u <= l && r <= v) {
        return nodes[id].val;
    }
    int mid = (l + r) / 2;
    down(id); // d?y gi� tr? lazy propagation xu?ng c�c con

    return max(get(id*2, l, mid, u, v),
        get(id*2+1, mid+1, r, u, v));
    // Trong c�c b�i to�n t?ng qu�t, gi� tr? ? n�t id c� th? b? thay d?i (do ta d?y lazy propagation
    // xu?ng c�c con). Khi d�, ta c?n c?p nh?t l?i th�ng tin c?a n�t id d?a tr�n th�ng tin c?a c�c con.
}
