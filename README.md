# Optimasi Waktu Pengisian Baterai Ponsel Menggunakan Metode Secant

Kelompok 27
1. Azra Nabila Azzahra (2306161782)
2. Mutia Casella (2306202870) 
3. Siti Amalia Nurfaidah (2306161851)
4. Alicia (2306161832)
5. Jesie Tenardi (2306162002)

## Deskripsi Program

Program ini menggunakan metode numerik Secant untuk menghitung waktu yang dibutuhkan dalam proses pengisian baterai ponsel hingga mencapai tegangan target. Model pengisian diasumsikan mengikuti fungsi eksponensial yang merepresentasikan pertumbuhan tegangan terhadap waktu, dengan mempertimbangkan faktor resistansi dan efisiensi sistem pengisian.

Jenis baterai yang dimodelkan dalam program ini adalah baterai lithium-ion (Li-ion), yaitu tipe baterai yang paling umum digunakan pada perangkat ponsel saat ini. Tujuan utama dari program ini adalah untuk menentukan durasi pengisian agar baterai dapat mencapai tegangan tertentu. Sebagai contoh, dari 0 volt hingga 4.0 volt, dengan batas maksimum tegangan 4.2 volt, serta konstanta pengisian yang telah ditentukan.

Metode Secant dipilih karena keunggulannya dalam menyelesaikan persamaan nonlinear tanpa memerlukan turunan fungsi secara eksplisit. Program ditulis dalam bahasa pemrograman C, dan dijalankan melalui terminal. Seluruh parameter simulasi, termasuk dua nilai tebakan awal untuk waktu pengisian, telah ditentukan langsung di dalam program. Program akan menampilkan proses iterasi hingga ditemukan waktu yang memenuhi kriteria toleransi error.