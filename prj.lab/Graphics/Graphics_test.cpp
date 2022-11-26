#include <iostream> 
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <map>
#include <unordered_set>
#include <matplot/matplot.h>
#include <set>
#include <clocale>

void gen_data(std::string fname, int n) {
    std::ofstream fout;
    fout.open(fname);
    fout << n << std::endl;
    for (int i = 0; i < n; i++) fout << rand() % n<< " ";
    fout.close();
}

void read_1(int& n, std::vector<int>& data, std::ifstream& fin) {
    fin >> n;
    for (int i = 0; i < n; i+=1) {
        fin >> data[i];
    }
}
void calc_1(int& n, std::vector<int>& data) {
    std::vector<int> as(200001, -1);
    for (int i = 0; i < n; i+=1) {
        int idx = data[i];
        as[idx] = n - i - 1;
    }
    int ans = std::distance(as.begin(), std::max_element(as.begin(), as.end()));
}
void read_2(int& n, std::vector<int>& data, std::ifstream& fin) {
    fin >> n;
    for (int i = 0; i < n; i += 1) {
        fin >> data[i];
    }
}
void calc_2(int& n, std::vector<int>& data) {
    std::unordered_set<int> unique;
    unique.reserve(200000);
    int idx_unique = n;
    for (int i = n - 1; 0 <= i; i -= 1) {
        if (!unique.contains(data[i])) {
            idx_unique = data[i];
            unique.insert(idx_unique);
        }
    }
}

std::pair<double, double> time_test(
    const std::string fname,
    void (*read)(int& n, std::vector<int>& data, std::ifstream& fin), 
    void (*calc)(int& n, std::vector<int>& data)) {
        
    std::ifstream fin;
    fin.open(fname);

    int n = 0;
    std::vector<int> data(200001);

    auto start_r = std::chrono::steady_clock::now();
        read(n, data, fin);
        fin.close();
    auto end_r = std::chrono::steady_clock::now();
    std::chrono::duration<double> read_time = end_r - start_r;

    auto start_c = std::chrono::steady_clock::now();
        calc(n, data);
    auto end_c = std::chrono::steady_clock::now();
    std::chrono::duration<double> calc_time = end_c - start_c;

    std::pair<double, double> pair;
    pair.first = read_time.count();
    pair.second = calc_time.count();
    return pair;
}

std::vector<int> N {16, 160, 1600, 3200, 6400, 12800, 16000,
19200, 22400, 25600, 28800, 32000, 35200, 38400, 41600, 44800, 48000,
51200, 54400, 57600, 60800, 64000, 67200, 70400, 73600, 76800, 80000,
83200, 86400, 89600, 92800, 96000, 99200, 102400, 105600, 108800, 112000,
115200, 118400, 121600, 124800, 128000, 131200, 134400, 137600, 140800,
144000, 147200, 150400, 153600, 156800, 160000, 163200, 166400, 169600,
172800, 176000, 179200, 182400, 185600, 188800, 192000, 195200, 198400};
//std::vector<int> N{ 16 };

int main() {
    using namespace matplot;
    setlocale(LC_CTYPE, "rus");
    
    std::string gen_data_path = "gen_files/gen_data.txt";
  
    std::vector<double> calc1;
    std::vector<double> calc2;
    std::vector<double> read1;
    std::vector<double> read2;

    for (int n : N) {

        gen_data(gen_data_path, n);

        std::ifstream fin1;
        fin1.open("data1.txt");

        std::ifstream fin2;
        fin2.open("data1.txt");

        std::ios_base::sync_with_stdio(0);
        fin1.tie(nullptr);

        std::ios_base::sync_with_stdio(0);
        fin2.tie(nullptr);

        std::vector<int> input1(200001, -1);
        std::vector<int> input2(200001, -1);

        std::pair<double, double> time1 = time_test(gen_data_path, read_1, calc_1);
        std::pair<double, double> time2 = time_test(gen_data_path, read_2, calc_2);

        //std::cout << n << std::endl;

        fin1.close();
        fin2.close();

        read1.push_back(time1.first);
        read2.push_back(time2.first);
        calc1.push_back(time1.second);
        calc2.push_back(time2.second);
    }

    std::vector<double> x = linspace(16, 200000, 64);

    plot(x, calc1, x, calc2);
    xlabel("n");
    ylabel("t_{обработки}");
    save("gen_files/img/plot_calc.png");

    plot(x, read1, x, read2);
    xlabel("n");
    ylabel("t_{чтения}");
    save("gen_files/img/plot_read.png");


    std::string path = "gen_files/current_try.tex";

    std::ofstream fon_tex;
    fon_tex.open(path);

    fon_tex << "\\documentclass[12pt]{article}" << "\n";
    fon_tex << "\\usepackage[utf8x]{inputenc}" << "\n";
    fon_tex << "\\usepackage[english,russian]{babel}" << "\n";
    fon_tex << "\\usepackage{cmap}" << "\n"; 
    fon_tex << "\\usepackage[T2A]{ fontenc }" << "\n";
    fon_tex << "\\usepackage{graphicx}" << "\n";
    fon_tex << "\\usepackage{grffile}" << "\n";
    fon_tex << "\\graphicspath{{img/}}" << "\n";
    fon_tex << "\\title{Отчёт}" << "\n";
    fon_tex << "\\author{Прокуденко Кирилл БПМ-21-3}" << "\n";
    fon_tex << "\\begin{document}" << "\n";
    fon_tex << "\\maketitle" << "\n";
    fon_tex << "\\textbf{Github:} \\href{https://github.com/kirill737/prokudenko\\_k\\_i}" << "\n";
    fon_tex << "\\section{Логика программы}" << "\n";
    fon_tex << "Программа генерирует 2 графика, t чтения от n и t обработки от n. Значения n берутся из вектора N с изначальными тестовыми данными." << "\n";
    fon_tex << "\\section{Анализ графиков} " << "\n";
    fon_tex << "Синий график - первый код, оранжевый - второй код. " << "\n";
    fon_tex << "\\begin{center}" << "\n";
    fon_tex << "\\includegraphics[width=300pt]{plot_read.png} " << "\n";
    fon_tex << "\\end{center}" << "\n";
    fon_tex << "Из графика выше видно, что время чтения программ совпадает. Это соответствует логике, т.к. код считывания в программах идентичный." << "\n";
    fon_tex << "\\begin{center}" << "\n";
    fon_tex << "\\includegraphics[width=300pt]{plot_calc.png}" << "\n";
    fon_tex << "\\end{center}" << "\n";
    fon_tex << "Из графика считывания данных видно, что время обрабатывания данных первой программы растёт, но медленно. В то время как вторая программа тратит больше времени и растёт быстрее." << "\n";
    fon_tex << "\\section{Итог} " << "\n";
    fon_tex << "Как видно из замеров, первая программа работает гараздо быстрее чем вторая." << "\n";
    fon_tex << "\\end{document}" << "\n";


    fon_tex.close();

    std::cout << "the end" << std::endl;
    return 0;
}
