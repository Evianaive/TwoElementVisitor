
#include "BaseClass.h"
#include "DerivedB.h"
#include "DerivedC.h"
#include "DerivedD.h"

int main(int argc, char* argv[])
{
    BaseClass* BB = new DerivedB;
    BaseClass* DD = new DerivedD;
    BaseClass* CC = new DerivedC;
    BB->Accept(DD);
    CC->Accept(DD);
    DD->Accept(BB);

    return 0;
}
