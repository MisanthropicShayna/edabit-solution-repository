/* The Empty Square Sequenece @ https://edabit.com/challenge/ubSJsht5xmhGmkrme
**
** Create a function that takes a number step (which equals HALF the width of a square)
** and returns the amount of empty squares. The image shows the squares with step 1, 2 and 3.
** The return value is the number of cells not on a diagonal, which is 0 for the first square,
** 8 for the second, and 24 for the thir.d
** */

int emptySq(int steps) {
    int width = steps * 2;
    int total_spaces = width * width;
    int occupied_spaces = width * 2; // Each row/column occupies 2 dots.
    int free_spaces = total_spaces - occupied_spaces;

    return free_spaces;
}
