/*
 * Copyright (c) 2020, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "effect.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*(a)))

static const int8_t effect_0[] = {
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 
    4, 4, 4, 5, 5, 5, 6, 6, 7, 8, 8, 9, 10, 11, 12, 13, 
    14, 15, 16, 17, 19, 20, 22, 24, 26, 28, 30, 33, 
    36, 39, 42, 45, 49, 53, 57, 62, 67, 73, 79, 85, 
    92, 100, 107, 113, 118, 122, 125, 127, 127, 127, 
    127, 125, 123, 120, 116, 112, 107, 101, 96, 89, 83, 
    76, 69, 61, 54, 46, 38, 30, 22, 15, 7, 0, -8, -16, 
    -23, -31, -38, -44, -51, -58, -64, -70, -77, -82, 
    -87, -90, -92, -93, -93, -91, -88, -85, -80, -74, 
    -68, -61, -53, -44, -35, -26, -16, -6, 4, 15, 25, 
    36, 46, 56, 65, 74, 83, 91, 98, 105, 110, 115, 119, 
    121, 123, 123, 122, 120, 116, 111, 104, 96, 89, 82, 
    75, 68, 61, 54, 48, 41, 34, 27, 20, 14, 7, 0, -6, 
    -13, -19, -26, -32, -38, -44, -49, -54, -59, -64, 
    -68, -72, -75, -78, -81, -83, -84, -84, -84, -84, 
    -82, -80, -77, -74, -69, -64, -59, -54, -50, -46, 
    -42, -39, -36, -33, -30, -28, -25, -23, -22, -20, 
    -18, -17, -15, -14, -13, -12, -11, -10, -9, -9, -8, -7, 
    -7, -6, -6, -5, -5, -5, -4, -4, -4, -3, -3, -3, -3, -3, 
    -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

static const int8_t effect_1[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
    2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5, 6, 6, 7, 8, 
    8, 9, 10, 11, 11, 12, 13, 15, 16, 17, 18, 19, 19, 19, 
    19, 19, 19, 18, 18, 17, 16, 14, 13, 12, 10, 8, 6, 4, 
    2, 0, -3, -5, -8, -11, -14, -17, -20, -23, -27, -30, 
    -34, -38, -42, -46, -51, -55, -60, -66, -71, -77, 
    -83, -88, -91, -93, -94, -93, -92, -89, -85, -81, 
    -75, -68, -61, -53, -44, -35, -25, -15, -5, 6, 16, 
    27, 38, 48, 58, 68, 77, 86, 94, 102, 108, 114, 119, 
    123, 126, 127, 127, 127, 124, 120, 115, 108, 101, 
    94, 87, 80, 73, 66, 59, 52, 46, 39, 32, 26, 19, 
    13, 7, 0, -6, -12, -18, -23, -28, -34, -38, -43, 
    -47, -50, -53, -56, -58, -60, -60, -61, -60, -59, 
    -56, -53, -49, -44, -38, -31, -23, -14, -5, 2, 10, 
    16, 22, 28, 33, 37, 41, 44, 48, 50, 53, 55, 56, 
    58, 59, 60, 61, 61, 61, 62, 61, 61, 61, 60, 60, 59, 
    58, 57, 56, 55, 54, 53, 51, 50, 49, 47, 46, 44, 
    43, 41, 40, 38, 37, 35, 34, 32, 31, 30, 28, 27, 25, 
    24, 23, 21, 20, 19, 18, 17, 15, 14, 13, 12, 11, 10, 9, 
    8, 7, 7, 6, 5, 4, 4, 3, 2, 2, 1, 0, 0, 0, 0, 0, -2, 
    -2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -5, 
    -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, 
    -6, -6, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, 
    -5,
};

static const int8_t effect_2[] = {
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 
    4, 4, 4, 5, 5, 5, 6, 6, 7, 8, 8, 9, 10, 11, 12, 13, 
    14, 15, 16, 17, 19, 20, 22, 24, 26, 28, 30, 33, 
    36, 39, 42, 45, 49, 53, 57, 62, 67, 73, 79, 85, 
    92, 100, 107, 113, 118, 122, 125, 127, 127, 127, 
    127, 125, 123, 120, 116, 112, 107, 101, 96, 89, 83, 
    76, 69, 61, 54, 46, 38, 30, 22, 15, 7, 0, -8, -16, 
    -23, -31, -38, -44, -51, -58, -64, -70, -77, -82, 
    -87, -90, -92, -93, -93, -91, -88, -85, -80, -74, 
    -68, -61, -53, -44, -35, -26, -16, -6, 4, 15, 25, 
    36, 46, 56, 65, 74, 83, 91, 98, 105, 110, 115, 119, 
    121, 123, 123, 122, 120, 116, 111, 104, 96, 89, 82, 
    75, 68, 61, 54, 48, 41, 34, 27, 20, 14, 7, 0, -6, 
    -13, -19, -26, -32, -38, -44, -49, -54, -59, -64, 
    -68, -72, -75, -78, -81, -83, -84, -84, -84, -84, 
    -82, -80, -77, -74, -69, -64, -59, -54, -50, -46, 
    -42, -39, -36, -33, -30, -28, -25, -23, -22, -20, 
    -18, -17, -15, -14, -13, -12, -11, -10, -9, -9, -8, -7, 
    -7, -6, -6, -5, -5, -5, -4, -4, -4, -3, -3, -3, -3, -3, 
    -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

static const int8_t effect_3[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 
    1, 2, 2, 2, 3, 3, 4, 4, 5, 6, 7, 8, 9, 10, 12, 14, 16, 
    18, 20, 23, 27, 30, 35, 40, 45, 52, 59, 67, 75, 82, 
    88, 93, 97, 100, 102, 104, 106, 106, 107, 106, 106, 
    105, 104, 102, 101, 98, 96, 94, 91, 88, 86, 83, 79, 
    76, 73, 69, 66, 62, 59, 55, 51, 47, 44, 40, 36, 31, 
    27, 23, 18, 13, 8, 3, -4, -10, -17, -24, -32, -41, -51, 
    -62, -73, -83, -91, -97, -102, -106, -109, -110, -111, 
    -111, -109, -108, -105, -102, -98, -94, -89, -84, -79, 
    -73, -67, -60, -54, -47, -40, -33, -26, -18, -11, -4, 
    4, 11, 18, 25, 32, 38, 45, 51, 57, 63, 69, 74, 79, 84, 
    89, 94, 98, 102, 106, 110, 114, 117, 121, 124, 126, 127, 
    127, 127, 126, 124, 122, 119, 115, 111, 106, 101, 95, 89, 
    83, 76, 69, 62, 55, 47, 39, 31, 23, 15, 7, -2, -10, -18, 
    -26, -33, -41, -48, -55, -62, -68, -74, -79, -84, -89, 
    -93, -96, -99, -101, -103, -103, -103, -102, -100, -98, 
    -94, -88, -83, -78, -73, -68, -63, -59, -54, -49, -45, 
    -40, -35, -30, -25, -20, -14, -9, -3, 3, 9, 15, 20, 26, 
    32, 38, 44, 50, 55, 61, 66, 72, 77, 82, 87, 91, 95, 99, 
    103, 106, 108, 110, 112, 113, 113, 113, 111, 109, 106, 
    102, 97, 90, 82, 73,
};

static const int8_t effect_4[] = {
    0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 4, 
    4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 10, 11, 12, 13, 14, 15, 16, 
    18, 19, 21, 23, 24, 27, 29, 31, 34, 36, 39, 43, 46, 50, 
    54, 59, 64, 69, 74, 81, 87, 94, 101, 107, 112, 117, 120, 
    123, 125, 127, 127, 127, 127, 126, 125, 123, 120, 118, 
    114, 111, 107, 103, 99, 94, 89, 84, 79, 74, 68, 63, 57, 
    51, 46, 40, 34, 29, 23, 17, 12, 6, 1, -5, -10, -16, -21, 
    -27, -32, -38, -43, -49, -53, -56, -58, -60, -61, -60, 
    -59, -58, -55, -52, -49, -45, -40, -35, -29, -23, -17, 
    -11, -4, 3, 10, 17, 24, 31, 38, 45, 52, 58, 64, 70, 75, 
    80, 85, 89, 92, 94, 96, 97, 98, 97, 96, 94, 91, 86, 81, 
    75, 68, 61, 55, 49, 43, 37, 32, 26, 21, 15, 10, 5, 0, -6, 
    -11, -15, -20, -25, -30, -34, -39, -43, -48, -52, -56, 
    -60, -63, -67, -70, -73, -75, -78, -80, -81, -83, -84, 
    -84, -84, -84, -83, -82, -81, -78, -75, -72, -68, -63, 
    -58, -54, -49, -46, -42, -39, -36, -33, -30, -28, -26, 
    -24, -22, -20, -19, -17, -16, -15, -14, -13, -12, -11, 
    -10, -9, -9, -8, -7, -7, -7, -6, -6, -5, -5, -5, -4, -4, 
    -4, -4, -4, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2, 
    -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

static const int8_t effect_5[] = {
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 
    4, 4, 4, 5, 5, 5, 6, 6, 7, 8, 8, 9, 10, 11, 12, 13, 
    14, 15, 16, 17, 19, 20, 22, 24, 26, 28, 30, 33, 
    36, 39, 42, 45, 49, 53, 57, 62, 67, 73, 79, 85, 
    92, 100, 107, 113, 118, 122, 125, 127, 127, 127, 
    127, 125, 123, 120, 116, 112, 107, 101, 96, 89, 83, 
    76, 69, 61, 54, 46, 38, 30, 22, 15, 7, 0, -8, -16, 
    -23, -31, -38, -44, -51, -58, -64, -70, -77, -82, 
    -87, -90, -92, -93, -93, -91, -88, -85, -80, -74, 
    -68, -61, -53, -44, -35, -26, -16, -6, 4, 15, 25, 
    36, 46, 56, 65, 74, 83, 91, 98, 105, 110, 115, 119, 
    121, 123, 123, 122, 120, 116, 111, 104, 96, 89, 82, 
    75, 68, 61, 54, 48, 41, 34, 27, 20, 14, 7, 0, -6, 
    -13, -19, -26, -32, -38, -44, -49, -54, -59, -64, 
    -68, -72, -75, -78, -81, -83, -84, -84, -84, -84, 
    -82, -80, -77, -74, -69, -64, -59, -54, -50, -46, 
    -42, -39, -36, -33, -30, -28, -25, -23, -22, -20, 
    -18, -17, -15, -14, -13, -12, -11, -10, -9, -9, -8, -7, 
    -7, -6, -6, -5, -5, -5, -4, -4, -4, -3, -3, -3, -3, -3, 
    -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

static const struct effect_stream effects[] = {
    {
        .effect_id = 0,
        .data = effect_0,
        .length = ARRAY_SIZE(effect_0),
        .play_rate_hz = 24000,
    },

    {
        .effect_id = 1,
        .data = effect_1,
        .length = ARRAY_SIZE(effect_1),
        .play_rate_hz = 24000,
    },
    
    {
        .effect_id = 2,
        .data = effect_2,
        .length = ARRAY_SIZE(effect_2),
        .play_rate_hz = 24000,
    },
    
    {
        .effect_id = 3,
        .data = effect_3,
        .length = ARRAY_SIZE(effect_3),
        .play_rate_hz = 24000,
    },
    
    {
        .effect_id = 4,
        .data = effect_4,
        .length = ARRAY_SIZE(effect_4),
        .play_rate_hz = 24000,
    },
    
    {
        .effect_id = 5,
        .data = effect_5,
        .length = ARRAY_SIZE(effect_5),
        .play_rate_hz = 24000,
    },
};

const struct effect_stream *get_effect_stream(uint32_t effect_id)
{
    int i;

    for (i = 0; i < ARRAY_SIZE(effects); i++) {
        if (effect_id == effects[i].effect_id)
            return &effects[i];
    }

    return NULL;
}
