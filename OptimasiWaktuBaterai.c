/*
    Optimasi Waktu Pengisian Baterai dengan Metode Secant
    Parameter:
    - Tegangan maksimum (V_max) = 4.2 V
    - Tegangan target (V_target) = 4.0 V  
    - Konstanta pengisian (k) = 0.03 s⁻¹
    - Tebakan awal waktu = 30 s dan 120 s
    - Toleransi error = 10⁻⁵
    - Iterasi maksimum = 100
*/

#include <stdio.h>
#include <math.h>

// Parameter tetap
#define V_MAX 4.2f
#define V_TARGET 4.0f
#define K 0.03f
#define EPSILON 1e-5f
#define MAX_ITER 50

// Fungsi representasi tegangan baterai terhadap waktu
float fungsi_pengisian(float t) {
    return V_MAX * (1 - expf(-K * t)) - V_TARGET;
}

int main() {
    // Tebakan awal waktu pengisian (sekon)
    float t0 = 30.0f;
    float t1 = 120.0f;

    // Variabel untuk menyimpan hasil iterasi
    float t2, f0, f1, f2;
    int iter = 0;

    // Menampilkan parameter simulasi
    printf("\n=== HASIL SIMULASI PENGISIAN BATERAI ===\n");
    printf("Parameter:\n");
    printf("- V_maks = %.1f V\n", V_MAX);
    printf("- V_target = %.1f V\n", V_TARGET);
    printf("- Konstanta pengisian = %.2f s^(-1)\n", K);
    printf("- Tebakan awal = %.1f s dan %.1f s\n", t0, t1);
    printf("- Toleransi error = %.0e\n", EPSILON);
    
    printf("\nProses Iterasi:\n");
    printf("Iterasi\t t(dtk)\t\t Selisih Tegangan\n");

    // Implementasi metode Secant untuk mencari akar fungsi
    do {
        f0 = fungsi_pengisian(t0);  // Perhitungan f(t0)
        f1 = fungsi_pengisian(t1);  // Perhitungan f(t1)

        // Validasi: jika f0 = f1, tidak dapat dilakukan pembagian
        if (f1 == f0) {
            printf("\nError: f1 dan f0 bernilai sama, tidak dapat dilakukan pembagian.\n");
            return 1;
        }

        // Rumus metode Secant
        t2 = t1 - ((f1 * (t1 - t0)) / (f1 - f0));
        f2 = fungsi_pengisian(t2);  // Hitung f(t2)

        // Menampilkan hasil iterasi
        printf("%d\t %.6f\t %.6f\n", iter + 1, t2, f2);

        // Memperbarui nilai untuk iterasi selanjutnya
        t0 = t1;
        t1 = t2;
        iter++;

        // Jika iterasi melebihi batas, maka berhenti
        if (iter >= MAX_ITER) {
            printf("\nPeringatan: Maksimum iterasi tercapai\n");
            break;
        }

    } while (fabsf(f2) > EPSILON);  // Berhenti jika error sudah di bawah toleransi

    // Cetak hasil akhir
    printf("\n=== HASIL AKHIR ===\n");
    printf("Waktu pengisian: %.6f detik\n", t2);
    printf("Tegangan tercapai: %.6f V\n", V_TARGET + f2);
    printf("Jumlah iterasi: %d\n\n", iter);

    return 0;
}