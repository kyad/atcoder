# ABC336 D

- A[i]中心の長さkのピラミッド列⇔A[i±j] + j ≧ k (for j=0, 1, ..., k-1)⇔kはi中心で幅kmaxまで見た時のA[i±j] + jの最小値。
- これをlazysegtreeで計算した。
