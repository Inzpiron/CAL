#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>
#include "source.h"
using namespace std;

int n;

void runVector() {
    trab2::iCronometro();
    for(int i = 0; i < n; i++) {
        string nome, nome1;
        cin >> nome >> nome1;
        nome = nome + " " + nome1;
        trab2::vector::buscar(nome);
    }
    cout << "[vector] " << trab2::pCronometro() << "s" << endl;
    exit(0);
}

void runMap() {
    trab2::iCronometro();
    for(int i = 0; i < n; i++) {
        string nome, nome1;
        cin >> nome >> nome1;
        nome = nome + " " + nome1;
        trab2::map::buscar(nome);
    }
    cout << "[map   ] " << trab2::pCronometro() << "s" << endl;
    exit(0);
}

void runHash() {
    trab2::iCronometro();
    for(int i = 0; i < n; i++) {
        string nome, nome1;
        cin >> nome >> nome1;
        nome = nome + " " + nome1;
        trab2::hash::buscar(nome);
    }
    cout <<  "[hash  ] " << trab2::pCronometro() << "s" << endl;
    exit(0);
}

int main(int argc, char ** argv) {
    cin >> n;
    trab2::hash::iniciar(n);

    for(int i = 0; i < n; i++) {
        int index;
        string nome, nome1;
        cin >> index >> nome >> nome1;
        nome = nome + " " + nome1;
        trab2::vector::add(index, nome);
        trab2::hash::add(index, nome);
        trab2::map::add(index, nome);
    }

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
            }
        }
    }

    return 0;
}
