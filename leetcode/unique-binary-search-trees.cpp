class Solution {
public:
    int numTrees(int n) {
        int tab[n+1];
        fill_n(tab, n+1, 0);
        tab[0] = tab[1] = 1;

        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i; j++)
                tab[i] += tab[j - 1] * tab[i - j];
        return tab[n];
    }
};
