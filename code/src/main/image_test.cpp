#include "utility/image_manager.h"
#include "utility/opencv_manager.h"
#include <chrono>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    auto img = read_img("lena_128.png");

    ImageTransform trans(img);

    trans.pad();
    trans.center();

    auto tmp = trans.get_matrix();
    auto filter = Filters::gaussian_low_pass(tmp.size(), tmp[0].size(), 5);

    auto start_time = chrono::system_clock::now();
    trans.transform(false);

    trans.apply(filter);

    trans.transform(true);
    auto end_time = chrono::system_clock::now();

    trans.center();
    trans.crop();

    auto res = trans.get_matrix();

    auto duration =
        chrono::duration_cast<chrono::milliseconds>(end_time - start_time);
    cout << "Exec time for filter application: " << duration.count() << "ms "
         << endl;
    auto im_res = display_img(res, 0);
    imwrite("res/image/output/lenag_out.png", im_res);

    return 0;
}
