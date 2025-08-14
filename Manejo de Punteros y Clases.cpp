#include <iostream>
using namespace std;

class XVI{
public:
    void printMessage(){
        cout<<"Test class"<<endl;
    }
};

void ProsPointer(XVI*ptr){
    if (ptr != nullptr)
    {

        
        ptr->printMessage();
    }else {
        cout<<"Puntero es nulo"<<endl;
    }
    
}


int main(int argc, char const *argv[])
{
    XVI* validPtr = new XVI();
    XVI* nullPtr = nullptr;

    ProsPointer(validPtr);
    ProsPointer(nullPtr);

    delete validPtr;

    return 0;
}
