#include <iostream>
#include <unordered_map>

using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

int main()
{
    pair<int, char> p = make_pair(42, 'P');

    pair_hash hasher;
    size_t hash_value = hasher(p);

    cout << hash_value << endl;
    return 0;
}
