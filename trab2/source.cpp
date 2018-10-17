#include <bits/stdc++.h>
#include "source.h"
using namespace std;

namespace trab2 {
    namespace {
        auto start = std::chrono::high_resolution_clock::now();
    }

    void iCronometro(void) {
        start = std::chrono::high_resolution_clock::now();
    }

    double pCronometro(void) {
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        return elapsed.count();
    }

    namespace vector {
        //PRIVATE
        namespace {
            class Registro {
            public:
                int index;
                string nome;

                Registro() {
                    this->index = -1;
                    this->nome  = "";
                }

                Registro(int index, string nome) {
                    this->index = index;
                    this->nome  = nome;
                }
            };
            std::vector<Registro> buff;
        }

        void add(int index, std::string nome) {
            buff.push_back(Registro(index, nome));
        }

        int buscar(string nome) {
            for(auto a : buff) {
                if(a.nome == nome) {
                    return a.index;
                }
            }

            return -1;
        }
    }

    namespace map {
        namespace {
            std::map<string, int> buff;
        }

        void add(int index, string nome) {
            buff[nome] = index;
        }

        int buscar(string nome) {
            if(buff.count(nome) > 0)
                return buff[nome];

            return -1;
        }
    }

    namespace hash {
        namespace {
            std::map<string, int> * buff;
            int n;

            int hashing(string nome) {
                int soma = 0;
                for(int i = 0; i < nome.size(); i++) {
                    soma += nome[i];
                }

                return soma%n;
            }
        }

        void iniciar(int tam) {
            n = tam;
            buff = new std::map<string, int>[n];
        }

        void add(int index, string nome) {
            int i = hashing(nome);
            buff[i][nome] = index;
            cout << i << "|";
        }

        int buscar(string nome) { //pior = (log(n)), melhor = 
            int i = hashing(nome);
            if(buff[i].count(nome) > 0)
                return buff[i][nome];

            return -1;
        }

        void printHistograma (){
            for(int i = 0; i < n; i++) {
                cout << buff[i].size();
                if(i != n-1)
                    cout << "|";
            }
            cout << endl;
        }
    }
}
