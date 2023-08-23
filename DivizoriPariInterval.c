#include <stdio.h>

int main()
{
    unsigned a, b, n, nrmin, nrmax;
    unsigned short nrdp, d, maxnrdp = 0;

    scanf("%u %u", &a, &b);

    n = a;

    do {
        nrdp = n % 2 == 0 ? 1 : 0;

        for (d = 2; d*d < n; d++)
            if (n % d == 0) {
                if (d % 2 == 0) nrdp++;
                if (n/d % 2 == 0) nrdp++;
            }

        if (d*d == n && d % 2 == 0) nrdp++;

        if (nrdp > maxnrdp) {
            maxnrdp = nrdp;
            nrmin = n;
            nrmax = n;
        } else if (nrdp == maxnrdp) {
            if (n < nrmin) nrmin = n;
            if (n > nrmax) nrmax = n;
        }

    //  printf("n = %u, nrdp = %hu, maxnrdp = %hu, nrmin = %u, nrmax = %u\n", n, nrdp, maxnrdp, nrmin, nrmax);

        n = n % 2 == 0 ? n + 2 : n + 1;

    } while (n <= b);

    if (maxnrdp == 0) {
        nrmin = a;
        nrmax = b;
    }

    printf("%hu %u %u", maxnrdp, nrmin, nrmax);

    return 0;
}
// scor 100/100
