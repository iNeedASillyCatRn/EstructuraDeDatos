#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char const *argv[])
{

    string Passkey[2] = {"Si","si"};
    string NotPass[2] = {"No","no"};
    cout<<"Aceptas los terminos?"<<endl<<"Si/No"<<endl;
    string a;
    cin>>a;
    if (a == Passkey[1] || a == Passkey[2])
    {
        
    }else if(a== NotPass[1] || a== NotPass[2]){
        cout<<"NOT ACEPTED CLOSING";
        return 0;
    }
    

}
