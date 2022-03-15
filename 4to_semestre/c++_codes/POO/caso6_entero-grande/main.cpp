#include "IntGrande.h"

int main()
{
    IntGrande n1(7654321);
    IntGrande n2(7891234);
    IntGrande n3("999999999999999999999");
    IntGrande n4("1");
    IntGrande n5;

    cout<<"\nn1 es "<<n1;
    cout<<"\nn2 es "<<n2;
    cout<<"\nn3 es "<<n3;
    cout<<"\nn4 es "<<n4;
    cout<<"\nn5 es "<<n5;

    n5 = n1 + n2;

    cout<<"\n\n"<<n1<<" + "<<n2<<" = "<<n5;

    cout<<"\n\n"<<n3<<" + "<<n4<<" = "<<(n3 + n4);

    n5 = n1 + 9;

    cout<<"\n\n"<<n1<<" + "<<9<<" = "<<n5;

    n5 = n2 + "10000";

    cout<<"\n\n"<<n2<<" + "<<"10000"<<" = "<<n5<<"\n\n";

    return 0;
}
