#include <bits/stdc++.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "sort.h"
using namespace std;

static bool *check[4];
string name[4] = {"[  ORDENADO  ]", "[ORDENADO (R)]", "[   RANDON   ]", "[ RANDON (*) ]"};
vector<long long> * v;
double (*func)(vector<long long>&);


void filho0() {
    printf("[  ORDENADO  ] %.4lf\n", func(v[0]) * 1000);
    *check[0] = true;
}

void filho1() {
    printf("[ORDENADO (R)] %.4lf\n", func(v[1]) * 1000);
    *check[1] = true;
}

void filho2() {
    printf("[   RANDON   ] %.4lf\n", func(v[2]) * 1000);
    *check[2] = true;
}

void filho3() {
    printf("[ RANDON (*) ] %.4lf\n", func(v[3]) * 1000);
    *check[3] = true;
}

void pai(vector<pid_t> pid) {
    sort::iCronometro();
    while(sort::pCronometro() <  60 * 5.0) {
        bool check_all = true;
        for(int i = 0; i < pid.size(); i++) {
            if(*check[i] == false){ check_all = false; break;}
        }

        if(check_all == true)
            break;
    }

    for(int i = 0; i < pid.size(); i++) {
        if(*check[i] == false) {
            printf("%s time out\n",name[i].data());
        }
    }
}

int main(int argc, char ** argv) {
    if(argc <= 1)
        return 0;
    if(string(argv[1]) == "bubble")        func = &sort::bubble::run;
    else if(string(argv[1]) == "quick1")   func = &sort::quick::tipo1::run;
    else if(string(argv[1]) == "quick2")   func = &sort::quick::tipo2::run;
    else if(string(argv[1]) == "merge" )   func = &sort::merge::run;
    else if(string(argv[1]) == "heap"  )   func = &sort::heap::run;
    else if(string(argv[1]) == "insert")   func = &sort::insert::run;
    else if(string(argv[1]) == "counting") func = &sort::counting::run;
    else if(string(argv[1]) == "bucket")   func = &sort::bucket::run;
    else return 0;

    sort::reset();
    map<string, vector<long long> *> mapa;
    mapa["vec25"]  = &sort::vec25[0];
    mapa["vec50"]  = &sort::vec50[0];
    mapa["vec75"]  = &sort::vec75[0];
    mapa["vec100"] = &sort::vec100[0];
    mapa["vec1m"]  = &sort::vec1m[0];
    v = mapa[string(argv[2])];
    if(mapa[string(argv[2])] == NULL)
        return 0;

    cout << endl << argv[2] << endl;

    for(int i = 0; i < 4; i++) {
        check[i] = (bool *) mmap(NULL, sizeof *check[0], PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
        *check[i] = false;
    }

    pid_t pid = fork();
    if(pid == 0) {
        filho0();
    } else if(pid > 0){
        pid_t pid1 = fork();
        if(pid1 == 0) {
            filho1();
        } else if(pid1 > 0) {
            pid_t pid2 = fork();
            if(pid2 == 0) {
                filho2();
            } else if(pid2 > 0){
                pid_t pid3 = fork();
                if(pid3 == 0) {
                    filho3();
                } else if(pid3 > 0) {
                    pai({pid, pid1, pid2, pid3});
                }
            }
        }
    }

    return 0;
}
