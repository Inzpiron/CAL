#include <bits/stdc++.h>
#include "sort.h"
using namespace std;

#define MIN(x, y) (x<y)?x:y
#define MAX(x, y) (x>y)?x:y
#define INF 0x3f3f3f3f

namespace sort {
    //PRIVATE
    namespace {
        auto start = std::chrono::high_resolution_clock::now();

        void swap(long long &a, long long &b){
            long long aux = a;
            a = b;
            b = aux;
        }
    }

    vector<long long> vec25[4];
    vector<long long> vec50[4];
    vector<long long> vec75[4];
    vector<long long> vec100[4];
    vector<long long> vec1m[4];

    void iCronometro(void) {
        auto start = std::chrono::high_resolution_clock::now();
    }

    double pCronometro(void) {
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        return elapsed.count();
    }

    void reset(void) {
        //Inicialização dos vores
        for(int i = 0; i < 4; i++) {
            vec25[i] = vector<long long>(25000);
            vec50[i] = vector<long long>(50000);
            vec75[i] = vector<long long>(75000);
            vec100[i] = vector<long long>(100000);
            vec1m[i] = vector<long long>(1000000);
        }
        //Crescente
        for(long i = 0; i < 1000000; i++) {
            if(i < 25000)
                vec25[0][i] = i;
            if(i < 50000)
                vec50[0][i] = i;
            if(i < 75000)
                vec75[0][i] = i;
            if(i < 100000)
                vec100[0][i] = i;

            vec1m[0][i] = i;
        }
        //Decrescente
        {
            vec25[1] = vec25[0];
            reverse(vec25[1].begin(), vec25[1].end());

            vec50[1] = vec50[0];
            reverse(vec50[1].begin(), vec50[1].end());

            vec75[1] = vec75[0];
            reverse(vec75[1].begin(), vec75[1].end());

            vec100[1] = vec100[0];
            reverse(vec100[1].begin(), vec100[1].end());

            vec1m[1] = vec1m[0];
            reverse(vec1m[1].begin(), vec1m[1].end());
        }
        //Aleatório
        {
            auto engine = std::default_random_engine{};
            vec25[2] = vec25[1];
            shuffle(vec25[2].begin(), vec25[2].end(), engine);

            vec50[2] = vec50[1];
            shuffle(vec50[2].begin(), vec50[2].end(), engine);

            vec75[2] = vec75[1];
            shuffle(vec75[2].begin(), vec75[2].end(), engine);

            vec100[2] = vec100[1];
            shuffle(vec100[2].begin(), vec100[2].end(), engine);

            vec1m[2] = vec1m[1];
            shuffle(vec1m[2].begin(), vec1m[2].end(), engine);
        }
        //Aleatório com 10000
        {
            vec25[3] = vec25[2];
            srand (time(NULL));
            vec25[3][rand()%24999] = 100000000;

            vec50[3] = vec50[2];
            srand (time(NULL));
            vec50[3][rand()%49999] = 100000000;

            vec75[3] = vec75[2];
            srand (time(NULL));
            vec75[3][rand()%74999] = 100000000;;

            vec100[3] = vec100[2];
            srand (time(NULL));
            vec100[3][rand()%99999] = 100000000;

            vec1m[3] = vec1m[2];
            srand (time(NULL));
            vec1m[3][rand()%999999] = 100000000;
        }
    }

    namespace bubble {
        double run(vector<long long> &v) {
            iCronometro();
            for(int i = 0; i < v.size(); i++) {
                for(int j = 0; j < v.size(); j++) {
                    if(v[i] < v[j]) {
                        long long aux = v[i];
                        v[i] = v[j];
                        v[j] = aux;
                    }
                }
            }
            return pCronometro();
        }
    }

    namespace insert {
        double run(vector<long long> &v) {
            iCronometro();
            for(int i = 1; i < v.size(); i++){
                int aux = i;
                while(aux >= 1 && v[aux - 1] > v[aux]){
                    swap(v[aux - 1], v[aux]);
                    aux--;
                }
            }
            return pCronometro();
        }
    }

    namespace heap {
        //PRIVATE
        namespace {
            void heapify(int n, int i, vector<long long> &v){
                int dir = 2 * i + 1;
                int esq = 2 * i + 2;
                int maior = i;
                if(esq < n and v[esq] > v[maior]){
                    maior = esq;
                }
                if(dir < n and v[dir] > v[maior]){
                    maior = dir;
                }
                if(maior != i){
                    swap(v[i], v[maior]);
                    heapify(n, maior, v);
                }
            }

            void buildHeap(int n, vector<long long> &v){
                for(int i = n / 2; i >= 0; i--){
                    heapify(n, i, v);
                }
            }

            void heap(int n, vector<long long> &v){
                buildHeap(n, v);
                for(int i = n; i > 0; i--){
                    swap(v[0], v[i]);
                    heapify(i, 0, v);
                }
            }
        }

        double run(vector<long long> &v) {
            iCronometro();
            heap(v.size() - 1, v);
            return pCronometro();
        }
    }

    namespace quick {
        //PRIVADO QUICK
        namespace {
            int pivoteamento(int l, int r, bool flag, vector<long long> &v){
                if(flag) {
                    int rd = (rand() % (r - l + 1)) + l;
                    swap(v[rd], v[l]);
                }
                int pivo = l;
                for(int j = l + 1; j <= r; j++){
                    if(v[j] < v[l]){
                        pivo++;
                        swap(v[pivo], v[j]);
                    }
                }
                swap(v[l], v[pivo]);
                return pivo;
            }

            void quickSort(int l, int r, bool flag, vector<long long> &v){
                if(l >= r) return;
                int mid = pivoteamento(l, r, flag, v);
                quickSort(l, mid, flag, v);
                quickSort(mid + 1, r, flag,  v);
            }
        }

        namespace tipo1 {
            double run(vector<long long> &v){
                iCronometro();
                quickSort(0, v.size() - 1, false, v);
                return pCronometro();
            }
        }

        namespace tipo2 {
            double run(vector<long long> &v) {
                iCronometro();
                quickSort(0, v.size() -1, true, v);
                return pCronometro();
            }
        }
    }

    namespace merge {
        //PRIVADO MERGE
        namespace {
            vector<long long> merge(vector<long long> &l, vector<long long> &r){
                vector<long long> temp;
                int i = 0, j = 0;
                while(i < l.size() and j < r.size()){
                    if(l[i] < r[j]){
                        temp.push_back(l[i]);
                        i++;
                    } else {
                        temp.push_back(r[j]);
                        j++;
                    }
                }
                while(i < l.size()){
                    temp.push_back(l[i++]);
                }
                while(j < r.size()){
                    temp.push_back(r[j++]);
                }
                return temp;
            }

            vector<long long> mergeSort(int l, int r, vector<long long> &v){
                if(l == r){
                    return vector<long long>(1, v[l]);
                } else if(l > r){
                    return vector<long long>();
                } else {
                    int mid = (l + r) / 2;
                    vector<long long> left = mergeSort(l, mid, v);
                    vector<long long> right = mergeSort(mid + 1, r, v);
                    return merge(left, right);
                }
            }
        }

        double run(vector<long long> &v){
            iCronometro();
            v = mergeSort(0, v.size() - 1, v);
            return pCronometro();
        }
    }

    namespace counting {
        long long find_min(vector<long long> &v) {
            long long minn = v[0];
            for(int i = 1; i < v.size(); i++) {
                if(v[i] < minn){
                    minn = v[i];
                }
            }
            return minn;
        }

        long long find_max(vector<long long> &v) {
            long long maxx = v[0];
            for(int i = 1; i < v.size(); i++) {
                if(v[i] > maxx){
                    maxx = v[i];
                }
            }
            return maxx;
        }

        void soma_parcial(vector<long long> &cnt) {
            for(int i = 1; i < cnt.size(); i++) {
                cnt[i] += cnt[i - 1];
            }
        }

        vector<long long> counting_sort(vector<long long> &v) {
            long long minn = find_min(v);
            long long maxx = find_max(v);

            vector<long long> cnt(maxx - minn + 1, 0);
            for(int i = 0; i < v.size(); i++) {
                cnt[v[i] - minn]++;
            }

            soma_parcial(cnt);

            vector<long long> ordenado(v.size());
            for(int i = v.size() - 1; i >= 0; i--) {
                ordenado[--cnt[v[i] - minn]] = v[i];
            }

            return ordenado;
        }

        double run(vector<long long> &v){
            iCronometro();
            v = counting_sort(v);
            return pCronometro();
        }
    }

    namespace bucket {
        namespace {
            long long max;
            long long min;
            vector< set<long long> > bucket;
            long long divider;
        }

        void iniciar(vector<long long> &v) {
            bucket = vector< set<long long> >(v.size() + 1);
            for(auto i = 0; i < v.size(); i++) {
                if(i == 0) {
                    max = v[i];
                    min = v[i];
                } else {
                    max = MAX(max, v[i]);
                    min = MIN(min, v[i]);
                }
            }
            divider = ceil((max + 1)/(bucket.size() - 1));
        }

        double run(vector<long long> &v) {
            iniciar(v);
            vector<long long> r;
            iCronometro();

            for(int i = 0; i < v.size(); i++) {
                long long j = floor(v[i]/((double)divider));
                bucket[j].insert(v[i]);
            }

            for(int i = 0; i < bucket.size(); i++) {
                if(!bucket[i].empty()) {
                    copy(begin(bucket[i]), end(bucket[i]), back_inserter(r));
                }
            }

            v = r;
            return pCronometro();
        }
    }
}
