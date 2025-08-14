#include <iostream>
#include <string>
using namespace std;

void XVI(){
    std::string asciiArt = R"(
    ____    U _____ u   ____           __     __           ____     _____  U _____ u               
U |  _"\ u \| ___"|/U /"___|    ___   \ \   /"/u  ___    / __"| u |_ " _| \| ___"|/               
 \| |_) |/  |  _|"  \| | u     |_"_|   \ \ / //  |_"_|  <\___ \/    | |    |  _|"                 
  |  _ <    | |___   | |/__     | |    /\ V /_,-. | |    u___) |   /| |\   | |___                 
  |_| \_\   |_____|   \____|  U/| |\u U  \_/-(_/U/| |\u  |____/>> u |_|U   |_____|                
  //   \\_  <<   >>  _// \\.-,_|___|_,-.//   .-,_|___|_,-.)(  (__)_// \\_  <<   >>                
 (__)  (__)(__) (__)(__)(__)\_)-' '-(_/(__)   \_)-' '-(_/(__)    (__) (__)(__) (__)               
   _   _   _   _       _                                                                          
U |"|u| | | \ |"|  U  /"\  u                                                                      
 \| |\| |<|  \| |>  \/ _ \/                                                                       
  | |_| |U| |\  |u  / ___ \                                                                       
 <<\___/  |_| \_|  /_/   \_\                                                                      
(__) )(   ||   \\,-.\\    >>                                                                      
    (__)  (_")  (_/(__)  (__)                                                                     
              _   _  __     __            _____      _        ____            U  ___ u  _   _     
     ___     | \ |"| \ \   /"/u  ___     |_ " _| U  /"\  u U /"___|    ___     \/"_ \/ | \ |"|    
    |_"_|   <|  \| |> \ \ / //  |_"_|      | |    \/ _ \/  \| | u     |_"_|    | | | |<|  \| |>   
     | |    U| |\  |u /\ V /_,-. | |      /| |\   / ___ \   | |/__     | | .-,_| |_| |U| |\  |u   
   U/| |\u   |_| \_| U  \_/-(_/U/| |\u   u |_|U  /_/   \_\   \____|  U/| |\u\_)-\___/  |_| \_|    
.-,_|___|_,-.||   \\,-.//   .-,_|___|_,-._// \\_  \\    >>  _// \\.-,_|___|_,-.  \\    ||   \\,-. 
 \_)-' '-(_/ (_")  (_/(__)   \_)-' '-(_/(__) (__)(__)  (__)(__)(__)\_)-' '-(_/  (__)   (_")  (_/ 
)";

    std::cout << asciiArt << std::endl;
}

void XVII(string Invitado, string Evento, string Fecha, string Hora, string Lugar){
    cout<<"[Invitado]: "<<Invitado<<endl;
    cout<<"[Evento]: "<<Invitado<<endl;
    cout<<"[Fecha]: "<<Invitado<<endl;
    cout<<"[Hora]: "<<Invitado<<endl;
    cout<<"[Lugar]: "<<Invitado<<endl;

}
void XVIII(){
    cout<<"[+]        DESEAS ASISTIR AL EVENTO          [+]"<<endl;
    cout<<"[+]           SI(Y)        NO(N)             [+]"<<endl;
}
void XVIV(char Asistencia){
    if (Asistencia == 'n' || Asistencia == 'N')
    {
        std::string asciiArt = R"(
        
  ___ _  ___   _____ _____ _   ___ ___ ___  _  _     
 |_ _| \| \ \ / /_ _|_   _/_\ / __|_ _/ _ \| \| |    
  | || .` |\ V / | |  | |/ _ \ (__ | | (_) | .` |    
 |___|_|\_|_\_/ |___|_|_/_/_\_\___|___\___/|_|\_|  __
 | _ \ __/ __| || | /_\  |_  / /_\ |   \ /_\   \ \/ /
 |   / _| (__| __ |/ _ \  / / / _ \| |) / _ \   >  < 
 |_|_\___\___|_||_/_/ \_\/___/_/ \_\___/_/ \_\ /_/\_\
        )";
        std::cout<<asciiArt<<std::endl;
    }else if(Asistencia == 'y' || Asistencia ==  'Y'){
        std::string asciiArt = R"(
  ___ _  ___   _____ _____ _   ___ ___ ___  _  _ 
 |_ _| \| \ \ / /_ _|_   _/_\ / __|_ _/ _ \| \| |
  | || .` |\ V / | |  | |/ _ \ (__ | | (_) | .` |
 |___|_|\_| \_/ |___|_|_/_/ \_\___|___\___/|_|\_|
   /_\ / __| __| _ \_   _/_\ |   \ /_\           
  / _ \ (__| _||  _/ | |/ _ \| |) / _ \          
 /_/ \_\___|___|_|   |_/_/ \_\___/_/ \_\         
                                                 )";
        std::cout<<asciiArt<<std::endl;
    }else{
        cout<<"[-]ERROR!"<<endl;
        XVIII();
    }
    
}

int main(int argc, char const *argv[])
{
    string a = "Nombre";
    string b = "Template";
    string c = "1 de Enero de 2025";
    string d = "01:00 PM";
    string e = "Template";
    char f;


    XVI();
    XVII(a,b,c,d,e);
    XVIII();
    cin>>f;
    system("cls");
    XVIV(f);

    return 0;
}
