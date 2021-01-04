#include <stdio.h>
#include <math.h>
int main()
{
    double a, b;
    double c, d;
    double r1, r2;
    double Rm, Rp;
    double distance;
    int result = 0;
    int T = 0;
    scanf("%d", &T);

    for (T; T > 0; T--)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &r1, &c, &d, &r2);
        distance = sqrt((a - c) * (a - c) + (b - d) * (b - d));
        Rm = r1 - r2;
        if (Rm < 0)
            Rm = -Rm;
        Rp = r1 + r2;

        if (distance != 0)
        {
            if ((Rp == distance) || (Rm == distance))
                result = 1;
            else if (Rm >distance)
                result = 0;
            else if (distance > Rp)
                result = 0;
            else result = 2;
         }
        else
        {
            if (Rm == 0)
                result = -1;
            if (Rm != 0)
                result = 0;
        }
        printf("%d\n",result);
    }
}