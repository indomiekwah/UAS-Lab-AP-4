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
    PapanAwal();
    char pemainSekarang = 'X';
    int baris, kolom;

    while (true) {
        CetakPapan();
        cout << "Pemain " << pemainSekarang << ", masukkan langkah anda:\nBaris: ";
        cin >> baris;
        cout << "Kolom: ";
        cin >> kolom;

        if (!LangkahValid(baris, kolom)) {
            cout << "Langkah tidak valid. Coba lagi." << endl;
            continue;
        }

        baris--; kolom--;
        papan->grid[baris][kolom] = pemainSekarang;
        if (pemainSekarang == 'X') {
            langkahX.push_back(make_pair(baris, kolom));
            if (langkahX.size() > 3) {
                HapusLangkahPertama('X');
            }
        } else {
            langkahO.push_back(make_pair(baris, kolom));
            if (langkahO.size() > 3) {
                HapusLangkahPertama('O');
            }
        }

        if (CekMenang(pemainSekarang)) {
            CetakPapan();
            cout << "Pemain " << pemainSekarang << " menang!" << endl;
            break;
        }

        pemainSekarang = (pemainSekarang == 'X') ? 'O' : 'X';
    }

    delete papan;
    return 0;
}
