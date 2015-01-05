#include <cstdlib>
#include <iostream>
#include <ctime>

#define p system("pause");

#pragma argsused

using namespace std;

//argv[1...bflast] = maps
//argv[last] = mapname

void EchoArgvS(int what, char * args[])
{
     int i=2;
     cout<<args[1];
     while (i<=what)
     {
           cout<<" "<<args[i++];
     }
}
int main(int argc, char *argv[])
{
    int i=argc-2;
    char buffer[80];
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    char* format = "%Y.%m.%d_%H.%M.%S";
    strftime(buffer, 80, format, timeinfo);

    cout<<"set name="<<argv[argc-1]<<endl<<"set datetime="<<buffer<<endl;
    cout<<"MD \"";
    EchoArgvS(i,argv);
    cout<<argv[argc-1]<<"\\"<<buffer<<"\\\""<<endl;
    
    
    
    cout<<"copy \""; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\temp\\"<<argv[argc-1]<<".bsp\" \"";
    cout; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\"<<buffer<<"\\\""<<endl;
    
    cout<<"copy \""; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\temp\\"<<argv[argc-1]<<".res\" \"";
    cout; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\"<<buffer<<"\\\""<<endl;
    
    cout<<"copy \""; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\temp\\"<<argv[argc-1]<<".log\" \"";
    cout; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\"<<buffer<<"\\\""<<endl;
    
    cout<<"copy \""; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\temp\\"<<argv[argc-1]<<".err\" \"";
    cout; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\"<<buffer<<"\\\""<<endl;
    
    cout<<"copy \""; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\temp\\"<<argv[argc-1]<<".ent\" \"";
    cout; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\"<<buffer<<"\\\""<<endl;
    
    cout<<"copy \""; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\temp\\"<<argv[argc-1]<<".lin\" \"";
    cout; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\"<<buffer<<"\\\""<<endl;    
    
    cout<<"copy \""; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\temp\\"<<argv[argc-1]<<".pts\" \"";
    cout; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\"<<buffer<<"\\\""<<endl;    
    
    cout<<"copy \""; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\temp\\ripin.bat\" \"";
    cout; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\"<<buffer<<"\\\""<<endl;
    
    cout<<"copy \""; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\temp\\ripout.bat\" \"";
    cout; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\"<<buffer<<"\\\""<<endl;
    
    cout<<"copy \""; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\temp\\ripent.exe\" \"";
    cout; EchoArgvS(i,argv);cout<<argv[argc-1]<<"\\"<<buffer<<"\\\""<<endl; 

    return EXIT_SUCCESS;
}
