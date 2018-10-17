#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>
#include "source.h"
//#include "quero/dormir.h"
#include <string>
//#include "grasinha.h"
using namespace std;

int n, n1;
vector<pair<int, string> > entry0;
vector<string> entry1;

void readEntry(void (*f)(int, string)) {
    for(auto t : entry0) {
        int index = t.first;
        string nome = t.second;
        (*f)(index, nome);
    }
}

void findName(int (*f)(string)) {
    for(auto t : entry1) {
        (*f)(t);
    }
}

void runVector() {
    
    trab2::iCronometro();
    readEntry(trab2::vector::add);
    //cout << "plt.bar([1], [" << trab2::pCronometro()*1000 << "],label='vector Ins.', color = 'green')" << endl;

    trab2::iCronometro();
    findName(trab2::vector::buscar);
    //cout << "plt.bar([5], [" << trab2::pCronometro()*1000 << "],label='vector Bus.', color = 'darkgreen')" << endl;

    exit(0);
}

void runMap() {

    trab2::iCronometro();
    readEntry(trab2::map::add);
    //cout << "plt.bar([2], [" << trab2::pCronometro()*1000 << "],label='Map Ins.', color = 'red')" << endl;

    trab2::iCronometro();
    findName(trab2::map::buscar);
    //cout << "plt.bar([6], [" << trab2::pCronometro()*1000 << "],label='Map Bus.', color = 'darkred')" << endl;

    exit(0);
}

void runHash() {
    trab2::iCronometro();
    readEntry(trab2::hash::add);
    //cout <<  "plt.bar([0], [" << trab2::pCronometro()*1000 << "],label='hash Ins.', color = 'blue')" << endl;

    trab2::iCronometro();
    findName(trab2::hash::buscar);
    //cout <<  "plt.bar([4], [" << trab2::pCronometro()*1000 << "],label='hash Bus.', color = 'darkblue')" << endl;

    //trab2::hash::printHistograma();
    exit(0);
}

int main(int argc, char ** argv) {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int index;
        string nome1, nome2;
        cin >> index >> nome1 >> nome2;
        entry0.push_back({index, string(nome1 + " " + nome2)});
    }

    cin >> n1;
    for(int i = 0; i < n1; i++) {    
        string nome1, nome2;
        cin >> nome1 >> nome2;
        entry1.push_back(nome1+" "+nome2);
    }

    trab2::hash::iniciar(log(n));
    //cout << "import matplotlib.pyplot as plt " << endl;
    string title[] = {"Entrada-1 (5000x1000)", "Entrada-2 (25000x10000)",
                      "Entrada-3 (50000x10000)", "Entrada-4 (100000x25000)",
                      "Entrada-5 (100000x75000)"};

    pid_t p = fork();

    if(p == 0) {
        runVector();
    } else if (p > 0) {
        pid_t p1 = fork();
        if(p1 == 0) {
            runMap();
        } else if(p1 > 0) {
            pid_t p2 = fork();
            if(p2 == 0) {
                runHash();
            } else {
                int returnStatus[3];
                waitpid(p,  &returnStatus[0], 0);  // Parent process waits here for child to terminate.
                waitpid(p1, &returnStatus[1], 0);
                waitpid(p2, &returnStatus[2], 0);
                /*cout << "plt.xlabel('Estruturas')\n"
                     << "plt.ylabel('Tempo MS')\n"
                     << "plt.title('" << title[atoi(argv[1]) - 1] << "')\n"
                     << "plt.xticks([])\n"
                     << "plt.ylim(0, 10)\n"
                     << "plt.legend()\n"
                     << "plt.savefig('../Imgs/graph" << argv[1] << ".png')\n" << endl;*/
            }
        }
    }

    return 0;
}
