#include<iostream>
#include<vector>
using namespace std;
const int ukuran = 3;

struct Papan {
    char grid[ukuran][ukuran];
};

Papan* papan = new Papan;
vector<pair<int, int>> langkahX;
vector<pair<int, int>> langkahO;

void PapanAwal() {
    for (int i = 0; i < ukuran; i++) {
        for (int j = 0; j < ukuran; j++) {
            papan->grid[i][j] = ' ';
        }
    }
}

void CetakPapan() {
    for (int i = 0; i < ukuran; i++) {
        for (int j = 0; j < ukuran; j++) {
            cout << papan->grid[i][j];
            if (j < ukuran - 1) cout << " | ";
        }
        cout << endl;
        if (i < ukuran - 1) cout << "---------" << endl;
    }
}

bool CekMenang(char pemain) {
    for (int i = 0; i < ukuran; i++) {
        if (papan->grid[i][0] == pemain && papan->grid[i][1] == pemain && papan->grid[i][2] == pemain) return true;
        if (papan->grid[0][i] == pemain && papan->grid[1][i] == pemain && papan->grid[2][i] == pemain) return true;
    }
    if (papan->grid[0][0] == pemain && papan->grid[1][1] == pemain && papan->grid[2][2] == pemain) return true;
    if (papan->grid[0][2] == pemain && papan->grid[1][1] == pemain && papan->grid[2][0] == pemain) return true;
    return false;
}

bool LangkahValid(int baris, int kolom) {
    baris--; kolom--; 
    return (baris >= 0 && baris < ukuran && kolom >= 0 && kolom < ukuran && papan->grid[baris][kolom] == ' ');
}

void HapusLangkahPertama(char pemain) {
    if (pemain == 'X' && !langkahX.empty()) {
        pair<int, int> langkahPertama = langkahX.front();
        papan->grid[langkahPertama.first][langkahPertama.second] = ' ';
        langkahX.erase(langkahX.begin());
    } else if (pemain == 'O' && !langkahO.empty()) {
        pair<int, int> langkahPertama = langkahO.front();
        papan->grid[langkahPertama.first][langkahPertama.second] = ' ';
        langkahO.erase(langkahO.begin());
    }
}

int main() {
    
    return 0;
}
