#include <iostream> 
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <map>
#include <unordered_set>
#include <matplot/matplot.h>
#include <set>

void gen_data(std::string fname, int n, int mx) {
    std::ofstream fout;
    fout.open(fname);

    fout << n << std::endl;
    for (int i = 0; i < n; i++) fout << rand() % mx << " ";
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
        unique.reserve(200001);
        int idx_unique = n;
        for (int i = n - 1; 0 <= i; i -= 1) {
            if (unique.find(data[i]) != unique.end()) {
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

int main() {
    using namespace matplot;
    std::string all_data_path = "I:/OOP Kirl/prokudenko_k_i/prj.lab/Graphics/text.md";
    gen_data("I:/OOP Kirl/prokudenko_k_i/prj.lab/Graphics/text.md", 10, 1000);
    std::pair<double, double> pairt;
    pairt = time_test("I:/OOP Kirl/prokudenko_k_i/prj.lab/Graphics/text.md", read_1, calc_1);
    std::cout << pairt.first << " " << pairt.second;

    //std::map<int, std::vector<double>> plot_n;
    std::map<int, std::vector<double>> plot1;
    std::map<int, std::vector<double>> plot2;

    for (int n = 1; n < 100; n += 1) {
        std::cout << n << std::endl;
        /*for (int m = 100; m <= 1000000; m *=10) {*/
        int m = 1000000;
            gen_data(all_data_path, n, m);

            std::pair<double, double> time1 = time_test(all_data_path, read_1, calc_1);
            std::pair<double, double> time2 = time_test(all_data_path, read_2, calc_2);

             std::cout << n << " " << m << std::endl;

            plot1[m].push_back(time1.first / n);
            plot2[m].push_back(time2.second / n);
            //plot_n[m].push_back(n);

            std::cout << time1.first << " " << time1.second << std::endl;
            std::cout << time2.first << " " << time2.second << std::endl;

        //}
    }

    std::string path = "C:/Users/swag_/Desktop/prokudenko_k_i.md";
    std::ofstream fon_md;
    fon_md.open(path);

    fon_md << "# **Прокуденко Кирилл БПМ-21-3** \n" << "## Анализ 2 программ \n";
    fon_md << "# Прокуденко Кирилл БПМ-21-3 \n";
    fon_md << "  Из графиков видно, что вторая программа работает медленней на малых количествах чисел. Но на большом числе данных эта разница становится почти незаметной, но 2 код всё ещё медленней.";

    fon_md.close();


    std::vector<std::vector<double>> v {plot1[1000000], plot2[1000000]};
    plot(v);
    /*save("img/v.jpg");*/
    show();
    
    fon_md.close();

    return 0;
}