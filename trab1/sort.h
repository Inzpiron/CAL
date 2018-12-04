#ifndef __SORT_H_INCLUDED__
#define __SORT_H_INCLUDED__
#include <bits/stdc++.h>
using namespace std;

namespace sort {
    extern vector<long long> vec25[4];
    extern vector<long long> vec50[4];
    extern vector<long long> vec75[4];
    extern vector<long long> vec100[4];
    extern vector<long long> vec1m[4];
    void reset(void);
    void iCronometro();
    double pCronometro();

    namespace bubble {
        double run(vector<long long> &vec);
    }

    namespace insert {
        double run(vector<long long> &vec);
    }

    namespace heap {
        double run(vector<long long> &vec);
    }

    namespace quick {
        namespace tipo1{
            double run(vector<long long> &vec);
        }

        namespace tipo2{
            double run(vector<long long> &vec);
        }
    }

    namespace merge {
        double run(vector<long long> &vec);
    }

    namespace counting {
        double run(vector<long long> &vec);
    }

    namespace bucket {
        double run(vector<long long> &vec);
    }

    namespace bucket2 {
        double run(vector<long long> &vec);
    }
}

#endif
