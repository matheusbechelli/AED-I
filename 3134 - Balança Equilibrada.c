#include <stdio.h>
 
int main() {
    double m1, m2, m3, m4;
    double soma1,soma2;
    scanf("%lf", &m1);
    scanf("%lf", &m2);
    scanf("%lf", &m3);
    scanf("%lf", &m4);

    double epsilon = 0.000001;
    
    if(fabs((m1+m2) - (m3+m4)) < epsilon){
        printf("YES\n");
    }
    else if(fabs((m1+m3) - (m2+m4)) < epsilon){
        printf("YES\n");
    }
    else if(fabs((m1+m4) - (m2+m3)) < epsilon){
        printf("YES\n");
    }
    else if(fabs((m1)- (m2+m3+m4)) < epsilon){
        printf("YES\n");
    }
    else if(fabs((m2)- (m1+m3+m4)) < epsilon){
        printf("YES\n");
    }
    else if(fabs((m3)- (m2+m1+m4)) < epsilon){
        printf("YES\n");
    }
    else if(fabs((m4)- (m2+m3+m1)) < epsilon){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

    return 0;
}
