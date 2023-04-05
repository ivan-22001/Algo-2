#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    set<int> a;
    vector<int> res;
    for(int i = 0; i < s.size(); i++){
        if(a.count(s[i])==0){
            a.insert(s[i]);
            res.push_back(s[i]);
        }
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> a;
    vector<int> res;
    for(int i = 0; i < s.size(); i++){
        if(a.count(s[i])==0){
            a.insert(s[i]);
            res.push_back(s[i]);
        }
    }
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> set_a, set_b;
    for(int i :a)
        set_a.insert(i);
    for(int i : b)
        set_b.insert(i);
    return set_a == set_b;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    mismos_elementos(a,b);
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int,int> res;
    for(int i = 0; i < s.size(); i++){
        if(res.count(s[i]))
            res[s[i]]++;
        else
            res[s[i]] = 1;
    }
    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    map<int,int> m;
    for(int i = 0; i < s.size(); i++){
        if(m.count(s[i]))
            m[s[i]]++;
        else
            m[s[i]] = 1;
    }
    vector<int> res;
    for(pair<int,int> p : m){
        if(p.second == 1)
            res.push_back(p.first);
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for(int n : a){
        if(b.count(n) == 1)
            res.insert(n);
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int,set<int>> res;
    for(int n :s ){
        if(res.count(n % 10) == 1){
            res[n%10].insert(n);
        }
        else{
            res[n%10] = {n};
        }
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res;
    if(tr.size()==0){
        for(char a: str)
            res.push_back(a);
        return res;
    }
    for(char a: str){
        bool listo = false;
        for(pair<char,char> p : tr){
            if(p.first == a){
                res.push_back(p.second);
                listo = true;
                break;
            }
        }
        if(!listo)
            res.push_back(a);
    }
    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    for(Mail m1 : s){
        for(Mail m2 : s){
            if(m1.libretas() != m2.libretas()){
                for(LU n : m1.libretas()){
                    if(m2.libretas().count(n) == 1)
                        return true;
                }
            }
        }
    }
    return false;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  map<set<LU>,Mail> res;
  for(Mail m : s){
      if(m.adjunto())
          res[m.libretas()] = m;
  }
  return res;
}
