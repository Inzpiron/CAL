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

    cout << "[Pré processamento] ..." << endl;
    trab4::iCronometro();
    for(int i = 0; i < n; i++) {
        string misc;
        int x, y;
        cin >> misc >> x >> y;  
        g.add(trab4::Node(i, x, y));
    }

    for(int i = 0; i < g.mAdj.size(); i++) {
        for(int j = 0; j < g.mAdj[i].size(); j++) {
            g.lAdj[i].push_back({g.mAdj[i][j], j});
        }
    }

    for(int i = 0; i < g.lAdj.size(); i++) {
       sort(g.lAdj[i].begin(), g.lAdj[i].end());
    }

    // for(int i =0 ; i < g.lAdj.size(); i++) {
    //     cout << i << ": ";
    //     for(int j = 0; j < g.lAdj[i].size(); j++) {
    //         cout << "(" << g.lAdj[i][j].second  << "," << g.lAdj[i][j].first << ") - ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    for(int i =0 ; i < g.mAdj.size(); i++) {
         cout << i << ": ";
         for(int j = 0; j < g.mAdj[i].size(); j++) {
             cout << "(" << g.mAdj[i][j]  << ") - ";
         }
         cout << endl;
     }
    cout << "[Pré processamento] OK (" << trab4::pCronometro() << "s)" << endl;
    
    cout << "[Guloso] ..." << endl;
    trab4::iCronometro();
    cout << "[Guloso] " << trab4::guloso::startWorker(g) << " (" <<trab4::pCronometro() << "s)" << endl;

    cout << "[Aproximação] ..." << endl;
    trab4::iCronometro();
    cout << "[Aproximação] " << trab4::aprox::startWorker(g) << " (" << trab4::pCronometro() << "s)" << endl; 

    cout << "[Backtracking] ..." << endl;
    trab4::iCronometro();
    cout << "[Backtracking] " << trab4::backtracking::startWorker(g) << " (" << trab4::pCronometro() << "s)" <<endl;
    return 0;
}