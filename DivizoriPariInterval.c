#include <stdio.h>

int main()
{
    unsigned a, b, i, n, nrdp, d, maxnrdp = 0, nrmin = 999999999, nrmax = 1;

    scanf("%u %u", &a, &b);
    
    for (n = a; n <= b; n++) {
        nrdp = n % 2 == 0 ? 1 : 0;

        for (d = 2; d <= n/2; d++) {
            if (n % d == 0) {
                if (d % 2 == 0) {
                    nrdp++;
                }
            }
        }

        if (maxnrdp < nrdp) {
            maxnrdp = nrdp;
            nrmin = n;
            nrmax = n;
        } else if (maxnrdp == nrdp) {
            if (n < nrmin) nrmin = n;
            if (n > nrmax) nrmax = n;
        }
    }

    printf("%u %u %u", maxnrdp, nrmin, nrmax);

    return 0;
}
// scor 80/100
