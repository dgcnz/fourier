#ifndef __FFT_H__
#define __FFT_H__

#include "utility/types.h"
#include <vector>

// Util
bool is_prime(int num);
std::vector<cn> convolute(const std::vector<cn>& f, const std::vector<cn>& g);

// Out-of-place
std::vector<cn> ct_out_fft1d(const std::vector<cn>& a, bool inverse);
std::vector<cn> dj_out_fft1d(const std::vector<cn>& a, bool inverse);
std::vector<std::vector<cn>> dj_out_fft2d(
    const std::vector<std::vector<cn>>& matrix, bool inverse);

// In-place
void ct_in_fft1d(std::vector<cn>& a, bool inverse);
void ct_in_fft2d(std::vector<std::vector<cn>>& matrix, bool inverse);
void rad_in_fft1d(std::vector<cn>& vec, bool inverse);
void win_in_fft1d(std::vector<cn>& vec, bool inverse);
void blu_in_fft1d(std::vector<cn>& vec, bool inverse);

// Shift
void shift_fft2d(std::vector<std::vector<cn>>& matrix);

#endif
