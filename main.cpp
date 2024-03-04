#include <iostream>

struct wierzcholek{
    double x, y;
};

struct Wielokat{
    int pole;
};

int pole(wierzcholek wierzcholki[], int n){
    double poleWiel = 0;
    for (int i = 0; i < n; i++){
        if (i == n-1) poleWiel += ((wierzcholki[i].x*wierzcholki[0].y) - (wierzcholki[0].x*wierzcholki[i].y));
        else poleWiel += ((wierzcholki[i].x*wierzcholki[i+1].y) - (wierzcholki[i+1].x*wierzcholki[i].y));
    }
    return int(0.5 * poleWiel);
}

int main() {
    int linie, lwspol, poleI;
    double x,y;
    std::cin >> linie;

    Wielokat wielokaty[linie];
    for (int i = 0 ; i < linie; i++){
        std::cin >> lwspol;
        wierzcholek wierzcholki[lwspol/2];
        for (int j = 0; j< lwspol/2; j++){
            std::cin >> wierzcholki[j].x;
            std::cin >> wierzcholki[j].y;
        }
        poleI = pole(wierzcholki, lwspol/2);
        wielokaty[i].pole = poleI;
    }

    for (int i = 0; i< linie; i++){
        std::cout << wielokaty[i].pole << "\n";
    }

    return 0;
}
