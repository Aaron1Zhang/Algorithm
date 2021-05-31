class ConnectingGraph {
public:
    int *father;
    /*
    * @param n: An integer
    */ConnectingGraph(int n) {
        // do intialization if necessary
        father = new int[n+1];
        for(int i = 1; i <=n; ++i) {
            father[i] = i;
        }
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        int fa = find(a);
        int fb = find(b);
        if(fa == fb) {
            return;
        }
        if(fa > fb) {
            swap(fa, fb);
        }
        father[fb] = fa;
    }
    int find(int t) {
        if(father[t] == t) {
            return t;
        }
        father[t] = find(father[t]);
        return father[t];

    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: A boolean
     */
    bool query(int a, int b) {
        // write your code here
        return find(a) == find(b);
    }
};