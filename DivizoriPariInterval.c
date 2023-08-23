#include <stdio.h>

int main()
{
    unsigned a, b, n, i, nrmin, nrmax;
    unsigned short d, p, nrdp, maxnrdp = 0; 

    scanf("%u %u", &a, &b);

    for (i = a; i <= b; i++) {
        n = i, nrdp = 0, d = 2;
        while (d*d <= n) {
            p = 0;
            while (n % d == 0 ) {
                n /= d;
                p++;
            }

            if (p != 0)
                nrdp = (d % 2 == 0) ? (nrdp + p) : (nrdp + 1); 

            d++;
        }

        if (n != 1) {
            if (n % 2 == 0 || nrdp > 0) 
                nrdp++;

            if (i % 2 == 0 && i != n)
                nrdp++;
        }

        if (maxnrdp < nrdp) {
            maxnrdp = nrdp;
            nrmin = i;
            nrmax = i;
        } else if (maxnrdp == nrdp) {
            if (i < nrmin) nrmin = i;
            if (i > nrmax) nrmax = i;
        }
    }

    printf("%hu %u %u", maxnrdp, nrmin, nrmax);
            
    return 0;
}
// scor 20/100
