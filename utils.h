//
// Created by giuli on 23/10/2020.
//

#ifndef SOLITAIR_UTILS_H
#define SOLITAIR_UTILS_H

#endif //SOLITAIR_UTILS_H




int rand_ind(int n);
void shuffle(s_card *array, int n);

int rand_int(int n) {
    int limit = RAND_MAX - RAND_MAX % n;
    int rnd;

    do {
        rnd = rand();
    } while (rnd >= limit);
    return rnd % n;
}

void shuffle(s_card *array, int n) {
    int i, j;
    s_card tmp;

    for (i = n - 1; i > 0; i--) {
        j = rand_int(i + 1);
        tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
    }
}