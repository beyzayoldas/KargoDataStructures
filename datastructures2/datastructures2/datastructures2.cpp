#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int N;

    cout << "Kac kisi kargo bekliyor? ";
    cin >> N;

    int* kargo_sirasi = new int[N]; // Dizi veri yapısı ile yığın oluştur

    cout << "Kargo sirasi: ";
    for (int i = 0; i < N; i++) {
        int islem_suresi = rand() % ((300 - 30 + 1) + 30); // 30-300 arası rastgele bir sayı üret
        kargo_sirasi[i] = islem_suresi;
        cout << i + 1 << "(" << islem_suresi << "sn) ";
    }

    stack<int> yigin; // Yığın oluştur
    for (int i = N - 1; i >= 0; i--) { // Yığını oluştururken diziyi tersten oku
        yigin.push(kargo_sirasi[i]);
    }
    delete[] kargo_sirasi; // Diziyi temizle

    priority_queue<int, vector<int>, greater<int>> oncelikli_kuyruk; // Öncelikli kuyruk oluştur
    int toplam_sure = 0;
    int ortalama_sure = 0;
    //int fark = 0;
    cout << endl << "Kargo cikisi:" << endl;
    while (!yigin.empty()) {
        int kisi = yigin.top();
        yigin.pop();
        oncelikli_kuyruk.push(kisi); // Öncelikli kuyruğa ekle
        toplam_sure += kisi;
        ortalama_sure = toplam_sure / N;
        cout << "Kargo teslim alindi (" << kisi << " sn), kalan kisi sayisi: " << yigin.size() << endl;
    }

    cout << endl << "Oncelikli kuyruk:" << endl;
    while (!oncelikli_kuyruk.empty()) {
        int kisi = oncelikli_kuyruk.top();
        oncelikli_kuyruk.pop();
        cout << "Kargo teslim alindi (" << kisi << " sn), kalan kisi sayisi: " << oncelikli_kuyruk.size() << endl;
    }
    cout << "Toplam islem suresi: " << toplam_sure << " sn." << endl;
    cout << N << " kisi icin ortalama islem suresi: " << ortalama_sure << " sn." << endl;
    //cout << "FIFO'ya göre 1.1 ve 1.2 arasındaki fark : " << (fark - toplam_sure) << endl; 
    //projeyi 2'ye böldüğüm için farkı raporda açıklamış bulunmaktayım.

    return 0;



}
