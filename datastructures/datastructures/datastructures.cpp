#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    queue<int> kargo_sirasi;
    int N;

    cout << "Kac kisi kargo bekliyor? ";
    cin >> N;

    srand(time(NULL)); // Rastgele sayı üretmek için zamanı kullan

    cout << "Kargo sirasi: ";
    for (int i = 1; i <= N; i++) {
        int islem_suresi = rand() % ((300 - 30 + 1) + 30); // 30-300 arası rastgele bir sayı üret
        kargo_sirasi.push(islem_suresi);
        cout << i << "(" << islem_suresi << "sn) ";
    }

    cout << endl << "Kargo cikisi:" << endl;
    int toplam_sure = 0;
    int ortalama_sure = 0;
    //int fark = 0;
    while (!kargo_sirasi.empty()) {
        int kisi = kargo_sirasi.front();
        kargo_sirasi.pop();
        toplam_sure += kisi;
        cout << "Kargo teslim alindi (" << kisi << " sn), kalan kisi sayisi: " << kargo_sirasi.size() << endl;
        ortalama_sure = toplam_sure / N ;
    }
    cout << "Toplam islem suresi: " << toplam_sure << " sn." << endl;
    cout << N <<  " kisi icin ortalama islem suresi: " << ortalama_sure << " sn." << endl;
    //cout << "FIFO'ya göre 1.1 ve 1.2 arasindaki fark : " << (fark - toplam_sure) << endl; 
    //projeyi 2'ye böldüğüm için farkı raporda açıklamış bulunmaktayım.

    return 0;
}








