# map<int, map<int, int> > とmap<pair<int, int>, int>の実行時間の比較

| File | Data structure            | Time  |
|------|---------------------------|-------|
| a.cc | set<pair<int, int> >      | 390ms |
| b.cc | map<int, set<int> >       | 405ms |
| c.cc | map<pair<int, int>, int > | 402ms |
| d.cc | map<int, map<int, int> >  | 377ms |
