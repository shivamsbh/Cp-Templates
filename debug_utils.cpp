#ifndef DEBUG_UTILS_H
#define DEBUG_UTILS_H

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define debug(x)       std::cerr << #x <<" "; _print(x); std::cerr << std::endl
#else
#define debug(x)
#endif

void _print(bool x)               {std::cerr << (x ? "True" : "False");}
template <typename T, size_t N>   void _print(T (&arr)[N]);
template <typename T>             void _print(T t) {std::cerr << t;}
template <typename T>             void _print(std::priority_queue<T, std::vector<T>, std::greater<T>> _);
template <typename T>             void _print(std::priority_queue<T> _);
template <typename T, typename V> void _print(std::pair<T, V> p);
template <typename T>             void _print(std::vector<T> v);
template <typename T>             void _print(std::queue<T> _);
template <typename T>             void _print(std::stack<T> _);
template <typename T>             void _print(std::set<T> v);
template <typename T>             void _print(__gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> v);
template <typename T, typename V> void _print(std::map<T, V> v);
template <typename T>             void _print(std::multiset<T> v);
template <typename T, typename V> void _print(std::pair<T, V> p) {std::cerr << "("; _print(p.first); std::cerr << ","; _print(p.second); std::cerr << ")";}
template <typename T>             void _print(std::vector<T> v) {std::cerr << "[ "; for (T i : v) {_print(i); std::cerr << " ";} std::cerr << "]";}
template <typename T>             void _print(std::set<T> v) {std::cerr << "( "; for (T i : v) {_print(i); std::cerr << " ";} std::cerr << ")";}
template <typename T>             void _print(std::multiset<T> v) {std::cerr << "( "; for (T i : v) {_print(i); std::cerr << " ";} std::cerr << ")";}
template <typename T, typename V> void _print(std::map<T, V> v) {std::cerr << "[ "; for (auto i : v) {_print(i); std::cerr << " ";} std::cerr << "]";}
template <typename T>             void _print(std::priority_queue<T> _) {std::priority_queue<T> v = _; std::cerr << "{ "; while (!v.empty()) {_print(v.top()); std::cerr << " "; v.pop();} std::cerr << "}";}
template <typename T>             void _print(std::priority_queue<T, std::vector<T>, std::greater<T>> _) {std::priority_queue<T, std::vector<T>, std::greater<T>> v = _; std::cerr << "{ "; while (!v.empty()) {_print(v.top()); std::cerr << " "; v.pop();} std::cerr << "}";}
template <typename T>             void _print(std::queue<T> _) {std::queue<T> v = _; std::cerr << "{ "; while (!v.empty()) {_print(v.front()); std::cerr << " "; v.pop();} std::cerr << "}";}
template <typename T>             void _print(std::stack<T> _) {std::stack<T> v = _; std::cerr << "{ "; while (!v.empty()) {_print(v.top()); std::cerr << " "; v.pop();} std::cerr << "}";}
template <typename T>             void _print(__gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> v) {std::cerr << "( "; for (T i : v) {_print(i); std::cerr << " ";} std::cerr << ")";}
template <typename T, size_t N>   void _print(T (&arr)[N]) {std::cerr << "[ "; for (size_t i = 0; i < N; ++i) {_print(arr[i]); std::cerr << " ";} std::cerr << "]";}

#endif
