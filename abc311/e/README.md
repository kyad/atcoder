# ABC311 E

- 各マスを頂点とし、頂点からに左、上、左上に重み1の辺を張ったグラフを考え、穴の位置を始点とした多始点BFSをする。
- これにより、各マスから穴の位置への距離(距離はL∞ノルムとする)の最小値が求まる。
- 答え=各マスの穴の位置への距離の和