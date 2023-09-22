class Solution {
    char[] str;
    int n, res;
    int[] tab;

    void init(String s) {
        this.str = s.toCharArray();
        this.n = s.length();
        this.res = 0;

        this.tab = new int[this.n];

        for(int i=0; i<this.n; i++){
            if(this.str[i] == 'I')
                tab[i] = 1;
            else if(this.str[i] == 'V')
                tab[i] = 5;
            else if(this.str[i] == 'X')
                tab[i] = 10;
            else if(this.str[i] == 'L')
                tab[i] = 50;
            else if(this.str[i] == 'C')
                tab[i] = 100;
            else if(this.str[i] == 'D')
                tab[i] = 500;
            else if(this.str[i] == 'M')
                tab[i] = 1000;
        }
    }


    public int romanToInt(String s) {
        init(s);

        int idx=0;
        while (idx < this.n){
            int v1 = this.tab[idx];

            if(idx == n-1){
                res += v1;
                break;
            }

            int v2 = this.tab[idx+1];

            if(v1 >= v2) {
                this.res += v1;
                idx++;
            }
            else {
                this.res += v2 - v1;
                idx += 2;
            }
        }
        return this.res;
    }
}
