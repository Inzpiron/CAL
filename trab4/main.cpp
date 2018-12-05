#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/wait.h>
#include "source.hpp"
//#include "quero/dormir.h"
#include <string>
//#include "grasinha.h"
using namespace std;

int main(int argc, char ** argv) {

    int n;
    cin >> n;
    trab4::Graph g(n);

    for(int i = 0; i < n; i++) {
        string misc;
        int x, y;
        cin >> misc >> x >> y;  
        g.add(trab4::Node(i, x, y));
    }
    cout << "[Leitura] OK" << endl;
    
    trab4::iCronometro();
    trab4::guloso::startWorker(g);
    cout << "[Guloso] " << trab4::pCronometro() << "s" << endl;
    
    trab4::iCronometro();
    trab4::backtracking::startWorker(g);
    cout << "[Backtracking] " << trab4::pCronometro() << "s" << endl;
    return 0;
}