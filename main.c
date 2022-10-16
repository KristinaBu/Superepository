#include <stdio.h>
#include <math.h>
int N=0;

double uravn(double kor,int koef){
    return (kor-koef*cos(kor));
} // изначальное уравнение

double funct_ot_x1(double t,int koef){ // функция для нового икс
    return (t-uravn(t,koef));
}
double nomer1(double a,double eps, int koef) {
    int k=0; //счетчик итераций
    double xstar,xsled,t;
    xsled=a; //
    do{
        xstar=xsled; // смена икс
        t=funct_ot_x1(xstar,koef); //значение от функции для нового икс
        xsled=t;
        k=k+1; //
    } while (fabs(xsled-xstar)>eps); //условие для учета погрешности
    N=k;
    return xsled;
} //итерации

double funct_ot_x3(double t,int koef){ // функция для нового икс
    return t - (uravn(t,koef))/(1+koef*sin(t));
}
double nomer3(double b,double eps, int koef){
    int k=0; //счетчик итераций
    double xstar,xsled,t;
    xsled=b; //
    do{
        //printf("nnn\nx=%lf\nk=%d\nnnn\n",xsled,k);
        xstar=xsled; // смена икс
        t=funct_ot_x3(xstar,koef); //значение от функции для нового икс
        xsled=t;
        k=k+1; //
    } while (fabs(xsled-xstar)>eps); //условие для учета погрешности
    N=k;
    return xsled;
} // Ньютон

double nomer2(double a1, double a2,double eps, int koef){
    int k;
    double aser;
    do{
       aser=(a1+a2)/2;
       if (uravn(aser,koef)==0){
           return aser;
           break;
       }
       if (uravn(a1,koef)* uravn(aser,koef)<0){
           a2=aser;
       }else{
           a1=aser;
       }
        k=k+1;
    }while(fabs(a2-a1)>eps);
    N=k;
    return (a1+a2)/2;;
} // деление пополам

int main(){
    int n=0,koef=1;
    double a1=0,a2=43,eps=0.000001;
    printf("Уравнение: x - cos(x) = 0. Погрешность: 0.000001\n№ метода        x               N\n");
    printf("1               %.8lf      %d\n",nomer1(n,eps,koef),N);
    printf("1               %.8lf      %d\n",nomer2(a1,a2,eps,koef),N);
    printf("1               %.8lf      %d\n",nomer3(n,eps,koef),N);
    eps=0.00000001;
    printf("Уравнение: x - cos(x) = 0. Погрешность: 0.00000001\n№ метода        x               N\n");
    printf("1               %.8lf      %d\n",nomer1(n,eps,koef),N);
    printf("1               %.8lf      %d\n",nomer2(a1,a2,eps,koef),N);
    printf("1               %.8lf      %d\n",nomer3(n,eps,koef),N);
    koef=5;
    eps=0.000001;
    printf("Уравнение: x - k * cos(x) = 0, k = 5. Погрешность: 0.000001\n№ метода        x               N\n");
    printf("1               %.8lf      %d\n",nomer1(n,eps,koef),N);
    printf("1               %.8lf      %d\n",nomer2(a1,a2,eps,koef),N);
    printf("1               %.8lf      %d\n",nomer3(n,eps,koef),N);
    koef=10;
    printf("Уравнение: x - k  * cos(x) = 0, k = 10. Погрешность: 0.000001\n№ метода        x               N\n");
    printf("1               %.8lf      %d\n",nomer1(n,eps,koef),N);
    printf("1               %.8lf      %d\n",nomer2(a1,a2,eps,koef),N);
    printf("1               %.8lf      %d\n",nomer3(n,eps,koef),N);
    return 0;
}